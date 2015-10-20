#include "bazahasel.h"

BazaHasel::BazaHasel()
{

}

QStringList BazaHasel::przetworz_na_baze_hasel(QString t)
{
    qDebug() << "[BazaHasel::przetworz_na_baze_hasel(QString t)]";
    QString szukana = "\n";

    return t.split(szukana);
}

QStringList BazaHasel::tekst_na_baze()
{
    qDebug() << "[BazaHasel::tekst_na_baze()]";
    QStringList temp = przetworz_na_baze_hasel(tekst);
    for (int i = 0; i < temp.size();++i)
    {
        qDebug() << temp.at(i);
    }

    return temp;
}

QString BazaHasel::baza_na_tekst()
{
    qDebug() << "[BazaHasel::baza_na_tekst()]";
    QString temp = baza.join("\n");

    return temp;
}
