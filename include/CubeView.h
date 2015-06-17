/*!
 * \file src\CubeView.h
 * \brief Visualisation du cube
 * \author Groupe 8
 * \version 1.0
 */

#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include <Cube.h>
#include <GL/glut.h>

/*! \brief Enumeration des couleurs des faces
     *
     * Enumeration couleurs des faces.
     */
enum Color {WHITE, GREEN, RED, BLUE, YELLOW, ORANGE};

/*! \brief Enumeration des axes
     *
     * Enumeration des axes.
     */
enum Axe {X, Y, Z};

/*! \brief Enumeration des sens
     *
     * Enumeration couleurs des faces.
     */
enum Sens {UP, DOWN, RIGHT, LEFT};

#define NBVOISINS 5

/*! \class CubeView
 * \brief Gere la visualisation d'un Cube
 *
 *  Visualisation
 */
class CubeView
{
  public:

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Cube
    *
    *  \param
    */
    CubeView(Cube* cube);

   /*!
    *  \brief Destructeur
    *
    *  Destructeur de la classe Cube
    */
    virtual ~CubeView();

    // à appeler dans la boucle d'animation (mise à jour + affichage)
    void update(void);
    // rotations du cube (en entier)
    void mooveCube(Sens s);


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

    static int speed;
    bool areAngles(int x, int y, int z);

    void setFaceRepere(Color f);
    void setPerspective();

    void rotation(Axe axe, bool sensHoraire = true);
    void majCurrentFace(Sens sens);

    // left, up, right, bottom, back
    Color neighbors[5];
};

#endif // CUBEVIEW_H
