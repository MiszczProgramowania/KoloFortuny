#include "oknoglowne.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    OknoGlowne w;
    w.sciezka_do_pliku="";//reset sciezki_do_pliku
    w.show();

    return a.exec();
}
