#include "konfiguracja.h"

Konfiguracja::Konfiguracja()
{
    sciezka= "konfiguracja.dat";
    tekst_na_konfiguracje();
}
QString Konfiguracja::wycinanie_parametru(QString szukana)
{
    qDebug() << "[Konfiguracja::wycinanie_parametru(QString szukana)]";
    QString temp = tekst;
    int temp_start,temp_end;
    szukana=szukana+"=";
    temp_start= tekst.lastIndexOf(szukana)+szukana.length();
    qDebug() << "Temp_START >> " << temp_start;

    temp.remove(0,temp_start);
    qDebug() << temp;


    temp_end = temp.indexOf("\n");
    temp.truncate(temp_end);
    qDebug() << "Oto wynik wycinania parametru konfiguracyjnego: " << temp;

    return temp;
}

void Konfiguracja::tekst_na_konfiguracje()
{
    qDebug()<<"[Konfiguracja::tekst_na_konfiguracje()]";
    odczyt_z_pliku();
    if (tekst.isEmpty())
    {
        qDebug() << "Tworze pusty plik konfiguracyjny";
        zapis_do_pliku();
        return;
    }
    //szukamy parametru sciezki do hasel
    QString szukana = "sciezka_do_hasel";

    sciezka_do_hasel = wycinanie_parametru(szukana);
    return;
}
QString Konfiguracja::wgraj_sciezke_do_hasel()
{
    return Konfiguracja::sciezka_do_hasel;
}

void Konfiguracja::konfiguracja_na_tekst()
{
    //konfiguracja_na_tekst
    QString a = "sciezka_do_hasel=";
    a.append(sciezka_do_hasel);
    a.append("\n");
    tekst = a;
    zapis_do_pliku();
}
void Konfiguracja::ustaw_sciezke_do_hasel(QString temp)
{
    sciezka_do_hasel = temp;
}
