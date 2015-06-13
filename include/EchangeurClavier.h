#ifndef ECHANGEURCLAVIER_H
#define ECHANGEURCLAVIER_H

const unsigned int NB_MAX_TOUCHE_MEMO = 10;
enum {AUCUNE, HAUT, BAS, GAUCHE, DROITE, ECHAP, ESPACE, ZOOM, DEZOOM, ARROW_UP, ARROW_DOWN, ARROW_RIGHT, ARROW_LEFT};

class EchangeurClavier
{
public:
    EchangeurClavier();
    bool touchePressee();
    void ajouteTouchePressee(int touche);
    int recupereTouchePressee();

private:
    unsigned int nb_touches_memorisees;
    int liste_touche_memo[NB_MAX_TOUCHE_MEMO];
};

#endif // ECHANGEURCLAVIER_H
