#include "bazahasel.h"

BazaHasel::BazaHasel()
{
    separator=";";
    znacznikNiewiadomej="*";
    nrPartii=-1;
}

QStringList BazaHasel::przetworz_na_baze_hasel(QString t)
{
    qDebug() << "[BazaHasel::przetworz_na_baze_hasel(QString t)]";
    QString szukana = "\n";

    return t.split(szukana);
}

void BazaHasel::tekst_na_baze()
{
    qDebug() << "[BazaHasel::tekst_na_baze()]";

    odczyt_z_pliku();
    if (tekst.isEmpty())
        return;
    QStringList temp = przetworz_na_baze_hasel(tekst);
    for (int i = 0; i < temp.size();++i)
    {
        qDebug() << temp.at(i);
    }

    baza.slowa = temp;
    baza.podpowiedzi=temp;

    if (baza.slowa.isEmpty())
    {
        qDebug()<<"baza.slowa jest pusta!";
        return;
    }
    qDebug() << "Skracanie do słów START";

    for (int i=0;i<baza.slowa.length();i++)
    {
        int temp_end = baza.slowa.at(i).indexOf(separator);
        if (temp_end!=-1)
        {

            QString temp = baza.slowa.at(i);
            temp.truncate(temp_end);
            baza.slowa.replace(i,temp);
            qDebug() <<"baza slowa o indexie "<<i<<" wynosi: " << baza.slowa.at(i);
            temp = baza.podpowiedzi.at(i);
            if (!temp.isEmpty())
            {

                temp.remove(0,temp_end+1);
                baza.podpowiedzi.replace(i,temp);
                qDebug() <<"baza podpowiedz o indexie "<<i<<" wynosi: " << baza.podpowiedzi.at(i);
            }
            else
            {
                qDebug() << "Brak podpowiedzi";
            }
        }
    }

}

QString BazaHasel::baza_na_tekst()
{
    qDebug() << "[BazaHasel::baza_na_tekst()]";
    QStringList lista = baza.slowa;
    qDebug() << "Rozpoczynam łączenie";
    for (int i=0;i<lista.length();i++)
    {
        QString polaczenie = baza.slowa.at(i);
        polaczenie.insert(polaczenie.length(),separator);
        polaczenie.insert(polaczenie.length(),baza.podpowiedzi.at(i));
        lista.replace(i,polaczenie);
        qDebug() << "Połączony obiekt nr "<<i<<" = "<<lista.at(i);
    }
    qDebug() << "Kończe łączenie";
    QString temp = lista.join("\n");
    return temp;
}
