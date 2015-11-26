#ifndef DIALOGWYGRANEJ_H
#define DIALOGWYGRANEJ_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include "konfiguracja.h"

namespace Ui {
class DialogWygranej;
}

class DialogWygranej : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWygranej(QWidget *parent = 0);
    ~DialogWygranej();
    bool wyswietlWygranych();
private:
    Ui::DialogWygranej *ui;
    Konfiguracja dane;
    void poukladajWygranych();
};

#endif // DIALOGWYGRANEJ_H
