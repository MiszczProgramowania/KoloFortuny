#ifndef FORMULARZHASEL_H
#define FORMULARZHASEL_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include "bazahasel.h"
#include <QFileDialog>

namespace Ui {
class FormularzHasel;
}

class FormularzHasel : public QDialog
{
    Q_OBJECT
private:

public:
    explicit FormularzHasel(QWidget *parent = 0);
    ~FormularzHasel();
    BazaHasel tymczasowa;
    void zaczytajFormularz();

private slots:

    void on_buttonBox_accepted();

    void on_pushButtonNowyWiersz_released();

private:
    Ui::FormularzHasel *ui;
};

#endif // FORMULARZHASEL_H
