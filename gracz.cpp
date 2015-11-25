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
bool Gracz::czy_samogloska(QChar temp)
{
    bool czy = false;
    QChar lista[]={'a','e','i','o','ó','u','y'};
    for(int i=0;i<7;i++)
    {
        if(lista[i]==temp)
        {
            czy=true;
        }
    }
    return czy;
}
int Gracz::jakaCena(int pozycja)
{
    int cena;
    if (pozycja==0)
    {
        qDebug()<<"POZYCJA BANKRUT BŁĄD";
    }
    if (pozycja==1)
    {
        cena=400;
    }
    else if (pozycja==2)
    {
        cena=2500;
    }
    else if (pozycja==3)
    {
        cena=250;
    }
    else if (pozycja==4)
    {
        qDebug()<<"POZYCJA STOP BŁĄD";
    }
    else if (pozycja==5)
    {
        cena=400;
    }
    else if (pozycja==6)
    {
        cena=200;
    }
    else if (pozycja==7)
    {
        cena=100;
    }
    else if (pozycja==8)
    {
        qDebug()<<"POZYCJA STOP BŁĄD";
    }
    else if (pozycja==9)
    {
        cena=150;
    }
    else if (pozycja==10)
    {
        cena=250;
    }
    else if (pozycja==11)
    {
        cena=300;
    }
    else
    {
        qDebug()<<"Błąd pozycja niee jest w predziale 0-11";
        return -1;
    }
    return cena;
}

bool Gracz::moze_kupic(int pozycja)
{
    qDebug()<<"[bool Gracz::moze_kupic(int pozycja)]";
    int cena;
    cena=jakaCena(pozycja);
    if (punkty<cena)
        return false;
    return true;
    qDebug()<<"[bool Gracz::moze_kupic(int pozycja)]---END";
}
void Gracz::kup_samogloske(int pozycja)
{
    int cena;
    cena=jakaCena(pozycja);
    punkty=punkty-cena;
    if (punkty<0)
    {
        qDebug()<<"Błąd: Punkty są mniejsze od 0?";
        punkty=-1;
    }
    else
        return;
}
void Gracz::niezgadl(int pozycja)
{
    qDebug()<<"[void Gracz::niezgadl(int pozycja)]";
    int cena;
    cena=jakaCena(pozycja);
    punkty=punkty-cena;
    if (punkty<0)
    {
        punkty=0;
    }
    qDebug()<<"[void Gracz::niezgadl(int pozycja)]---END";
}
