#ifndef OKNOGLOWNE_H
#define OKNOGLOWNE_H

#include <QMainWindow>
#include "plik.h"
#include "bazahasel.h"
#include "konfiguracja.h"
#include "kololosu.h"

namespace Ui {
class OknoGlowne;
}

class OknoGlowne : public QMainWindow
{
    Q_OBJECT
private:
    Konfiguracja plik_conf;
    BazaHasel plik_hasel;

    int losowanie_partii();
    void odkrycie_hasla(QString temp);
    void zakrycie_hasla(QString temp);
    void inicjalizacja_podpowiedzi(QString temp);
    void szukajLiter(QString temp,QChar szukana);


public:
    KoloLosu * kolo;
    explicit OknoGlowne(QWidget *parent = 0);

    QString intToStr(int n);
    void najpierwZaczytajBaze();
    void najpierwUruchomGre();

    ~OknoGlowne();
private slots:
    void on_actionWczytaj_triggered();

    void on_actionNowa_triggered();

    void on_actionUtw_rz_triggered();

    void on_wybierzLitere_released();

    void on_wybranaLitera_returnPressed();

    void on_buttonLosuj_released();

private:
    Ui::OknoGlowne *ui;
};

#endif // OKNOGLOWNE_H
