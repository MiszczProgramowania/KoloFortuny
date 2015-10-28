#ifndef FORMULARZHASEL_H
#define FORMULARZHASEL_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include "bazahasel.h"

namespace Ui {
class FormularzHasel;
}

class FormularzHasel : public QDialog
{
    Q_OBJECT
private:
    BazaHasel tymczasowa;
public:
    explicit FormularzHasel(QWidget *parent = 0);
    ~FormularzHasel();

private slots:

    void on_tablicaSlow_cellChanged(int row, int column);
    void on_buttonBox_accepted();

private:
    Ui::FormularzHasel *ui;
};

#endif // FORMULARZHASEL_H
