
#include "plik.h"



void Plik::zapis_do_pliku()
{
    qDebug() << "[Plik::zapis_do_pliku()]";
    QFile plik(sciezka);
    if(!plik.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Nie można było otworzyć pliku o zapisu\n";
        return;
    }

    QTextStream out (&plik);
    out << tekst;

    qDebug() << "Wczytano Następujące Dane z Pliku:\n";
    qDebug() << tekst << "\n";

    plik.flush();
    plik.close();

    return;
}
QString Plik::odczyt_z_pliku()
{
    qDebug() << "[Plik::odczyt_z_pliku()]";
    QFile plik(sciezka);
    tekst="";

    if(!plik.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Nie można było otworzyc pliku do odczytu\n";

//        QMessageBox::warning(
//                    this,
//                    QObject::tr("Hello World"),
//                    "Wystąpił błąd w dostępie do pliku"
//                    );
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
QString Plik::wycinanie_szukanego_tekstu(QString szukana)
{
    qDebug() << "[Plik::przeszukiwanie(QString szukana)]";

    int temp_start;
    szukana=szukana+"=";
    temp_start= tekst.lastIndexOf(szukana);
    qDebug() << "Tniemy!!";
    QString temp = tekst.mid(temp_start,szukana.length());
    qDebug() << temp;
    return temp;
}
