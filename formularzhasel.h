#ifndef FORMULARZHASEL_H
#define FORMULARZHASEL_H

#include <QDialog>

namespace Ui {
class FormularzHasel;
}

class FormularzHasel : public QDialog
{
    Q_OBJECT

public:
    explicit FormularzHasel(QWidget *parent = 0);
    ~FormularzHasel();

private:
    Ui::FormularzHasel *ui;
};

#endif // FORMULARZHASEL_H
