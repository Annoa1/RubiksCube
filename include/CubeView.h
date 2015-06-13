#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include <Cube.h>
#include <GL/glut.h>

/**
 * \file main.c
 * \brief Programme de tests.
 * \author Franck.H
 * \version 0.1
 * \date 11 septembre 2007
 *
 * Programme de test pour l'objet de gestion des chaînes de caractères Str_t.
 *
 */

enum Color {WHITE, GREEN, RED, BLUE, YELLOW, ORANGE};
enum Axe {X, Y, Z};
enum Sens {UP, DOWN, RIGHT, LEFT};



class CubeView
{
  public:
    CubeView(Cube* cube);
    virtual ~CubeView();

    // à appeler dans la boucle d'animation (mise à jour + affichage)
    void update(void);

    //////////////////////////
    // fonctions animations //
    //////////////////////////

    // rotations du cube (en entier)
    void mooveCube(Sens s);
    void rotation(Axe axe, bool sensHoraire = true);

    //
    static void setGlutColor(Color c);

  private:
    Color currentFace;
    int currentXAngle;
    int currentYAngle;
    int currentZAngle;
    Cube* cube;
    void draw(void);
    bool isMooving = false;
    int angle;
    static int speed;
    void setFaceRepere(Color f);
    void setPerspective();
};

#endif // CUBEVIEW_H
