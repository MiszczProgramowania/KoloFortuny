#include "oknoglowne.h"
#include "ui_oknoglowne.h"
#include <QFileDialog>
#include <QMessageBox>

OknoGlowne::OknoGlowne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OknoGlowne)
{
    ui->setupUi(this);
}

OknoGlowne::~OknoGlowne()
{
    delete ui;
}
OknoGlowne::zapis_do_pliku(QString sciezka)
{

}

void OknoGlowne::on_actionWczytaj_triggered()
{
    sciezka_do_pliku = QFileDialog::getOpenFileName(
                this, //ten plik
                tr("Otwórz plik"), //tytuł okna
                QString(), //ścieżka do pliku (opcjonalna)
                "Plik Tekstowy(*.txt);;Wszystkie(*.*)"); //to czego szukamy w formularzu
    if (sciezka_do_pliku=="")
    {
        QMessageBox::warning(
                    this,
                    tr("Błąd"),
                    "Wystąpił błąd w dostępie do ścieżki pliku (on_actionWczytaj_triggered())"
                    );
    }
    else
    {
        QString informacja = "Hasła zaczytane z pliku o ścieżce: \n";
        informacja.append(sciezka_do_pliku);
        QMessageBox::information(
                    this,
                    tr("Hasła zaczytane"),
                    informacja
                    );
    }
}
