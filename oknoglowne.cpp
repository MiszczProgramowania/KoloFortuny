#include "oknoglowne.h"
#include "ui_oknoglowne.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <Qtime>
#include "formularzhasel.h"

OknoGlowne::OknoGlowne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OknoGlowne)
{
    ui->setupUi(this);
    if(ui->TablicaLiter->isSortingEnabled())
        ui->TablicaLiter->setSortingEnabled(false);
}

OknoGlowne::~OknoGlowne()
{
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


void OknoGlowne::on_actionNowa_triggered()
{
    qDebug() << "[OknoGlowne::on_actionNowa_triggered()]";
    //zaciagnij sciezke hasel
    plik_hasel.sciezka=plik_conf.wgraj_sciezke_do_hasel();
    plik_hasel.tekst_na_baze();
    if (plik_hasel.tekst.isEmpty())
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

    OknoGlowne::zakrycie_hasla(plik_hasel.baza.slowa.at(plik_hasel.nrPartii));
    QString podpowiedz="Podpowiedź: "+plik_hasel.baza.podpowiedzi.at(plik_hasel.nrPartii);
    OknoGlowne::inicjalizacja_podpowiedzi(podpowiedz);
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

void OknoGlowne::on_wybierzLitere_released()
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
    szukajLiter(plik_hasel.baza.slowa.at(plik_hasel.nrPartii),szukana);
    ui->wybranaLitera->clear();
}
void OknoGlowne::szukajLiter(QString temp,QChar szukana)
{
    qDebug()<<"[void OknoGlowne::szukajLiter(QString temp,QChar szukana)]";
    int ile_wierszy=temp.length()/ui->TablicaLiter->columnCount();
    if (temp.length()%ui->TablicaLiter->columnCount())
        ile_wierszy++;

    for (int j=0,licznik=0;j < ile_wierszy;j++)
    {
        for (int i=0;i < ui->TablicaLiter->columnCount()&&licznik<temp.length();i++)
        {
            if (szukana==temp.at(licznik))
            {
                ui->TablicaLiter->setItem(j,i,new QTableWidgetItem(temp.at(licznik)));
            }
            licznik++;
        }
    }
    qDebug()<<"[void OknoGlowne::szukajLiter(QString temp,QChar szukana)----END]";
}
