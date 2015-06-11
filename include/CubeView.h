#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include <Cube.h>
#include <GL/glut.h>

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
    void rotateX(bool sensHoraire = true);
    void rotateY(bool sensHoraire = true);
    void rotateZ(bool sensHoraire = true);

    // quelques animations (� completer selon les demandes de cube)
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
