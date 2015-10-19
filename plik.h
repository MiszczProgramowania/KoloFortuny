#ifndef PLIK_H
#define PLIK_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>

class Plik
{

private:

public:

    QString sciezka;
    QString zapis_do_pliku();
    QString odczyt_z_pliku();

};

#endif // PLIK_H
