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

void clavier(unsigned char touche, int x, int y);

Cube unCube;
CubeView cubeView(&unCube);

/* A MODIFIER PLUS TARD */
/*------------------------------------------------------------------*/
/* Constantes */
const unsigned int NB_MAX_TOUCHE_MEMO = 10;
enum {AUCUNE, HAUT, BAS, GAUCHE, DROITE, ECHAP, ESPACE, ZOOM, DEZOOM};


/* Classes */
class EchangeurClavier
{
public:
    EchangeurClavier();
    bool touchePressee();
    void ajouteTouchePressee(int touche);
    int recupereTouchePressee();

private:
    unsigned int nb_touches_memorisees;
    int liste_touche_memo[NB_MAX_TOUCHE_MEMO];
};

EchangeurClavier::EchangeurClavier()
{
    // Constructeur
    unsigned int i;
    nb_touches_memorisees = 0;

    for (i=0; i<NB_MAX_TOUCHE_MEMO; i++)
    {
        liste_touche_memo[i] = AUCUNE;
    }
}

bool EchangeurClavier::touchePressee()
{
    if (nb_touches_memorisees>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EchangeurClavier::ajouteTouchePressee(int touche)
{
    if (nb_touches_memorisees < (NB_MAX_TOUCHE_MEMO - 1) )
    {
        liste_touche_memo[nb_touches_memorisees] = touche;
        nb_touches_memorisees = nb_touches_memorisees + 1;
    }
}

int EchangeurClavier::recupereTouchePressee()
{
    int ret = AUCUNE;

    if(nb_touches_memorisees > 0)
    {
        nb_touches_memorisees = nb_touches_memorisees - 1;
        ret = liste_touche_memo[nb_touches_memorisees];
    }

    return ret;
}

/*
   Variables globales : uniquement pour la gestion des
   evenements. Tout le reste doit etre local a la fonction
   affichage
*/
EchangeurClavier mesTouches;

/*--------------------------------------------------------------------------------*/


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
    glutCreateWindow("Projet Rubik's Cube");
    glEnable(GL_DEPTH_TEST);

    /* Initialisation OpenGL : machine à etats... */
    glClearColor(0.0,0.0,0.0,0.0);

    /* Enregistrement des fonctions de rappel ("CallBacks" evenementielles) */
    glutReshapeFunc(redimensionne);
    glutDisplayFunc(display);
    glutKeyboardFunc(clavier);

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
    static GLdouble pos_cam_x = 20, pos_cam_y = 0, pos_cam_z = 0, alpha_cam = 0, thetha_cam = 0, dist_cam = 20;
    char strMsg1[100];


    /* Mise a jour des donnees avec les evenements clavier */
    while(mesTouches.touchePressee())
    {
        switch(mesTouches.recupereTouchePressee())
        {
        case ECHAP:     exit(EXIT_SUCCESS);
                        break;

        case ZOOM:       dist_cam++;
                        if(dist_cam >100)dist_cam=100;
                        break;

        case DEZOOM:      dist_cam--;
                        if(dist_cam <1)dist_cam=1;
                        break;

        case GAUCHE:    alpha_cam -=2;
                        if(alpha_cam < 0)alpha_cam=358;
                        break;

        case DROITE:    alpha_cam +=2;
                        if(alpha_cam >358)alpha_cam=0;
                        break;

        case BAS:    thetha_cam -=2;
                        if(thetha_cam < 0)thetha_cam=360;
                        break;

        case HAUT:    thetha_cam +=2;
                        if(thetha_cam >358)thetha_cam=0;
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
    /* On empile (ie. memorise) la matrice de transformation des objets
    courante afin de la reutiliser pour chacun des objets de la
    scene. Ainsi, tous les objets seront dessines avec un unique point
    de vue, celui choisi a l'aide de la commande gluLookAt */

    /* Objets 3D de la scene */

    cubeView.update();



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

void clavier(unsigned char touche, int x, int y)
{
    switch (touche)
    {
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
    // Force le reaffichage et calcul de la scene apres reception d'un evenement
    glutPostRedisplay();
}
