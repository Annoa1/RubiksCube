//#include <stdlib.h>
//#include <GL/glut.h>
//#include <math.h>
//#include "fonction.h"
//
//
//#define WIDTH 600
//#define HEIGHT 600
//
///* Prototypes des fonctions utilisees par glut */
//void redimensionne(int largeur, int hauteur);
//void mainDisplay(void);
//void mainDisplay2(void);
//void subDisplay(void);
//void clavier(unsigned char touche, int x, int y);
//void GestionSpecial(int key, int x, int y);
//void timer(int value);
//void mMotion(int x, int y);
//
//int winIdMain;
//int winIdMain2;
//int winIdSub;
//
///* Point d'entree du programme : fonction main */
///*int main(int argc, char *argv[])
//{
//    init();
//
//    //Initialisation de glut et creation
//    de la fenetre
//
//    glutInit(&argc, argv);
//    glutInitWindowPosition(0,0);
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//    glutInitWindowSize(WIDTH,HEIGHT);
//
//
//
//    //Creation fenetre principal
//    winIdMain = glutCreateWindow("Simulation Judas Optique");
//    glEnable(GL_DEPTH_TEST);
//    glutReshapeFunc(redimensionne);
//    glutDisplayFunc(mainDisplay);
//    glutKeyboardFunc(clavier);
//    glutSpecialFunc(GestionSpecial);
//    glutMotionFunc(mMotion);
//    glutTimerFunc(17,timer, 1);
//
//    glutInitWindowPosition(610,0);
//    //Creation fenetre secondaire
//    winIdSub = glutCreateSubWindow(winIdMain,5,5,200,100);
//    glutDisplayFunc(subDisplay);
//
//    winIdMain2 = glutCreateWindow("Simulation Judas Optique");
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_AUTO_NORMAL);
//    glEnable(GL_NORMALIZE);
//    float dir[]={0.2f,0.9f,0.1f,1.0f};
//    glLightfv(GL_LIGHT0,GL_POSITION,dir);
//    glutDisplayFunc(mainDisplay2);
//    glutReshapeFunc(redimensionne);
//    glutKeyboardFunc(clavier);
//    glutSpecialFunc(GestionSpecial);
//    glutMotionFunc(mMotion);
//    glutTimerFunc(17,timer, 1);
//
//
//    //Entree dans la boucle principale glut
//    glutMainLoop();
//
//    return EXIT_SUCCESS;
//}*/
//
//void mainDisplay(void)
//{
//    /* Effacement de l'image avec la couleur de fond */
//    glutSetWindow(winIdMain);
//    glClearColor(0.0,0.0,0.0,0.0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    /* Selection / Initialisation de la matrice de transformation des objets */
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glFrustum(100,100,100,100,1,200);
//
//    /* Placement de la camera */
//    gluLookAt(cam_x,cam_y,cam_z, 0,0,0, 0,1,0);
//    glRotatef(-angley,1,0,0);
//    glRotatef(-anglex,0,1,0);
//
//    switch (systeme)
//    {
//        /* lentille */
//        case 1  :   afficher_axe_optique();
//                    afficher_objet_image();
//                    afficher_rayon();
//                    break;
//
//        /* JUDAS OPTIQUE */
//        case 2  :   afficher_mur();
//                    afficher_porte();
//                    afficher_cylindre();
//                    glScalef(0.5,0.5,0.5);
//                    afficher_system(objet1);
//                    afficher_quadrillage_modifie(objet1,10);
//                    break;
//
//        case 3  :   glTranslated(-5,0,0);
//                    afficher_lentille_menisque();
//                    afficher_lentille_biconvex1();
//                    afficher_lentille_biconcave();
//                    afficher_lentille_biconvex2();
//                    break;
//
//
//    }
//    glutSwapBuffers();
//}
//
//void mainDisplay2(void)
//{
//    /* Effacement de l'image avec la couleur de fond */
//    glutSetWindow(winIdMain2);
//    glClearColor((GLfloat) (160) / 255.0,(GLfloat) (160) / 255.0,(GLfloat) (160) / 255.0,0.0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glShadeModel(GL_SMOOTH);
//    /* Selection / Initialisation de la matrice de transformation des objets */
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//
//    /* Placement de la camera */
//    gluLookAt(cam_x,cam_y,cam_z, 0,0,0, 0,1,0);
//    glRotatef(-angley,1,0,0);
//    glRotatef(-anglex,0,1,0);
//
//    afficher_axe_optique();
//    glTranslated(1,0,0);
//    glRotated(-90,0,1,0);
//    afficher_menisque();
//
//    glutSwapBuffers();
//}
//
//void subDisplay(void)
//{
//    glutSetWindow(winIdSub);
//    glClearColor(0.25,0.25,0.25,0.0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glPushMatrix();
//    glColor3f(0,1,0);
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(-1,1);
//    glVertex2f(1,1);
//    glVertex2f(1,-1);
//    glVertex2f(-1,-1);
//    glEnd();
//    glPopMatrix();
//
//    glPushMatrix();
//    ecriture();
//    glPopMatrix();
//
//
//    glutSwapBuffers();
//}
//
//
///* Gestion du redimensionnement de la fenetre + projections de la scene */
//void redimensionne(int largeur, int hauteur)
//{
//    glViewport(0, 0, largeur, hauteur);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, largeur/(GLdouble)hauteur , 1.0, 100.);
//}
//
//
//void clavier(unsigned char touche, int x, int y)
//{
//    switch (touche)
//    {
//    case 27:  /* Les touches 'q' et Esc permettent de quitter le programme */
//    case 'q':
//        exit(EXIT_SUCCESS);
//        break;
//
//    case 's': switch(systeme)
//              {
//                case 1 :  systeme = 2;
//                            break;
//                case 2 :  systeme = 3;
//                            break;
//                case 3 :  systeme = 1;
//                            break;
//              }
//              break;
//
//    case 'f':   if(d_focal>0)
//                {
//                    d_focal=-5;
//                    calcul();
//                }
//                else
//                {
//                    d_focal = 5;
//                    calcul();
//                }
//                break;
//
//    }
//}
//
//void GestionSpecial(int key, int x, int y)
//{
//
//    switch (key)
//    {
//        case GLUT_KEY_F1 : break;
//        case GLUT_KEY_F2 : break;
//        case GLUT_KEY_F3 : break;
//        case GLUT_KEY_F4 : break;
//        case GLUT_KEY_F5 : break;
//        case GLUT_KEY_F6 : break;
//        case GLUT_KEY_F7 : break;
//        case GLUT_KEY_F8 : break;
//        case GLUT_KEY_F9 : break;
//        case GLUT_KEY_F10 : break;
//        case GLUT_KEY_F11 : break;
//        case GLUT_KEY_F12 : break;
//
//        case GLUT_KEY_LEFT :    alpha_cam +=1;
//                                if(alpha_cam >180)alpha_cam=-179;
//                                cam_x = dist_cam * cos(alpha_cam*3.14/180);
//                                cam_z = dist_cam * sin(alpha_cam*3.14/180);
//                                break;
//
//
//        case GLUT_KEY_UP :      dist_cam--;
//                                if(dist_cam <1)dist_cam=1;
//                                cam_x = dist_cam * cos(alpha_cam*3.14/180);
//                                cam_z = dist_cam * sin(alpha_cam*3.14/180);
//                                break;
//
//        case GLUT_KEY_RIGHT :   alpha_cam -=1;
//                                if(alpha_cam < -180)alpha_cam=179;
//                                cam_x = dist_cam * cos(alpha_cam*3.14/180);
//                                cam_z = dist_cam * sin(alpha_cam*3.14/180);
//                                break;
//
//        case GLUT_KEY_DOWN :    dist_cam++;
//                                if(dist_cam >100)dist_cam=100;
//                                cam_x = dist_cam * cos(alpha_cam*3.14/180);
//                                cam_z = dist_cam * sin(alpha_cam*3.14/180);
//                                break;
//
//        case GLUT_KEY_PAGE_UP : objet.x_p1+=0.1;
//                                objet.x_p2+=0.1;
//                                calcul();
//                                break;
//
//        case GLUT_KEY_PAGE_DOWN :   objet.x_p1-=0.1;
//                                    objet.x_p2-=0.1;
//                                    calcul();
//                                    break;
//
//        case GLUT_KEY_HOME :    if(ouverture_porte == 1)
//                                {
//                                    ouverture_porte = 0;
//                                }
//                                else if(ouverture_porte == 0)
//                                {
//                                    ouverture_porte = 1;
//                                }
//
//                                break;
//
//        case GLUT_KEY_END :     alpha_cam = 90;
//                                dist_cam = 50;
//                                cam_x=0;
//                                cam_z=50;
//                                anglex=0;
//                                angley=0;
//                                break;
//
//        case GLUT_KEY_INSERT : break;
//
//    }
//
//}
//
//void mMotion(int x, int y)
//{
//    anglex = anglex+(x-xold);
//    angley = angley+(y-yold);
//    xold = x;
//    yold = y;
//
//}
//
//void timer(int value)
//{
//    if(ouverture_porte == 1)
//    {
//        if(porte_ang < 90)porte_ang++;
//    }
//    else if(ouverture_porte == 0)
//    {
//        if(porte_ang >0)porte_ang--;
//    }
//
//    glutSetWindow(winIdMain);
//    glutPostRedisplay();
//    glutSetWindow(winIdMain2);
//    glutPostRedisplay();
//    glutSetWindow(winIdSub);
//    glutPostRedisplay();
//    glutTimerFunc(17,timer, 1);
//}
