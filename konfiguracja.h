#ifndef KONFIGURACJA_H
#define KONFIGURACJA_H
#include "plik.h"
#include <QFile>
class Konfiguracja : public Plik
{
private:
    //domyślne parametry konfiguracyjne
    QString sciezka_do_hasel;

public:
    Konfiguracja();
    QString listaWygranych;
    QString wycinanie_parametru(QString szukana);
    void tekst_na_konfiguracje();
    void konfiguracja_na_tekst();
    QString wgraj_sciezke_do_hasel();
    void ustaw_sciezke_do_hasel(QString temp);
};

#endif // KONFIGURACJA_H
