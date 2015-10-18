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
QString OknoGlowne::zapis_do_pliku(QString sciezka)
{
    QFile plik(sciezka);
    QString tekst=NULL;

    if(!plik.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Nie można było otworzyć pliku o zapisu\n";
        return tekst;
    }

    QTextStream out (&plik);
    out << tekst;

    qDebug() << "Wczytano Następujące Dane z Pliku:\n";
    qDebug() << tekst << "\n";

    plik.flush();
    plik.close();

    return tekst;
}
QString OknoGlowne::odczyt_z_pliku(QString sciezka)
{
    QFile plik(sciezka);
    QString tekst=NULL;

    if(!plik.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Nie można było otworzyc pliku do odczytu\n";
        return tekst;
    }

    QTextStream in (&plik);
    tekst = in.readAll();

    qDebug() << "Wczytano Następujące Dane z Pliku:\n";
    qDebug() << tekst << "\n";

    plik.flush();
    plik.close();

    return tekst;
}
void OknoGlowne::on_actionWczytaj_triggered()
{
    sciezka_do_pliku = QFileDialog::getOpenFileName(
                this, //ten plik
                tr("Otwórz plik"), //tytuł okna
                QString(), //ścieżka do pliku (opcjonalna)
                "Plik Tekstowy(*.txt);;Wszystkie(*.*)"); //to czego szukamy w formularzu

    QString tekst = OknoGlowne::odczyt_z_pliku(sciezka_do_pliku);

    if (tekst==NULL)
    {
        QMessageBox::warning(
                    this,
                    tr("Błąd"),
                    "Wystąpił błąd w dostępie do pliku"
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
