#include "dialogwygranej.h"
#include "ui_dialogwygranej.h"

DialogWygranej::DialogWygranej(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWygranej)
{
    ui->setupUi(this);

    wyswietlWygranych();
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
        ui->tableWidgetWygrani->insertRow(i);
        QTableWidgetItem * x = new QTableWidgetItem(temp2.at(0));
        qDebug()<<"x wynosi: "<<x->text();
        ui->tableWidgetWygrani->setItem(i,0,x);

        QTableWidgetItem * y = new QTableWidgetItem(temp2.at(1));
        qDebug()<<"y wynosi: "<<y->text();
        ui->tableWidgetWygrani->setItem(i,1,y);
        i++;

    }
qDebug()<<"[bool DialogWygranej::wyswietlWygranych()]---END";
    return true;
}
