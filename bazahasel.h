#ifndef BAZAHASEL_H
#define BAZAHASEL_H
#include "plik.h"


class BazaHasel : public Plik
{
public:
    BazaHasel();
    QStringList baza;
    QStringList podpowiedzi;

    void tekst_na_baze();

    QString baza_na_tekst();
    QStringList przetworz_na_baze_hasel(QString t);
};

#endif // BAZAHASEL_H
