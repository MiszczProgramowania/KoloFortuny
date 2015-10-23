#include "formularzhasel.h"
#include "ui_formularzhasel.h"

FormularzHasel::FormularzHasel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormularzHasel)
{
    ui->setupUi(this);
    QList<QAbstractButton *> lista = ui->buttonBox->buttons();
    lista.at(0)->setText("Zapisz jako");
    lista.at(1)->setText("Wyjdź");
}

FormularzHasel::~FormularzHasel()
{
    delete ui;
}

void FormularzHasel::on_tablicaSlow_cellChanged(int row, int column)
{
    qDebug() <<"[FormularzHasel::on_tablicaSlow_cellChanged(int row, int column)]";
    if (row==0&&column==0)
    {
        ui->tablicaSlow->insertRow(row);
    }
    qDebug() <<"[FormularzHasel::on_tablicaSlow_cellChanged(int row, int column)] -> END";
}

void FormularzHasel::on_buttonBox_accepted()
{

}
