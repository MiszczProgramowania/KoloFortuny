#ifndef KOLOLOSU_H
#define KOLOLOSU_H
#include <QString>
#include <QList>
#include <QDebug>
#include "gracz.h"

class KoloLosu
{
private:

    unsigned int iloscPozycji;

public:
    Gracz gracz1;
    QStringList nagrody;
    int wylosowanaPozycja;
    QStringList nazwaTury;
    int tura;

    KoloLosu();
    int wygrajPunkty(int poprzedniePunkty, int wygranePunkty);
    int bankrut();
    int stop(int poprzedniePunkty);
    bool czyTraciKolejke();
    void realizacjaWygranej(int liczbaWystapien);
    void losowaniePozycji();

};

#endif // KOLOLOSU_H
