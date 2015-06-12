#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include <Cube.h>

/**
 * \file main.c
 * \brief Programme de tests.
 * \author Franck.H
 * \version 0.1
 * \date 11 septembre 2007
 *
 * Programme de test pour l'objet de gestion des cha�nes de caract�res Str_t.
 *
 */

enum Color {RED, BLUE, GREEN, YELLOW, ORANGE, WHITE};


class CubeView
{
  public:
    CubeView(Cube* cube);
    virtual ~CubeView();

    // � appeler dans la boucle d'animation (mise � jour + affichage)
    void update(void);

    //////////////////////////
    // fonctions animations //
    //////////////////////////

    // rotations du cube (en entier)
    void rotateUp(void);
    void rotateDown(void);
    void rotateLeft(void);
    void rotateRight(void);

    // quelques animations (� completer selon les demandes GUI)
    void mooveRightUp(void);
    void mooveRightDown(void);
    void mooveLeftUp(void);
    void mooveLeftDown(void);

  private:
    int currentFace;
    Cube* cube;
    void draw(void);
    bool isMooving = false;
    int angle;
    static int speed;
};

#endif // CUBEVIEW_H
