#include "GUI.h"

GUI::GUI()
{
  currentFace = WHITE;
  neighbors[0] = GREEN;
  neighbors[1] = ORANGE;
  neighbors[2] = BLUE;
  neighbors[3] = RED;
  neighbors[4] = YELLOW;
  cam_x = 0;
  cam_y = 0;
  cam_z = 20;
}

GUI::~GUI()
{
  //dtor
}

void GUI::setCamera(void) {
  // gluLookAt
  // tu l'appelles dans affichage
}

void GUI::majCurrentFace(Sens sens) {
    Color tmp = currentFace;

    switch (sens) {
        case DOWN:
            currentFace = neighbors[1];
            neighbors[1] = neighbors[4];
            neighbors[4] = neighbors[3];
            neighbors[3] = tmp;
            break;
        case UP:
            currentFace = neighbors[3];
            neighbors[3] = neighbors[4];
            neighbors[4] = neighbors[1];
            neighbors[1] = tmp;
            break;
        case RIGHT:
            currentFace = neighbors[0];
            neighbors[0] = neighbors[4];
            neighbors[4] = neighbors[2];
            neighbors[2] = tmp;
            break;
        case LEFT:
            currentFace = neighbors[2];
            neighbors[2] = neighbors[4];
            neighbors[4] = neighbors[0];
            neighbors[0] = tmp;
            break;
    }
}
