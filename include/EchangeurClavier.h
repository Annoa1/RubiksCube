#ifndef ECHANGEURCLAVIER_H
#define ECHANGEURCLAVIER_H

/*!
 * \file src\EchangeurClavier.h
 * \brief Gestion des evenements clavier
 * \author Groupe 8
 * \version 1.0
 */

const unsigned int NB_MAX_TOUCHE_MEMO = 10;
enum {AUCUNE, HAUT, BAS, GAUCHE, DROITE, ECHAP, ESPACE, ZOOM, DEZOOM, ARROW_UP, ARROW_DOWN, ARROW_RIGHT, ARROW_LEFT,DEBUT};

/*! \class EchangeurClavier
 * \brief Gere l'appui des touches sur le clavier
 *
 * Gestion des evenements clavier
 */
class EchangeurClavier
{
public:

    EchangeurClavier();
    bool touchePressee();
    /*!
     *  \brief Ajout d'un morceau
     *
     *  Methode qui permet d'ajouter un morceau a liste de

     *
     *  \param strSong : le morceau a ajouter
     */

    void ajouteTouchePressee(int touche);
    int recupereTouchePressee();

private:
    unsigned int nb_touches_memorisees;
    int liste_touche_memo[NB_MAX_TOUCHE_MEMO];
};

#endif // ECHANGEURCLAVIER_H
