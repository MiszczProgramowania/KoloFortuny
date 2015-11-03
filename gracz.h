#ifndef GRACZ_H
#define GRACZ_H
#include <QString>

class Gracz
{
private:
QString nazwa;
int punkty;
bool wygral;

public:
    Gracz();

    void ustawNazwe(QString n);
    void ustawPunkty(int p);
    void ustawWygral(bool w);

    QString pobierzNazwe();
    int pobierzPunkty();
    bool sprawdzCzyWygral();

};

#endif // GRACZ_H
