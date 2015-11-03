#ifndef KOLOLOSU_H
#define KOLOLOSU_H
#include <QString>
#include <QList>

class KoloLosu
{
private:
    int wylosowanaPozycja;
    int iloscPozycji;
public:
    int wygrajPunkty(int poprzedniePunkty);
    int bankrut(int poprzedniePunkty);
    int stop(int poprzedniePunkty);

    void losowaniePozycji();
    KoloLosu();
};

#endif // KOLOLOSU_H
