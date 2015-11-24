#include "formularzhasel.h"
#include "ui_formularzhasel.h"

FormularzHasel::FormularzHasel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormularzHasel)
{
    ui->setupUi(this);
    QList<QAbstractButton *> lista = ui->buttonBox->buttons();
    lista.at(0)->setText("Zapisz jako");

    lista.at(1)->setText("Wyjdź");
}

FormularzHasel::~FormularzHasel()
{
    delete ui;
}

void FormularzHasel::on_buttonBox_accepted()
{
    qDebug()<<"[FormularzHasel::on_buttonBox_accepted()]";
    tymczasowa.baza.slowa.clear();
    tymczasowa.baza.podpowiedzi.clear();
    for (int i=0;i<(ui->tablicaSlow->rowCount());i++)
    {

        tymczasowa.baza.slowa << ui->tablicaSlow->item(i,0)->text();
        qDebug() <<"Wpisuje do bazy haseł: " << tymczasowa.baza.slowa.at(i);

        if (ui->tablicaSlow->item(i,1)!=0)
        {
            tymczasowa.baza.podpowiedzi << ui->tablicaSlow->item(i,1)->text();
            qDebug() <<"Wpisuje do bazy podpowiedzi: " << tymczasowa.baza.podpowiedzi.at(i);
        }
        else
        {
            tymczasowa.baza.podpowiedzi << "";
            qDebug() <<"Wpisuje pustą podpowiedź";
        }
    }
    qDebug() << "zapisywanie rozpoczynam";
    tymczasowa.sciezka = QFileDialog::getSaveFileName(
                this, //ten plik
                tr("Zapisz plik"), //tytuł okna
                QString(), //ścieżka do pliku (opcjonalna w tym momencie funkcja generująca NULL)
                "Plik Tekstowy(*.txt);Wszystkie(*.*)"); //to czego szukamy w formularzu
    tymczasowa.tekst="";
    tymczasowa.tekst=tymczasowa.baza_na_tekst();
    qDebug() << "Wczytany tekst: " << tymczasowa.tekst;
    tymczasowa.zapis_do_pliku();
    qDebug() << "zapisywanie END";
    qDebug()<<"FormularzHasel::on_buttonBox_accepted()->>END";
}
void FormularzHasel::zaczytajFormularz()
{
    qDebug()<<"[void FormularzHasel::zaczytajFormularz()]";
    qDebug()<<"tymczasowa.baza.slowa po exec"<< tymczasowa.baza.slowa;


    for(int j=0;j<ui->tablicaSlow->rowCount();j++)
    {
        ui->tablicaSlow->removeRow(j);
    }
    qDebug()<<"Liczba kolumn wynosi: "<<ui->tablicaSlow->columnCount()<<" liczba wierszy: "<<ui->tablicaSlow->rowCount();

    int i;
    for (i=0;i<tymczasowa.baza.slowa.length();i++)
    {
        qDebug()<<"Tworze wiersz nr: "<< i;
        ui->tablicaSlow->insertRow(i);
        qDebug()<<"Ustawiam slowo nr: "<< i<<": "<<tymczasowa.baza.slowa.at(i);
        QTableWidgetItem *newItemSlowo = new QTableWidgetItem(tymczasowa.baza.slowa.at(i));
        ui->tablicaSlow->setItem(i,0,newItemSlowo);
        qDebug()<<"Ustawiam podpowiedz nr: "<< i<<": "<<tymczasowa.baza.podpowiedzi.at(i);
        QTableWidgetItem *newItemPodpowiedz = new QTableWidgetItem(tymczasowa.baza.podpowiedzi.at(i));
        ui->tablicaSlow->setItem(i,1,newItemPodpowiedz);
    }
    ui->tablicaSlow->insertRow(0);
    ui->tablicaSlow->removeRow(i+1);

    qDebug()<<"[void FormularzHasel::zaczytajFormularz()---END]";

}

void FormularzHasel::on_pushButtonNowyWiersz_released()
{
    ui->tablicaSlow->insertRow(0);
}
