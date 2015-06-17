#ifndef CUBE_H
#define CUBE_H

#include <iostream>

#define NBFACES 6
#define NBCOL 3

using namespace std;

/*! \class Cube
 * \brief classe representant le Cube
 *
 *  La classe gere l'affichage et la rotation d'un Cube
 */
class Cube
{
    public:
     /*!
      *  \brief Constructeur
      *
      *  Constructeur de la classe Cube
      *
      *  \param
      */
      Cube();

      void afficher();/*!< Fonction affichage du cube */

     /*!
      *  \brief Destructeur
      *
      *  Destructeur de la classe Cube
      */
      virtual ~Cube();


    void rotation(int face, int sens);/*!< Fonction rotation du cube */

    int face[NBFACES][NBCOL][NBCOL];
    protected:
    private:

};

#endif // CUBE_H
