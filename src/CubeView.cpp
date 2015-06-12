#include "CubeView.h"

CubeView::CubeView(Cube* c)
{
  cube = c;
  currentFace = WHITE;
  currentUpFace = ORANGE;
}

CubeView::~CubeView()
{
  //dtor
}

void CubeView::update(void) {
  draw();
}

// modifie le repère en fonction de la face courrante
void CubeView::setDrawRepere(Color f) {
  // cas de base :
  // currentFace == WHITE
  // currentUpFace == ORANGE

  // on se place face au cube
  switch (currentFace) {
    case WHITE:     glRotated(0, 0, 0, 0);break;
    case ORANGE:    glRotated(-90, 1, 0, 0);break;
    case BLUE:      glRotated(90, 0, 1, 0); break;
    case RED:       glRotated(-3*90, 1, 0, 0);break;
    case GREEN:     glRotated(3*90, 0, 1, 0);break;
    case YELLOW:    glRotated(-2*90, 0, 1, 0);
  }

  // on rotationne le cube
  switch (currentUpFace) {
  }
}

void CubeView::setFaceRepere(Color f) {


  switch (f) {
    case WHITE:     glRotated(0, 0, 0, 0);
                    glRotated(-90, 0, 0, 1); break;
    case ORANGE:    glRotated(-90, 1, 0, 0);
                    glRotated(-90, 0, 0, 1); break;
    case BLUE:      glRotated(90, 0, 1, 0); break;
    case RED:       glRotated(-3*90, 1, 0, 0);
                    glRotated(-90, 0, 0, 1); break;
    case GREEN:     glRotated(3*90, 0, 1, 0);
                    glRotated(2*90, 0, 0, 1); break;
    case YELLOW:    glRotated(-2*90, 0, 1, 0);
                    glRotated(90, 0, 0, 1);
  }
}

void CubeView::setGlutColor(Color c) {
  switch (c) {
    case WHITE:   glColor3f(1,1,1); break;
    case RED:     glColor3d(1,0,0); break;
    case BLUE:    glColor3d(0,0,1); break;
    case GREEN:   glColor3d(0,1,0); break;
    case YELLOW:  glColor3f(1,1,0); break;
    case ORANGE:  glColor3f(1,0.5,0);
  }
}

void CubeView::rotatation(Axe axe, bool sensHoraire = true) {
  switch (axe) {
    case X: break;
    case Y: break;
    case Z: ;
  }
}

/**
 * Dessine le cube si il n'y a pas d'animations en cours
 */
void CubeView::draw(void) {

  int cX, cY;
  float diff = 0.1;
  float cote = 3 - 0.05;

  for (int f=0; f<NBFACES; f++) {
    glPushMatrix();
    setFaceRepere((Color) f);
    // fond noir
    glBegin(GL_QUADS) ;
    glColor3f(0,0,0);
    glVertex3f(-cote, cote, cote);
    glVertex3f(-cote, -cote, cote);
    glVertex3f(cote, -cote, cote);
    glVertex3f(cote, cote, cote);
    glEnd();


    // Ici on change le repère de dessin en fonction de la face (todo)

    for (int i=0; i<NBCOL; i++) {
      for (int j=0; j<NBCOL; j++) {

        cX = 2*i-2;
        cY = 2*j-2;

        glBegin(GL_QUADS) ;
        setGlutColor((Color) cube->face[f][i][j]);
        glVertex3f(cX-1 +diff, cY+1 -diff, 3);
        glVertex3f(cX-1 +diff, cY-1 +diff, 3);
        glVertex3f(cX+1 -diff, cY-1 +diff, 3);
        glVertex3f(cX+1 -diff, cY+1 -diff, 3);
        glEnd();
      }
    }
    glPopMatrix();
  }

  glPopMatrix();
}
