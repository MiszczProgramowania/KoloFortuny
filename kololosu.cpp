#include "kololosu.h"

KoloLosu::KoloLosu()
{
    qDebug()<<"[KoloLosu::KoloLosu()]";
    wylosowanaPozycja=-1;
    iloscPozycji=12;
    tura=0;
    nagrody << "Bankrut" << "400" << "2500" << "250" << "STOP" << "400" << "200" << "100" << "STOP" << "150" << "250" <<"300";
    nazwaTury << "Początek BETA narazie zakręć kołem" << "Zakręć kołem" << "Wybierz Literę lub zgaduj";
    qDebug()<<"[KoloLosu::KoloLosu()--END]";
}
int KoloLosu::losowanie_gracza(int liczba)
{
    qDebug()<<"[int OknoGlowne::losowanie_gracza()]";
    if (liczba==0)
    {
        int los=0;
        qDebug()<<"[int OknoGlowne::losowanie_gracza()---END]";
        return los;
    }
    int los = qrand()%liczba;
    if (los<0)
        los=los*(-1);
    qDebug()<<"Wylosowano gracza nr: "<<los;
    qDebug()<<"[int OknoGlowne::losowanie_gracza()---END]";
    return los;

}
KoloLosu::KoloLosu(int liczba)
{
    qDebug()<<"[KoloLosu::KoloLosu(int liczba)]";
    wylosowanaPozycja=-1;
    iloscPozycji=12;
    tura=0;
    liczbaGraczy=liczba;
    qDebug()<<"Liczba Graczy na starcie wynosi: "<<liczbaGraczy;
    nagrody << "BANKRUT!!" << "400" << "2500" << "250" << "STOP" << "400" << "200" << "100" << "STOP" << "150" << "250" <<"300";
    nazwaTury << "Początek BETA narazie zakręć kołem" << "Zakręć kołem" << "Wybierz Literę lub zgaduj";
    listaGraczy = new Gracz [liczbaGraczy];
    aktualnyZawodnikIndex=losowanie_gracza(liczbaGraczy);
    qDebug()<<"Aktualny Zawodnik na starcie wynosi: "<<aktualnyZawodnikIndex;
    aktualnyZawodnik = &listaGraczy[aktualnyZawodnikIndex]; //tutaj możesz losować
    qDebug()<<"[KoloLosu::KoloLosu(int liczba)--END]";
}

KoloLosu::~KoloLosu()
{
    delete listaGraczy;
}

int KoloLosu::wygrajPunkty(int poprzedniePunkty, int wygranePunkty)
{
    return poprzedniePunkty + wygranePunkty;
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
