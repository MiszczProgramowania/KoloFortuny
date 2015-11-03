#include "kololosu.h"

KoloLosu::KoloLosu()
    :
    wylosowanaPozycja(-1),
    iloscPozycji(12)
{

}
int KoloLosu::wygrajPunkty(int poprzedniePunkty, int wygranePunkty)
{
    return poprzedniePunkty + wygranePunkty;
}

int KoloLosu::bankrut()
{
    return 0;
}
int KoloLosu::stop(int poprzedniePunkty)
{
    return poprzedniePunkty;
}

void KoloLosu::losowaniePozycji()
{
    qDebug()<<"[void KoloLosu::losowaniePozycji()]";
    wylosowanaPozycja=qrand()%(iloscPozycji-1);
    if (wylosowanaPozycja<0)
        wylosowanaPozycja=wylosowanaPozycja*(-1);
    qDebug()<<"Wylosowana pozycja to: "<<wylosowanaPozycja;
    qDebug()<<"[void KoloLosu::losowaniePozycji()---END]";
}
void KoloLosu::realizacjaWygranej()
{
    qDebug()<<"[void KoloLosu::realizacjaWygranej()]";
    if(wylosowanaPozycja==-1)
    {
        qDebug()<<"Kolo na pozycji startowej realizacja wygranej nie udana!";
        return;
    }
    if (wylosowanaPozycja==0)
    {
        gracz1.ustawPunkty(bankrut());
        return;
    }
    if (wylosowanaPozycja==1)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),400));
        return;
    }
    if (wylosowanaPozycja==2)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),2500));
        return;
    }

    if (wylosowanaPozycja==3)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),250));
        return;
    }

    if (wylosowanaPozycja==4)
    {
        gracz1.ustawPunkty(stop(gracz1.pobierzPunkty()));
        return;
    }

    if (wylosowanaPozycja==5)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),400));
        return;
    }

    if (wylosowanaPozycja==6)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),200));
        return;
    }

    if (wylosowanaPozycja==7)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),100));
        return;
    }

    if (wylosowanaPozycja==8)
    {
        gracz1.ustawPunkty(stop(gracz1.pobierzPunkty()));
        return;
    }

    if (wylosowanaPozycja==9)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),150));
        return;
    }
    if (wylosowanaPozycja==10)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),250));
        return;
    }

    if (wylosowanaPozycja==11)
    {
        gracz1.ustawPunkty(wygrajPunkty(gracz1.pobierzPunkty(),300));
        return;
    }



    qDebug()<<"[void KoloLosu::realizacjaWygranej()---END]";
}
