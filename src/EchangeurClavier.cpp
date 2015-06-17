/*!
 * \file src\EchangeurClavier.cpp
 * \brief Gestion des evenements clavier
 * \author Groupe 8
 * \version 1.0
 */

#include "EchangeurClavier.h"

EchangeurClavier::EchangeurClavier()
{
    // Constructeur
    unsigned int i;
    nb_touches_memorisees = 0;

    for (i=0; i<NB_MAX_TOUCHE_MEMO; i++)
    {
        liste_touche_memo[i] = AUCUNE;
    }
}

bool EchangeurClavier::touchePressee()
{
    if (nb_touches_memorisees>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EchangeurClavier::ajouteTouchePressee(int touche)
{
    if (nb_touches_memorisees < (NB_MAX_TOUCHE_MEMO - 1) )
    {
        liste_touche_memo[nb_touches_memorisees] = touche;
        nb_touches_memorisees = nb_touches_memorisees + 1;
    }
}

int EchangeurClavier::recupereTouchePressee()
{
    int ret = AUCUNE;

    if(nb_touches_memorisees > 0)
    {
        nb_touches_memorisees = nb_touches_memorisees - 1;
        ret = liste_touche_memo[nb_touches_memorisees];
    }

    return ret;
}
