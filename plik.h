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
    QString zapis_do_pliku();
    QString odczyt_z_pliku();

};

#endif // PLIK_H
