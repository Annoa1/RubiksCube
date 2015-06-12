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
    void rotatation(Axe axe, bool sensHoraire);

    //
    static void setGlutColor(Color c);

  private:
    Color currentFace; // la face principale en affichage (face à nous)
    Color currentUpFace; // pour déduire le sens du cube
    Cube* cube;
    void draw(void);
    bool isMooving = false;
    int angle;
    static int speed;
    void setFaceRepere(Color f);
    void setDrawRepere(Color f);
};

#endif // CUBEVIEW_H
