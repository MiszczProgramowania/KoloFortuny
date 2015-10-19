#include "oknoglowne.h"
#include "ui_oknoglowne.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

void OknoGlowne::on_actionWczytaj_triggered()
{
    plik_hasel.sciezka = QFileDialog::getOpenFileName(
                this, //ten plik
                tr("Otwórz plik"), //tytuł okna
                QString(), //ścieżka do pliku (opcjonalna w tym momencie funkcja generująca NULL)
                "Plik Tekstowy(*.txt);;Wszystkie(*.*)"); //to czego szukamy w formularzu

    QString tekst = plik_hasel.odczyt_z_pliku();

    if (tekst==NULL)
    {
//                QMessageBox::warning(
//                            this,
//                            tr("Błąd"),
//                            "Wystąpił błąd w dostępie do pliku"
//                            );
       qDebug() << "Plik pusty lub otwarcie nie udane!!";
    }
    else
    {
        QString informacja = "Hasła zaczytane z pliku o ścieżce: \n";
        informacja.append(plik_hasel.sciezka);
        QMessageBox::information(
                    this,
                    tr("Hasła zaczytane"),
                    informacja
                    );
    }
}
