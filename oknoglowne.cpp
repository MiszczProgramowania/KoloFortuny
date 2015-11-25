#include "oknoglowne.h"
#include "ui_oknoglowne.h"


OknoGlowne::OknoGlowne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OknoGlowne)
{
    kolo=NULL;
    ui->setupUi(this);
    if(ui->TablicaLiter->isSortingEnabled())
        ui->TablicaLiter->setSortingEnabled(false);
    ui->wybierzLitere->setAutoDefault(true);

    ui->labelGrafika->setPixmap(QPixmap(":/img/kolo"));
}

OknoGlowne::~OknoGlowne()
{
    delete kolo;
    delete ui;
}

void OknoGlowne::on_actionWczytaj_triggered()
{
    qDebug() << "[OknoGlowne::on_actionWczytaj_triggered()]";
    plik_hasel.sciezka = QFileDialog::getOpenFileName(
                this, //ten plik
                tr("Otwórz plik"), //tytuł okna
                QString(), //ścieżka do pliku (opcjonalna w tym momencie funkcja generująca NULL)
                "Plik Tekstowy(*.txt);;Wszystkie(*.*)"); //to czego szukamy w formularzu

    plik_conf.ustaw_sciezke_do_hasel(plik_hasel.sciezka);
    plik_conf.konfiguracja_na_tekst();

}
void OknoGlowne::najpierwZaczytajBaze()
{
    QMessageBox msgBox;
    msgBox.setText("Najpierw zaczytaj baze haseł lub utwórz nową!");
    msgBox.setInformativeText("Czy chcesz kontynuować?");
    msgBox.setStandardButtons(QMessageBox::Save |QMessageBox::Open| QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.button(QMessageBox::Open)->setText("Utwórz");
    msgBox.button(QMessageBox::Save)->setText("Wczytaj");
    msgBox.button(QMessageBox::Cancel)->setText("Anuluj");
    int ret = msgBox.exec();
    qDebug() << "Zwrócono: " << ret;
    if(ret==2048)
    {
         on_actionWczytaj_triggered();
         return;
    }
     else if(ret==8192)
     {
        on_actionUtw_rz_triggered();
        return;
     }
    else if(ret==4194304)
    {
         return;
    }
    else
    {
         qDebug()<<"Nie zwrócono nic sensownego!";
    }
}
void OknoGlowne::czyszczenieElementowUi()
{
    ui->TablicaLiter->clear();
    ui->lineEditZgadnij->clear();
    ui->wybranaLitera->clear();
    ui->labelPunkty->clear();
    ui->labelNazwaGracza->clear();
}
void OknoGlowne::aktualizacjaElementowUi()
{
    ui->lineEditZgadnij->clear();
    ui->wybranaLitera->clear();
    QString temp;
    temp = temp.number(kolo->aktualnyZawodnik->pobierzPunkty());
    ui->labelPunkty->setText(temp);
    ui->labelNazwaGracza->setText(kolo->aktualnyZawodnik->pobierzNazwe());
    ui->labelTura->setText("Tura numer: "+intToStr(kolo->tura)+" o nazwie: "+ kolo->nazwaTury.at(kolo->tura));
    ui->labelPodpowiedz->setText("Podpowiedź: "+ plik_hasel.baza.podpowiedzi.at(plik_hasel.nrPartii));
}

void OknoGlowne::on_actionNowa_triggered()
{
    qDebug() << "[OknoGlowne::on_actionNowa_triggered()]";
    //zaciagnij sciezke hasel
    czyszczenieElementowUi();
    plik_hasel.sciezka=plik_conf.wgraj_sciezke_do_hasel();
    plik_hasel.tekst_na_baze();
    if (plik_hasel.tekst.isEmpty())
    {
       najpierwZaczytajBaze();
       return;
    }
    QString informacja = "Hasła zaczytane z pliku o ścieżce: \n";
    informacja.append(plik_hasel.sciezka);
    QMessageBox::information(
                this,
                tr("Hasła zaczytane"),
                informacja
                );


    ui->TablicaLiter->clear();
    ui->TablicaLiter->setRowCount(0);

    if(plik_hasel.baza.slowa.isEmpty())
    {
        qDebug() << "Brak haseł";
        QMessageBox::warning(
                    this,
                    tr("Błąd"),
                    "Błąd odczytu albo zaczytałeś pusty plik!"
                    );
        return;
    }
    qDebug() << "Baza Istnieje";

    plik_hasel.nrPartii = losowanie_partii();

    zakrycie_hasla(plik_hasel.baza.slowa.at(plik_hasel.nrPartii));
    QString podpowiedz="Podpowiedź: "+ plik_hasel.baza.podpowiedzi.at(plik_hasel.nrPartii);
    inicjalizacja_podpowiedzi(podpowiedz);
    qDebug()<<"Pytamy o liczbę graczy";

    QMessageBox msgBox;
    msgBox.setText("Nowa Gra!");
    msgBox.setInformativeText("W ilu graczy?");
    msgBox.setStandardButtons(QMessageBox::Save |QMessageBox::Open| QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.button(QMessageBox::Save)->setText("Jeden");
    msgBox.button(QMessageBox::Open)->setText("Dwóch");
    msgBox.button(QMessageBox::Cancel)->setText("Czterch");

    int ret = msgBox.exec();
    qDebug() << "ret wynosi: " << ret;
    if(ret==2048)
    {
        qDebug()<<"Tworzymy KOLO";
        kolo = new KoloLosu(1);
        QString temp= QInputDialog::getText(this,"Nazwa użytkownika nr 1", "Gracz nr 1:");
        kolo->listaGraczy[0].ustawNazwe(temp);
        qDebug()<<"Tworzymy KOLO END";
        zmianaTury();
         return;
    }
    if (ret==8192)
     {
        qDebug()<<"Tworzymy KOLO";
        kolo = new KoloLosu(2);
        QString temp= QInputDialog::getText(this,"Nazwa użytkownika nr 1", "Gracz nr 1:");
        kolo->listaGraczy[0].ustawNazwe(temp);
        temp= QInputDialog::getText(this,"Nazwa użytkownika nr 2", "Gracz nr 2:");
        kolo->listaGraczy[1].ustawNazwe(temp);
        qDebug()<<"Tworzymy KOLO END";
        zmianaTury();
        return;
     }
    if(ret==4194304)
    {
        qDebug()<<"Tworzymy KOLO";
        kolo = new KoloLosu(4);
        QString temp= QInputDialog::getText(this,"Nazwa użytkownika nr 1", "Gracz nr 1:");
        kolo->listaGraczy[0].ustawNazwe(temp);
        temp= QInputDialog::getText(this,"Nazwa użytkownika nr 2", "Gracz nr 2:");
        kolo->listaGraczy[1].ustawNazwe(temp);
        temp= QInputDialog::getText(this,"Nazwa użytkownika nr 3", "Gracz nr 3:");
        kolo->listaGraczy[2].ustawNazwe(temp);
        temp= QInputDialog::getText(this,"Nazwa użytkownika nr 4", "Gracz nr 4:");
        kolo->listaGraczy[3].ustawNazwe(temp);
        qDebug()<<"Tworzymy KOLO END";
        zmianaTury();
         return;
    }
    else
    {
         qDebug()<<"Nie zwrócono nic sensownego!";
         return;
    }

}
int OknoGlowne::losowanie_partii()
{
    QTime czas;
    czas = czas.currentTime();
    int milisekunda=czas.msec();

    int los = milisekunda % plik_hasel.baza.slowa.count();
    qDebug() << "czas wynosi: "<< milisekunda << "Wylosowałeś hasło numer: " << los;
    return los;
}

void OknoGlowne::odkrycie_hasla(QString temp)
{
    qDebug() << "Rozmiar stringa: " << temp.length();
    int ile_wierszy=temp.length()/ui->TablicaLiter->columnCount(); // potencjalne zagrożenie dla wyjątków
    if (temp.length()%ui->TablicaLiter->columnCount())
        ile_wierszy++;
    qDebug() << "ile_wierszy: " << ile_wierszy;

    for (int j=0,licznik=0;j < ile_wierszy;j++)
    {
        ui->TablicaLiter->insertRow(j);
        for (int i=0;i < ui->TablicaLiter->columnCount()&&licznik<temp.length();i++)
        {

            ui->TablicaLiter->setItem(j,i,new QTableWidgetItem(temp.at(licznik)));
            //qDebug()<<i<<":"<<j<<" licznik wynosi: "<<licznik <<" litera to "<<temp.at(licznik);
            licznik++;
        }
    }
}
void OknoGlowne::zakrycie_hasla(QString temp)//DO ZROBIENIA
{
    qDebug() << "[void OknoGlowne::zakrycie_hasla(QString temp)]";
    qDebug() << "Rozmiar stringa: " << temp.length();

    int ile_wierszy=temp.length()/ui->TablicaLiter->columnCount(); // potencjalne zagrożenie dla wyjątków
    if (temp.length()%ui->TablicaLiter->columnCount())
        ile_wierszy++;
    qDebug() << "ile_wierszy: " << ile_wierszy;

    for (int j=0,licznik=0;j < ile_wierszy;j++)
    {
        ui->TablicaLiter->insertRow(j);
        for (int i=0;i < ui->TablicaLiter->columnCount()&&licznik<temp.length();i++)
        {
            if (temp.at(licznik)!=' ')
            {
                ui->TablicaLiter->setItem(j,i,new QTableWidgetItem(plik_hasel.znacznikNiewiadomej));
            }
            licznik++;
        }
    }
    qDebug() << "[void OknoGlowne::zakrycie_hasla(QString temp)----END]";
}

void OknoGlowne::inicjalizacja_podpowiedzi(QString temp)
{
    qDebug() << "[OknoGlowne::inicjalizacja_podpowiedzi(QString temp)]";
    ui->labelPodpowiedz->setText(temp);
    qDebug() << "[OknoGlowne::inicjalizacja_podpowiedzi(QString temp)-- END]";
}
void OknoGlowne::on_actionUtw_rz_triggered()
{
    FormularzHasel tworzenie_hasel;
    tworzenie_hasel.exec();
    plik_conf.ustaw_sciezke_do_hasel(tworzenie_hasel.tymczasowa.sciezka);
    plik_conf.konfiguracja_na_tekst();
}
void OknoGlowne::uwzglednijWygrana(int liczbaWystapien)
{
    kolo->realizacjaWygranej(liczbaWystapien);
    int liczba = kolo->aktualnyZawodnik->pobierzPunkty();
    QString lancuch = intToStr(liczba);
    ui->labelPunkty->setText(lancuch);
}
void OknoGlowne::zmianaGracza()
{
    qDebug()<<"[void KoloLosu::zmianaGracza()]";
    if(kolo->aktualnyZawodnikIndex==(kolo->liczbaGraczy-1))
        kolo->aktualnyZawodnikIndex=0;
    else
        kolo->aktualnyZawodnikIndex++;
    kolo->aktualnyZawodnik=&kolo->listaGraczy[kolo->aktualnyZawodnikIndex];
    zmianaTury();
    qDebug()<<"[void KoloLosu::zmianaGracza()--END]";
}
bool OknoGlowne::czyTraciKolejke()
{
    qDebug()<<"[bool KoloLosu::czyTraciKolejke()]";
    if(kolo->wylosowanaPozycja==-1)
    {
        qDebug()<<"Kolo na pozycji startowej";
        return true;
    }
    if (kolo->wylosowanaPozycja==0)
    {
        qDebug()<<"Aktualny gracz: "<< kolo->aktualnyZawodnik->pobierzNazwe() << " ZBANKRUTOWAŁ!";
        kolo->aktualnyZawodnik->ustawPunkty(0);
        zmianaGracza();
        return true;
    }
    if (kolo->wylosowanaPozycja==4)
    {
        qDebug()<<"Aktualny gracz: "<< kolo->aktualnyZawodnik->pobierzNazwe() << " stracił kolejke!";
        zmianaGracza();
        return true;
    }

    if (kolo->wylosowanaPozycja==8)
    {
        qDebug()<<"Aktualny gracz: "<< kolo->aktualnyZawodnik->pobierzNazwe() << " stracił kolejke!";
        zmianaGracza();
        return true;
    }
    return false;
    qDebug()<<"[bool KoloLosu::czyTraciKolejke()---END]";
}
void OknoGlowne::on_wybierzLitere_released()
{
    if (kolo->tura==2)
    {
        QString szukanaString = ui->wybranaLitera->text();
        if (szukanaString.isEmpty())
        {
            qDebug()<<"Wybrana litera jest pusta";
            QMessageBox::warning(
                        this,
                        tr("Błąd"),
                        "Wprowadź jakąś litere!"
                        );
            return;
        }
        QChar szukana=szukanaString.at(0);
        qDebug()<<"Szukamy znaku: "<<szukana;
        if(plik_hasel.nrPartii==-1)
        {
            qDebug()<<"Brak wczytanej bazy";
            QMessageBox::warning(
                        this,
                        tr("Błąd"),
                        "Brak wczytanej bazy.\n Najpiew zacznij NOWĄ GRĘ!"
                        );
            ui->wybranaLitera->clear();
            return;
        }

        if(kolo->aktualnyZawodnik->czy_samogloska(szukana))
        {
            if(kolo->aktualnyZawodnik->moze_kupic(kolo->wylosowanaPozycja))
            {
                kolo->aktualnyZawodnik->kup_samogloske(kolo->wylosowanaPozycja);
                aktualizacjaElementowUi();
            }
            else
            {
                QMessageBox::warning(
                            this,
                            tr("Brak środków"),
                            "Brak środków na kupno samogłoski!\nWybierz spółgłoskę"
                            );
                return;
            }
        }
        int liczbaWystapien = szukajLiter(plik_hasel.baza.slowa.at(plik_hasel.nrPartii),szukana);
        if (liczbaWystapien==0)
        {
            kolo->aktualnyZawodnik->niezgadl(kolo->wylosowanaPozycja);
            zmianaTury();
            zmianaGracza();
        }
        else if(liczbaWystapien>0)
            uwzglednijWygrana(liczbaWystapien);
        ui->wybranaLitera->clear();

        zmianaTury();
    }
    else
    {
        QMessageBox::warning(this, tr("Zła tura"),
                                       tr("Wykonałeś akcje nie przewidzianą w tej turze.\n"));
        qDebug()<<"Jest teraz inna tura o nazwie: "<<kolo->nazwaTury.at(kolo->tura);
        qDebug()<<"Najpierw ją ukończ";
    }
}
void OknoGlowne::zmianaTury()
{
    qDebug()<<"[void OknoGlowne::zmianaTury()]";
    kolo->tura=kolo->tura+1;
    if (kolo->tura >= kolo->nazwaTury.length())
        kolo->tura=1;
    aktualizacjaElementowUi();
    qDebug()<<"[void OknoGlowne::zmianaTury()--END]";
}

int OknoGlowne::szukajLiter(QString temp,QChar szukana)
{
    qDebug()<<"[void OknoGlowne::szukajLiter(QString temp,QChar szukana)]";
    int ile_wierszy=temp.length()/ui->TablicaLiter->columnCount();
    if (temp.length()%ui->TablicaLiter->columnCount())
        ile_wierszy++;
    temp=temp.toUpper();
    szukana=szukana.toUpper();
    int liczbaWystapien=0;
    for (int j=0,licznik=0;j < ile_wierszy;j++)
    {
        for (int i=0;i < ui->TablicaLiter->columnCount()&&licznik<temp.length();i++)
        {
            if (szukana==temp.at(licznik))
            {
                if (ui->TablicaLiter->item(j,i)->text()=="*")
                {
                    ui->TablicaLiter->setItem(j,i,new QTableWidgetItem(temp.at(licznik)));
                    liczbaWystapien++;
                }
            }
            licznik++;
        }
    }
    return liczbaWystapien;
    qDebug()<<"[void OknoGlowne::szukajLiter(QString temp,QChar szukana)----END]";
}

void OknoGlowne::on_wybranaLitera_returnPressed()
{
    OknoGlowne::on_wybierzLitere_released();
}
void OknoGlowne::najpierwUruchomGre()
{
    qDebug()<<"[void OknoGlowne::najpierwUruchomGre()]";
    QMessageBox msgBox;
    msgBox.setText("Najpierw uruchom gre!");
    msgBox.setInformativeText("Czy chcesz kontynuować?");
    msgBox.setStandardButtons(QMessageBox::Open| QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Open);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.button(QMessageBox::Open)->setText("Nowa");
    msgBox.button(QMessageBox::Cancel)->setText("Anuluj");
    int ret = msgBox.exec();
    qDebug() << "Zwrócono: " << ret;
    if(ret==8192)
     {
        on_actionNowa_triggered();
        return;
     }
    else if(ret==4194304)
    {
         return;
    }
    else
    {
         qDebug()<<"Nie zwrócono nic sensownego!";
    }
    qDebug()<<"[void OknoGlowne::najpierwUruchomGre()---END]";
}
QString OknoGlowne::intToStr(int n)
{
     QString tmp, ret;
     if(n < 0) {
      ret = "-";
      n = -n;
     }
     do {
      tmp += n % 10 + 48;
      n -= n % 10;
     }
     while(n /= 10);
     for(int i = tmp.length()-1; i >= 0; i--)
      ret += tmp.at(i);
     return ret;
}
void OknoGlowne::on_buttonLosuj_released()
{

    qDebug()<<"[void OknoGlowne::on_buttonLosuj_released()]";
    if (kolo==NULL)
    {
        najpierwUruchomGre();
        return;
    }
    if (kolo->tura==1)
    {
    kolo->losowaniePozycji();
    OknoGlowne::obrotGrafiki(30*kolo->wylosowanaPozycja+15);
    ui->labelWylosowano->setText("Wylosowano na kole: " + kolo->nagrody.at(kolo->wylosowanaPozycja));
    czyTraciKolejke();
    zmianaTury();
    }
    else
    {
        QMessageBox::warning(this, tr("Zła tura"),
                                       tr("Wykonałeś akcje nie przewidzianą w tej turze.\n"
                                          "Wykonaj polecenie zapisane w nagłówku programu"));
        qDebug()<<"Jest teraz inna tura o nazwie: "<<kolo->nazwaTury.at(kolo->tura);
        qDebug()<<"Najpierw ją ukończ";
    }
    qDebug()<<"[void OknoGlowne::on_buttonLosuj_released()----NULL]";
}

void OknoGlowne::on_lineEditZgadnij_returnPressed()
{
    QString temp = plik_hasel.baza.slowa.at(plik_hasel.nrPartii);
    qDebug()<<"Hasło do zgadnięcia to: "<<temp;
    QString strzal=ui->lineEditZgadnij->text();
    if (strzal.isNull()||strzal.isEmpty())
    {
        ui->lineEditZgadnij->clear();
        return;
    }
    temp=temp.toUpper();
    strzal=strzal.toUpper();
    if (temp!=strzal)
    {
        kolo->aktualnyZawodnik->ustawPunkty(0);
        ui->labelPunkty->setText(0);
        QMessageBox::information(
            this,tr("ZŁY STRZAŁ!"),tr("Tym razem ci się nie udało kasujemy punkty!!"));
        ui->lineEditZgadnij->clear();
        return;
    }
    wygranaRozgrywka();
}
void OknoGlowne::wygranaRozgrywka()
{
    qDebug()<<"[void OknoGlowne::wygranaRozgrywka()]";

    QMessageBox::information(
        this,tr("WYGRAŁEŚ!"),tr("Wygrałeś gratulacje!!"));
    on_actionNowa_triggered();
    qDebug()<<"[void OknoGlowne::wygranaRozgrywka()---END]";
}
void OknoGlowne::obrotGrafiki(int wylosowanyObrot)
{
    int obrot=360;
    int licznik=10;
    bool wyjscie=false;
    while(licznik>0&&wyjscie==false)
    {
        if (licznik==1&&obrot==wylosowanyObrot)
        {
            //wychodzimy gdy osiagniemy wylosowany obort w ostatniej iteracji licznika
            wyjscie=true;
            break;
        }
        QApplication::processEvents(); //tworzymy nowy proces
        QPixmap ship(":/img/kolo"); //zaczytujemy obrazek
        QPixmap rotate(ship.size());//nierozumiem tego ale jest w poradnikach

        QPainter temp(&rotate);//nierozumiem tego ale jest w poradnikach

        temp.setRenderHint(QPainter::Antialiasing);
        temp.setRenderHint(QPainter::SmoothPixmapTransform);

        temp.translate(rotate.size().width()/2, rotate.size().height()/2);
        temp.rotate(obrot);
        temp.translate(-rotate.size().width()/2, -rotate.size().height()/2);

        temp.drawPixmap(0,0,ship);

        ui->labelGrafika->setPixmap(rotate);
        obrot=obrot-licznik;
        if (obrot<0)
        {
            obrot=360;
            licznik--;
        }
        temp.end();
    }

}

void OknoGlowne::on_actionEdytuj_triggered()
{
    plik_hasel.sciezka=plik_conf.wgraj_sciezke_do_hasel();
    plik_hasel.tekst_na_baze();
    if (plik_hasel.tekst.isEmpty())
    {
         on_actionWczytaj_triggered();
         plik_hasel.tekst_na_baze();
    }
    FormularzHasel tworzenie_hasel;
    tworzenie_hasel.tymczasowa.baza.slowa=plik_hasel.baza.slowa;
    qDebug()<<"tworzenie_hasel.tymczasowa.baza.slowa przed exec() wynosi "<<tworzenie_hasel.tymczasowa.baza.slowa;
    tworzenie_hasel.tymczasowa.baza.podpowiedzi=plik_hasel.baza.podpowiedzi;
    tworzenie_hasel.zaczytajFormularz();
    tworzenie_hasel.exec();

    plik_conf.ustaw_sciezke_do_hasel(tworzenie_hasel.tymczasowa.sciezka);
    plik_conf.konfiguracja_na_tekst();

}
