#include "kontrolerdzwieku.h"

KontrolerDzwieku::KontrolerDzwieku()
{
    ruchKola.setSource(QUrl::fromLocalFile(":/sound/tik.wav"));
    blad.setSource(QUrl::fromLocalFile(":/sound/error.wav"));
    wylosowano.setSource(QUrl::fromLocalFile(":/sound/wylosowane.wav"));
}

