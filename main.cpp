#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <Cube.h>
#include <CubeView.h>

using namespace std;




/* Prototypes des fonctions utilisees par glut */
void redimensionne(int largeur, int hauteur);
void display(void);
int rubixConsole(void);

Cube unCube;
CubeView cubeView(&unCube);

/* Point d'entree du programme : fonction main */
int main(int argc, char *argv[])
{
    //rubixConsole();



    /* Initialisation de glut et creation
    de la fenetre */
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(100,100);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("TP : Introduction a OpenGL");
    glEnable(GL_DEPTH_TEST);

    /* Initialisation OpenGL : machine à etats... */
    glClearColor(0.0,0.0,0.0,0.0);

    /* Enregistrement des fonctions de rappel ("CallBacks" evenementielles) */
    glutReshapeFunc(redimensionne);
    glutDisplayFunc(display);

    /* Entree dans la boucle principale glut */
    glutMainLoop();

    return EXIT_SUCCESS;
}



// Exemple d'utilisation du rubix en mode console
int rubixConsole(void)
{
    cout << "Hello world!" << endl;
    Cube unCube;
    unCube.afficher();

    /*
    unCube.rotation(1,1);
    unCube.afficher();
    unCube.rotation(1,2);
    unCube.afficher();
    unCube.rotation(3,1);
    unCube.afficher();
    unCube.rotation(3,2);
    unCube.afficher();
    unCube.rotation(1,2);
    unCube.afficher();
    unCube.rotation(2,1);
    unCube.afficher();
    unCube.rotation(2,2);
    unCube.afficher();
    unCube.rotation(5,1);
    unCube.afficher();
    unCube.rotation(5,2);
    unCube.afficher();
    unCube.rotation(4,1);
    unCube.afficher();
    unCube.rotation(4,2);
    unCube.afficher();*/

    int num = 42;
    int sens;
    while(num != -1) {
        cout << "Quelle face voulez vous faire tourner ? 0, 1, 2, 3, 4 ou 5" << endl;
        cout << "Entrez -1 pour arrêter." << endl;
        cin >> num;
        if(num !=-1 ) {
            cout << "Dans quel sens ? horaire = 1, inverse = 2" << endl;
            cin >> sens;
            unCube.rotation(num,sens);
            unCube.afficher();
        }
    }

    return 0;
}


void display(void) {
  /* Variables locales ET statiques pour memorisation entre affichages successifs */
    static GLdouble pos_cam_x = 0, pos_cam_y = 0;

    /* Effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Selection / Initialisation de la matrice de transformation des objets */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    /* Placement de la camera */
    gluLookAt(pos_cam_x, pos_cam_y, -20, 0,0,0, 0,1,0);
    /* On empile (ie. memorise) la matrice de transformation des objets
    courante afin de la reutiliser pour chacun des objets de la
    scene. Ainsi, tous les objets seront dessines avec un unique point
    de vue, celui choisi a l'aide de la commande gluLookAt */
    glPushMatrix();

    /* Objets 3D de la scene */

    cubeView.update();

     /* On restitue la matrice de tranformation des objets
     presente en memoire a l'aide de la fonction glPopMatrix
     pour le trace des formes suivantes. */
     glPopMatrix(); // Restitution environnement


    /* Il n'y a plus aucun objet a dessiner, on libere la memoire
    utilisee par la matrice de transformation memorisee */

    /* ATTENTION : le nombre d'appels de la fonction glPopMatrix
    doit etre egal a celui de la fonction glPushMatrix.
    Dans le cas contraire (glPushMatrix > glPopMatrix), un depassement
    de capacites de la pile conduit a un plantage du programme ! */


    /* On affiche la scene nouvellement calculee (double buffer) */
    glutSwapBuffers();

    glutPostRedisplay();
}

/* Gestion du redimensionnement de la fenetre + projections de la scene */
void redimensionne(int largeur, int hauteur)
{
    glViewport(0, 0, largeur, hauteur);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, largeur/(GLdouble)hauteur , 1.0, 100.);
}
