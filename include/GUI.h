#ifndef GUI_H
#define GUI_H
#include <CubeView.h>
#include <GL/glut.h>


class GUI
{
  public:
    GUI();
    virtual ~GUI();
    void majCurrentFace(Sens sens);
    void setCamera(void);
  protected:
  private:
    Color currentFace;
    Color neighbors[5];
    GLdouble cam_x, cam_y, cam_z;

};

#endif // GUI_H
