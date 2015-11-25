#ifndef GRACZ_H
#define GRACZ_H
#include <QString>
#include <QInputDialog>
#include <QObject>
#include <QWidget>
#include <QDebug>

class Gracz
{
private:
QString nazwa;
int punkty;
bool wygral;
int jakaCena(int pozycja);
public:
    Gracz();

    void ustawNazwe(QString n);
    void ustawPunkty(int p);
    void ustawWygral(bool w);
    bool czy_samogloska(QChar temp);
    bool moze_kupic(int pozycja);
    void kup_samogloske(int pozycja);
    void niezgadl(int pozycja);
    QString pobierzNazwe();
    int pobierzPunkty();
    bool sprawdzCzyWygral();

};

#endif // GRACZ_H
