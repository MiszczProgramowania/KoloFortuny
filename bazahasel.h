#ifndef BAZAHASEL_H
#define BAZAHASEL_H
#include "plik.h"


class BazaHasel : public Plik
{
public:
    QStringList baza;
    QStringList tekst_na_baze();
    BazaHasel();
    QString baza_na_tekst();
    QStringList przetworz_na_baze_hasel(QString t);
};

#endif // BAZAHASEL_H
