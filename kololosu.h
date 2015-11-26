#ifndef KOLOLOSU_H
#define KOLOLOSU_H
#include <QString>
#include <QList>
#include <QDebug>
#include "gracz.h"
#include "kontrolerdzwieku.h"
class KoloLosu
{
private:
    int iloscPozycji;
    KontrolerDzwieku dzwiek;
    int losowanie_gracza(int liczba);
public:
    Gracz * aktualnyZawodnik;
    Gracz * listaGraczy;
    int aktualnyZawodnikIndex;
    QStringList nagrody;
    int wylosowanaPozycja;
    QStringList nazwaTury;
    int tura;
    int liczbaGraczy;

    KoloLosu();
    KoloLosu(int liczbaGraczy);
    ~KoloLosu();
    int wygrajPunkty(int poprzedniePunkty, int wygranePunkty);



    void realizacjaWygranej(int liczbaWystapien);
    void losowaniePozycji();

};

#endif // KOLOLOSU_H
