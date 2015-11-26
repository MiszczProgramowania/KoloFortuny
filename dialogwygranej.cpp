#include "dialogwygranej.h"
#include "ui_dialogwygranej.h"

DialogWygranej::DialogWygranej(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWygranej)
{
    ui->setupUi(this);

    wyswietlWygranych();
    poukladajWygranych();
}

DialogWygranej::~DialogWygranej()
{
    delete ui;
}

bool DialogWygranej::wyswietlWygranych()
{
    qDebug()<<"[bool DialogWygranej::wyswietlWygranych()]";
    if (dane.listaWygranych.isEmpty()||dane.listaWygranych.isNull())
        return false;
    QStringList temp = dane.listaWygranych.split(",",QString::SkipEmptyParts);
    for(int j=0;j<ui->tableWidgetWygrani->rowCount();j++)
    {
        ui->tableWidgetWygrani->removeRow(j);
    }
    int i=0;
    foreach(QString iteracja,temp)
    {
        QStringList temp2;
        temp2=iteracja.split(":");
        qDebug()<<"temp2.at(0);"<<temp2.at(0);
        qDebug()<<"temp2.at(1);"<<temp2.at(1);
        int temp3=temp2.at(1).toInt();
        ui->tableWidgetWygrani->insertRow(i);
        QTableWidgetItem * x = new QTableWidgetItem(temp2.at(0));
        qDebug()<<"x wynosi: "<<x->text();
        ui->tableWidgetWygrani->setItem(i,0,x);

        QTableWidgetItem * y= new QTableWidgetItem();
        qDebug()<<"y wynosi: "<<y->text();
        ui->tableWidgetWygrani->setItem(i,1,y);
        ui->tableWidgetWygrani->item(i,1)->setData(Qt::DisplayRole,temp3);
        i++;

    }
qDebug()<<"[bool DialogWygranej::wyswietlWygranych()]---END";
    return true;
}

void DialogWygranej::poukladajWygranych()
{
    ui->tableWidgetWygrani->sortItems(1,Qt::DescendingOrder);
}
