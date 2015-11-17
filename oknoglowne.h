#ifndef OKNOGLOWNE_H
#define OKNOGLOWNE_H

#include <QMainWindow>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <Qtime>
#include "plik.h"
#include "bazahasel.h"
#include "konfiguracja.h"
#include "kololosu.h"
#include "formularzhasel.h"
#include <QPixmap>
#include <QPainter>
#include <QThread>

namespace Ui {
class OknoGlowne;
}

class OknoGlowne : public QMainWindow
{
    Q_OBJECT
private:
    Konfiguracja plik_conf;
    BazaHasel plik_hasel;
    QImage obrazekKola;
    int losowanie_partii();
    void odkrycie_hasla(QString temp);
    void zakrycie_hasla(QString temp);
    void inicjalizacja_podpowiedzi(QString temp);
    int szukajLiter(QString temp,QChar szukana);
    void aktualizacjaElementowUi();
    void obrotGrafiki(int wylosowanyObrot);
public:
    KoloLosu * kolo;
    explicit OknoGlowne(QWidget *parent = 0);

    QString intToStr(int n);
    void najpierwZaczytajBaze();
    void najpierwUruchomGre();
    void zmianaTury();
    void zmianaGracza();
    bool czyTraciKolejke();
    void uwzglednijWygrana(int liczbaWystapien);
    void wygranaRozgrywka();
    void czyszczenieElementowUi();
    ~OknoGlowne();
private slots:
    void on_actionWczytaj_triggered();

    void on_actionNowa_triggered();

    void on_actionUtw_rz_triggered();

    void on_wybierzLitere_released();

    void on_wybranaLitera_returnPressed();

    void on_buttonLosuj_released();

    void on_lineEditZgadnij_returnPressed();

private:
    Ui::OknoGlowne *ui;
};

#endif // OKNOGLOWNE_H
