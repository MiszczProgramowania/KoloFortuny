#include "gracz.h"

Gracz::Gracz()
{

    punkty=0;
    wygral=false;


    if (nazwa.isEmpty()||nazwa.isNull())
       nazwa="Anonim";
}
void Gracz::ustawNazwe(QString n)
{
    if (n.isNull()||n.isEmpty())
        nazwa = "Anonim";
    nazwa=n;
}

void Gracz::ustawPunkty(int p)
{
    if (p<0)
        punkty = 0;
    punkty = p;
}
void Gracz::ustawWygral(bool w)
{
    wygral=w;
}
QString Gracz::pobierzNazwe()
{
    QString n = nazwa;
    return n;
}

int Gracz::pobierzPunkty()
{
    return punkty;
}

bool Gracz::sprawdzCzyWygral()
{
    return wygral;
}

