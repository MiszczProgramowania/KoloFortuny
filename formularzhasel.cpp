#include "formularzhasel.h"
#include "ui_formularzhasel.h"

FormularzHasel::FormularzHasel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormularzHasel)
{
    ui->setupUi(this);
}

FormularzHasel::~FormularzHasel()
{
    delete ui;
}
