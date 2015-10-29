#ifndef BAZAHASEL_H
#define BAZAHASEL_H
#include "plik.h"


class BazaHasel : public Plik
{
private:
    QString separator;
public:
    BazaHasel();
    struct Baza
    {
        QStringList slowa;
        QStringList podpowiedzi;
    }baza;



    void tekst_na_baze();

    QString baza_na_tekst();
    QStringList przetworz_na_baze_hasel(QString t);
};

#endif // BAZAHASEL_H
