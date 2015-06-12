#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include <Cube.h>
#include <GL/glut.h>

enum Color {WHITE, RED, BLUE, GREEN, YELLOW, ORANGE};

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
    void rotateX(bool sensHoraire = true);
    void rotateY(bool sensHoraire = true);
    void rotateZ(bool sensHoraire = true);

    // quelques animations (à completer selon les demandes de cube)
    void mooveRightUp(void);
    void mooveRightDown(void);
    void mooveLeftUp(void);
    void mooveLeftDown(void);

    //
    static void setGlutColor(Color c);

  private:
    int currentFace; // la face principale en affichage (face à nous)
    int currentUpFace; // pour déduire le sens du cube
    Cube* cube;
    void draw(void);
    bool isMooving = false;
    int angle;
    static int speed;
    void setGlutRepere(Color f);
};

#endif // CUBEVIEW_H
