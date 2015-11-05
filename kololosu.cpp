#include "kololosu.h"

KoloLosu::KoloLosu()
    :
    wylosowanaPozycja(-1),
    iloscPozycji(12),
    tura(0)
{
    qDebug()<<"KoloLosu::KoloLosu()";
    nagrody << "Bankrut" << "400" << "2500" << "250" << "STOP" << "400" << "200" << "100" << "STOP" << "150" << "250" <<"300";
    nazwaTury << "Początek BETA narazie zakręć kołem" << "Zakręć kołem" << "Wybierz Literę lub zgaduj";
    listaGraczy = new Gracz;
    aktualnyZawodnik = listaGraczy;
    qDebug()<<"KoloLosu::KoloLosu()--END";
}
KoloLosu::~KoloLosu()
{
    delete listaGraczy;
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
bool KoloLosu::czyTraciKolejke()
{
    if(wylosowanaPozycja==-1)
    {
        qDebug()<<"Kolo na pozycji startowej realizacja wygranej nie udana!";
        return true;
    }
    if (wylosowanaPozycja==0)
    {
        aktualnyZawodnik->ustawPunkty(bankrut());
        return true;
    }
    if (wylosowanaPozycja==4)
    {
        aktualnyZawodnik->ustawPunkty(stop(aktualnyZawodnik->pobierzPunkty()));
        return true;
    }

    if (wylosowanaPozycja==8)
    {
        aktualnyZawodnik->ustawPunkty(stop(aktualnyZawodnik->pobierzPunkty()));
        return true;
    }
    return false;
}

void KoloLosu::realizacjaWygranej(int liczbaWystapien)
{
    qDebug()<<"[void KoloLosu::realizacjaWygranej()]";


    if (wylosowanaPozycja==1)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),400*liczbaWystapien));
        return;
    }
    if (wylosowanaPozycja==2)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),2500*liczbaWystapien));
        return;
    }

    if (wylosowanaPozycja==3)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),250*liczbaWystapien));
        return;
    }



    if (wylosowanaPozycja==5)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),400*liczbaWystapien));
        return;
    }

    if (wylosowanaPozycja==6)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),200*liczbaWystapien));
        return;
    }

    if (wylosowanaPozycja==7)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),100*liczbaWystapien));
        return;
    }



    if (wylosowanaPozycja==9)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),150*liczbaWystapien));
        return;
    }
    if (wylosowanaPozycja==10)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),250*liczbaWystapien));
        return;
    }

    if (wylosowanaPozycja==11)
    {
        aktualnyZawodnik->ustawPunkty(wygrajPunkty(aktualnyZawodnik->pobierzPunkty(),300*liczbaWystapien));
        return;
    }



    qDebug()<<"[void KoloLosu::realizacjaWygranej()---END]";
}
