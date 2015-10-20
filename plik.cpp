
#include "plik.h"



QString Plik::zapis_do_pliku()
{
    qDebug() << "[Plik::zapis_do_pliku()]";
    QFile plik(sciezka);
    tekst="";

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
