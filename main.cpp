#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "Cube.h"
#include "CubeView.h"
#include "EchangeurClavier.h"

using namespace std;

/* Prototypes des fonctions evenementielles utilisees par glut */
void redimensionne(int largeur, int hauteur);
void display(void);
void clavier(unsigned char touche, int x, int y);
void numClavier(int key, int x, int y); // touches du numpad

/* Prototype des fonctions tmp */
int rubixConsole(void);
void drawString(char *S);
void drawRepere(void);

/* Variables globales */
Cube unCube;
CubeView cubeView(&unCube);
EchangeurClavier mesTouches;

/*--------------------------------------------------------------------------------*/


/* Point d'entree du programme : fonction main */
int main(int argc, char *argv[]) {
    //rubixConsole();

    /* Initialisation de glut et creation de la fenetre */
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(100,100);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Projet Rubik's Cube");
    glEnable(GL_DEPTH_TEST);

    /* Initialisation OpenGL : machine à etats... */
    glClearColor(0.0,0.0,0.0,0.0);

    /* Enregistrement des fonctions de rappel ("CallBacks" evenementielles) */
    glutReshapeFunc(redimensionne);
    glutDisplayFunc(display);
    glutKeyboardFunc(clavier);
    glutSpecialFunc(numClavier);

    /* Entree dans la boucle principale glut */
    glutMainLoop();

    return EXIT_SUCCESS;
}

void drawRepere(void) {
    glPushMatrix();

    glBegin(GL_LINE_STRIP);
    //axe Y
    glColor3f(0,1,0);
    glVertex3f(0,0,5);
    glVertex3f(0,1,5);
    //axe X
    glColor3f(1,0,0);
    glVertex3f(0,0,5);
    glVertex3f(1,0,5);
    //axe Z
    glColor3f(0,0,1);
    glVertex3f(0,0,5);
    glVertex3f(0,0,6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3d(0,1,0);
    glRasterPos3f(0,1,5);
    drawString("Y");
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,0,0);
    glRasterPos3f(1,0,5);
    drawString("X");
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0,1);
    glRasterPos3f(0,0,6);
    drawString("Z");

    glPopMatrix();
}

// Exemple d'utilisation du rubix en mode console
int rubixConsole(void) {
    cout << "Hello world!" << endl;
    Cube unCube;
    unCube.afficher();

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
    static GLdouble pos_cam_x = 20, pos_cam_y = 0, pos_cam_z = 0, alpha_cam = 0, thetha_cam = 0, dist_cam = 20;
    char strMsg1[100];

    /* Mise a jour des donnees avec les evenements clavier */
    while(mesTouches.touchePressee()) {

        switch(mesTouches.recupereTouchePressee()) {
        case ECHAP:
            exit(EXIT_SUCCESS);
            break;

        case ZOOM:
            dist_cam++;
            if(dist_cam >100)dist_cam=100;
            break;

        case DEZOOM:
            dist_cam--;
            if(dist_cam <1)dist_cam=1;
            break;

        case GAUCHE:
            alpha_cam -=2;
            if(alpha_cam < 0)alpha_cam=358;
            break;

        case DROITE:
            alpha_cam +=2;
            if(alpha_cam >358)alpha_cam=0;
            break;

        case BAS:
            thetha_cam -=2;
            if(thetha_cam < 0)thetha_cam=360;
            break;

        case HAUT:
            thetha_cam +=2;
            if(thetha_cam >358)thetha_cam=0;
            break;
        case ARROW_DOWN:
            cubeView.mooveCube(DOWN);
            break;
        case ARROW_UP:
            cubeView.mooveCube(UP);
            break;
        case ARROW_RIGHT:
            cubeView.mooveCube(RIGHT);
            break;
        case ARROW_LEFT:
            cubeView.mooveCube(LEFT);
            break;
        }
        pos_cam_x = dist_cam * cos(alpha_cam*3.14/180) * cos(thetha_cam*3.14/180);
        pos_cam_z = dist_cam * sin(alpha_cam*3.14/180) * cos(thetha_cam*3.14/180);
        pos_cam_y = dist_cam *                           sin(thetha_cam*3.14/180);
    }

    /* Effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Selection / Initialisation de la matrice de transformation des objets */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    /* Placement de la camera */
    gluLookAt(pos_cam_x, pos_cam_y, pos_cam_z, 0,0,0, 0,1,0);

    /* Objets 3D de la scene */

    glPushMatrix();

    drawRepere();
    cubeView.update();

    glPopMatrix();


    /* On affiche la scene nouvellement calculee (double buffer) */
    glutSwapBuffers();

    glutPostRedisplay();
}

/* Gestion du redimensionnement de la fenetre + projections de la scene */
void redimensionne(int largeur, int hauteur) {
    glViewport(0, 0, largeur, hauteur);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, largeur/(GLdouble)hauteur , 1.0, 100.);
}

void clavier(unsigned char touche, int x, int y) {

    switch (touche) {
    case 27:  /* Les touches 'q' et Esc permettent de quitter le programme */
        mesTouches.ajouteTouchePressee(ECHAP);
        break;
    case 'z':
    case 'Z':
        mesTouches.ajouteTouchePressee(HAUT);
        break;
    case 's':
    case 'S':
        mesTouches.ajouteTouchePressee(BAS);
        break;
    case 'q':
    case 'Q':
        mesTouches.ajouteTouchePressee(GAUCHE);
        break;
    case 'd':
    case 'D':
        mesTouches.ajouteTouchePressee(DROITE);
        break;
    case 'a':
    case 'A':
        mesTouches.ajouteTouchePressee(ZOOM);
        break;
    case 'e':
    case 'E':
        mesTouches.ajouteTouchePressee(DEZOOM);
        break;
    }
    glutPostRedisplay();
}

void numClavier(int key, int x, int y) {
    switch (key) {
    case 100:
        mesTouches.ajouteTouchePressee(ARROW_LEFT);
        break;
    case 101:
        mesTouches.ajouteTouchePressee(ARROW_UP);
        break;
    case 102:
        mesTouches.ajouteTouchePressee(ARROW_RIGHT);
        break;
    case 103:
        mesTouches.ajouteTouchePressee(ARROW_DOWN);
        break;
    }
    glutPostRedisplay();
}

void drawString(char *S) {
    for(unsigned int i =0; i<strlen(S); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,S[i]);
    }
}
