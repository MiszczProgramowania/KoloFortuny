#ifndef OKNOGLOWNE_H
#define OKNOGLOWNE_H

#include <QMainWindow>
#include "plik.h"

namespace Ui {
class OknoGlowne;
}

class OknoGlowne : public QMainWindow
{
    Q_OBJECT
private:
    Plik plik_hasel;
public:

    explicit OknoGlowne(QWidget *parent = 0);
    ~OknoGlowne();
    QString zapis_do_pliku(QString sciezka);
    QString odczyt_z_pliku(QString sciezka);
private slots:
    void on_actionWczytaj_triggered();


private:
    Ui::OknoGlowne *ui;
};

#endif // OKNOGLOWNE_H
