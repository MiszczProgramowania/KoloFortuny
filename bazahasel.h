#ifndef BAZAHASEL_H
#define BAZAHASEL_H
#include "plik.h"


class BazaHasel : public Plik
{
private:
    int ilosc_hasel; //do usuniecia
public:
    BazaHasel();
    QStringList baza;
    QStringList tekst_na_baze();
    QString baza_na_tekst();
    QStringList przetworz_na_baze_hasel(QString t);
};

#endif // BAZAHASEL_H
