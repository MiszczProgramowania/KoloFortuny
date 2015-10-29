#ifndef BAZAHASEL_H
#define BAZAHASEL_H
#include "plik.h"


class BazaHasel : public Plik
{
private:
    QString separator;

public:
    BazaHasel();
    int nrPartii;
    struct Baza
    {
        QStringList slowa;
        QStringList podpowiedzi;
    }baza;
    QString znacznikNiewiadomej;


    void tekst_na_baze();

    QString baza_na_tekst();
    QStringList przetworz_na_baze_hasel(QString t);
};

#endif // BAZAHASEL_H
