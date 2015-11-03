#ifndef KOLOLOSU_H
#define KOLOLOSU_H
#include <QString>
#include <QList>
#include <QDebug>
#include "gracz.h"

class KoloLosu
{
private:
    int wylosowanaPozycja;
    unsigned int iloscPozycji;

public:
    Gracz gracz1;
    KoloLosu();
    int wygrajPunkty(int poprzedniePunkty, int wygranePunkty);
    int bankrut();
    int stop(int poprzedniePunkty);
    void realizacjaWygranej();
    void losowaniePozycji();

};

#endif // KOLOLOSU_H
