#include "CubeView.h"

CubeView::CubeView(Cube* cube)
{
  //ctor
}

CubeView::~CubeView()
{
  //dtor
}

void CubeView::update(void) {
  draw();
}

//enum Color {WHITE, ORANGE, BLUE, RED, GREEN, YELLOW};

void CubeView::setGlutRepere(Color f) {
    // cas de base :
    // currentFace == WHITE
    // currentUpFace == ORANGE

  switch (f) {
    case WHITE:     glRotated(0, 0, 0, 0); break;
    case ORANGE:    glRotated(PI/2, 1, 0, 0); break;
    case BLUE:      glRotated(PI/2, 0, 1, 0); break;
    case RED:       glRotated(3*PI/2, 1, 0, 0); break;
    case GREEN:     glRotated(3*PI/2, 0, 1, 0); break;
    case YELLOW:
    default:        glRotated(PI, 1, 0, 0);
  }
}

void CubeView::setGlutColor(Color c) {
  switch (c) {
    case WHITE:   glColor3f(1,1,1); break;
    case RED:     glColor3d(1,0,0); break;
    case BLUE:    glColor3d(0,0,1); break;
    case GREEN:   glColor3d(0,1,0); break;
    case YELLOW:  glColor3f(1,1,0); break;
    case ORANGE:
    default:      glColor3f(1,0.5,0);
  }
}

/**
 * Dessine le cube si il n'y a pas d'animations en cours
 */
void CubeView::draw(void) {

  int cX, cY;

  for (int f=0; f<NBFACES; f++) {
    glPushMatrix();
    // Ici on change le repère de dessin en fonction de la face (todo)
    setGlutRepere((Color) f);
    for (int i=0; i<NBCOL; i++) {
      for (int j=0; j<NBCOL; j++) {

        cX = 2*i-2;
        cY = 2*j-2;

        glBegin(GL_QUADS) ;
        setGlutColor((Color) f);
        glVertex3i(cX-1, cY+1, 3);
        glVertex3i(cX-1, cY-1, 3);
        glVertex3i(cX+1, cY-1, 3);
        glVertex3i(cX+1, cY+1, 3);
        glEnd();
      }
    }
    glPopMatrix();
  }

  glPopMatrix();
}
