#include "oknoglowne.h"
#include "ui_oknoglowne.h"
#include <QFileDialog>
OknoGlowne::OknoGlowne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OknoGlowne)
{
    ui->setupUi(this);
}

OknoGlowne::~OknoGlowne()
{
    delete ui;
}

void OknoGlowne::on_actionWczytaj_triggered()
{
    sciezka_do_pliku = QFileDialog::getOpenFileName(this,"Otwórz plik",QString(),"*.txt");
}
