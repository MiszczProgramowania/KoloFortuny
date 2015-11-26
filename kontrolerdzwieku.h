#ifndef KONTROLERDZWIEKU_H
#define KONTROLERDZWIEKU_H
#include <QtMultimedia/QSoundEffect>

class KontrolerDzwieku
{
private:

public:
    KontrolerDzwieku();
    QSoundEffect ruchKola;
    QSoundEffect wygrana;
    QSoundEffect dialog;
    QSoundEffect nowaGra;
    QSoundEffect blad;
    QSoundEffect wylosowano;
};

#endif // KONTROLERDZWIEKU_H
