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
  glPushMatrix();
  glutSolidCube(2);
  glPopMatrix();
}
