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

void FormularzHasel::on_tablicaSlow_cellChanged(int row, int column)
{
    qDebug() <<"[FormularzHasel::on_tablicaSlow_cellChanged(int row, int column)]";
    if (row==0&&column==0)
    {
        ui->tablicaSlow->insertRow(row);
    }
    qDebug() <<"[FormularzHasel::on_tablicaSlow_cellChanged(int row, int column)] -> END";
}

void FormularzHasel::on_buttonBox_accepted()
{
    qDebug()<<"FormularzHasel::on_buttonBox_accepted()->NIEUKOŃCZONO!";

    for (int i=1;i<(ui->tablicaSlow->rowCount());i++)
    {

        tymczasowa.baza << ui->tablicaSlow->item(i,0)->text();
        qDebug() <<"Wpisuje do bazy haseł: " << tymczasowa.baza.at(i-1);

        if (ui->tablicaSlow->item(i,1)!=0)
        {
            tymczasowa.podpowiedzi << ui->tablicaSlow->item(i,1)->text();
            qDebug() <<"Wpisuje do bazy podpowiedzi: " << tymczasowa.podpowiedzi.at(i-1);
        }
        else
        {
            tymczasowa.podpowiedzi << "";
            qDebug() <<"Wpisuje pustą podpowiedź";
        }
    }
    qDebug() << "zapisywanie rozpoczynam";
    qDebug() << "[OknoGlowne::on_actionWczytaj_triggered()]";
    tymczasowa.sciezka = QFileDialog::getSaveFileName(
                this, //ten plik
                tr("Zapisz plik"), //tytuł okna
                QString(), //ścieżka do pliku (opcjonalna w tym momencie funkcja generująca NULL)
                "Plik Tekstowy(*.txt);;Wszystkie(*.*)"); //to czego szukamy w formularzu
    qDebug() << "Wczytany baza test numeru 1: " << tymczasowa.baza.at(1);
    tymczasowa.tekst=tymczasowa.baza_na_tekst();
    qDebug() << "Wczytany tekst nr 1: " << tymczasowa.tekst;
    tymczasowa.zapis_do_pliku();
    qDebug() << "zapisywanie END";
    qDebug()<<"FormularzHasel::on_buttonBox_accepted()->NIEUKOŃCZONO!->END";
}
