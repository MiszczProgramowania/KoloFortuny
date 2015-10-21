#ifndef PLIK_H
#define PLIK_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>

class Plik
{

public:
    QString sciezka;
    QString tekst;
    void zapis_do_pliku();
    QString odczyt_z_pliku();
    QString wycinanie_szukanego_tekstu(QString szukana);
};

#endif // PLIK_H
