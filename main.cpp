#include "oknoglowne.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //ustawiamy ikonkę wszędzie
    OknoGlowne w;
    QIcon ikonka;
    QPixmap icon;
    icon.load("icon.ico");
    ikonka.addPixmap(icon);
    w.setWindowIcon(ikonka);
    //ustawiamy ikonkę wszędzie --- end
    w.show();

    return a.exec();
}
