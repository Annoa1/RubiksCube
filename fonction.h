//#ifndef FONCTION_H_INCLUDED
//#define FONCTION_H_INCLUDED
//
//
//struct quadrillage
//{
//    int Pos_X;
//    int Pos_Y;
//    int Pos_Z;
//    int nb_ligne;
//    int longueur;
//};
//
//
//typedef struct{
//float x_p1,y_p1,z_p1,x_p2,y_p2,z_p2;
//float couleur_R,couleur_V,couleur_B;
//}obj;
//
//
//void calcul(void);
//void ecriture(void);
//void drawString(char *S);
//void afficher_axe_optique(void);
//void afficher_objet_image(void);
//void afficher_rayon(void);
//void afficher_mur(void);
//void afficher_porte(void);
//void afficher_cylindre(void);
//void afficher_sol(void);
//void afficher_menisque(void);
//void afficher_quadrillage_modifie(quadrillage q, int pos_X);
//void afficher_system(quadrillage q);
//void afficher_ligne_blanche_verticale(int X, int Y, int Z, int longueur);
//void afficher_ligne_blanche_horizontale(int X, int Y, int Z, int longueur);
//void init(void);
//void afficher_lentille_menisque(void);
//void afficher_lentille_biconvex1(void);
//void afficher_lentille_biconcave(void);
//void afficher_lentille_biconvex2(void);
//
//static GLUquadricObj* _quad;
///* Variables globales */
//int x=1,y=1,z=1;
//float cam_x=0,cam_y=0,cam_z=50,dist_cam=50,alpha_cam=90,theta_cam=0;
//int anglex =0,angley =0,anglez =0,rot_sphere=0,xold=0,yold=0;
//int pos_precedente_x=0,pos_precedente_y=0;
//float d_focal=5;
//int porte_ang=0,ouverture_porte=0;
//int systeme = 1;
//
//quadrillage objet1 = {-2, 2, 0, 10, 10};  // X Y Z - NBLIGNE - LONGUEUR
//quadrillage objet2 = {1, 1, 10, 5, 5 };
//quadrillage objet3 = {1, 1, 1, 10, 10 };
//
//obj objet={-10,0,0,-10,2,0,255,0,0};
//obj image={0,0,0,0,255,0,0};
//
//
//void calcul(void)
//{
//    image.x_p1 = 1/(1/objet.x_p1+1/d_focal);
//    image.x_p2 = 1/(1/objet.x_p2+1/d_focal);
//    image.y_p1 = objet.y_p1 * (image.x_p1/objet.x_p1);
//    image.y_p2 = objet.y_p2 * (image.x_p2/objet.x_p2);
//    image.z_p1 = objet.z_p1 * (image.x_p1/objet.x_p1);
//    image.z_p2 = objet.z_p2 * (image.x_p2/objet.x_p2);
//}
//
//void drawString(char *S)
//{
//    for(unsigned int i =0;i<strlen(S);i++)
//    {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,S[i]);
//    }
//}
//
//void ecriture(void)
//{
//
//    //float pos_ecr_x=0,pos_ecr_y=0;
//    char strMsg1[]="rotation CCW = fleche droite";
//    char strMsg2[]="rotation CW = fleche gauche";
//    char strMsg3[]="zoom  = fleche haut";
//    char strMsg4[]="dezoom = fleche bas";
//    char strMsg5[]="RAZ position = FIN";
//    char strMsg6[]="changer de figure = s";
//
//    glColor3d(1,0,0);
//    glRasterPos3f(-0.95,0.7,0);
//    drawString(strMsg1);
//
//    glRasterPos3f(-0.95,0.4,0);
//    drawString(strMsg2);
//
//    glRasterPos3f(-0.95,0.1,0);
//    drawString(strMsg3);
//
//    glRasterPos3f(-0.95,-0.2,0);
//    drawString(strMsg4);
//
//    glRasterPos3f(-0.95,-0.5,0);
//    drawString(strMsg5);
//
//    glRasterPos3f(-0.95,-0.8,0);
//    drawString(strMsg6);
//}
//
//void afficher_rayon(void)
//{
//
//    glPushMatrix();
//    glBegin(GL_LINE_STRIP);
//    glColor3f(0,1 ,0);
//    glVertex3f(objet.x_p2, objet.y_p2, objet.z_p2);
//    glVertex3f(0, objet.y_p2, 0);
//    glVertex3f(image.x_p2, image.y_p2, image.z_p2);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(0,1 ,0);
//    glVertex3f(objet.x_p2, objet.y_p2, objet.z_p2);
//    glVertex3f(image.x_p2, image.y_p2, image.z_p2);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(0,1 ,0);
//    glVertex3f(objet.x_p2, objet.y_p2, objet.z_p2);
//    glVertex3f(0, image.y_p2, 0);
//    glVertex3f(image.x_p2, image.y_p2, image.z_p2);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(0,0 ,1);
//    glVertex3f(objet.x_p1, objet.y_p1, objet.z_p1);
//    glVertex3f(0, objet.y_p1, 0);
//    glVertex3f(image.x_p1, image.y_p1, image.z_p1);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(0,0 ,1);
//    glVertex3f(objet.x_p1, objet.y_p1, objet.z_p1);
//    glVertex3f(image.x_p1, image.y_p1, image.z_p1);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(0,0 ,1);
//    glVertex3f(objet.x_p1, objet.y_p1, objet.z_p1);
//    glVertex3f(0, image.y_p1, 0);
//    glVertex3f(image.x_p1, image.y_p1, image.z_p1);
//    glEnd();
//
//    glPopMatrix();
//}
//
//void afficher_objet_image(void)
//{
////----------- OBJET --------------//
//    glPushMatrix();
//    glBegin(GL_LINES);
//    glColor3f(objet.couleur_R, objet.couleur_V, objet.couleur_B);
//    glVertex3f(objet.x_p1, objet.y_p1, objet.z_p1);
//    glVertex3f(objet.x_p2, objet.y_p2, objet.z_p2);
//    glEnd();
//    glPopMatrix();
////----------- IMAGE --------------//
//
//    glPushMatrix();
//    glBegin(GL_LINES);
//    glColor3f(objet.couleur_R, objet.couleur_V, objet.couleur_B);
//    glVertex3f(image.x_p1, image.y_p1, image.z_p1);
//    glVertex3f(image.x_p2, image.y_p2, image.z_p2);
//    glEnd();
//    glPopMatrix();
//}
//
//void afficher_axe_optique(void)
//{
//    glPushMatrix();
//
//    glBegin(GL_LINES);
//    glColor3f(1, 1, 0);
//    glVertex3i(0, -5, 0);
//    glVertex3i(0, 5, 0);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(1, 1, 0);
//    glVertex3i(-1, 4, 0);
//    glVertex3i(0, 5, 0);
//    glVertex3i(1, 4, 0);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(1, 1, 0);
//    glVertex3i(-1, -4, 0);
//    glVertex3i(0, -5, 0);
//    glVertex3i(1,-4, 0);
//    glEnd();
//
//    glBegin(GL_LINES);
//    glColor3f(1, 1, 1);
//    glVertex3i(-30, 0, 0);
//    glVertex3i(30, 0, 0);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glColor3f(1, 1, 1);
//    glVertex3i(29, 1, 0);
//    glVertex3i(30, 0, 0);
//    glVertex3i(29, -1, 0);
//    glEnd();
//
//    glPopMatrix();
//}
//
//void afficher_mur(void)
//{
//    glPushMatrix();
//
//    glBegin(GL_QUADS);
//    glColor3f(255, 0, 0);
//    glVertex3f(0.5, 0, 6);
//    glVertex3f(0.5, 6, 6);
//    glVertex3f(0.5, 6, 2);
//    glVertex3f(0.5, 0, 2);
//    glVertex3f(-0.5, 0, 6);
//    glVertex3f(-0.5, 6, 6);
//    glVertex3f(-0.5, 6, 2);
//    glVertex3f(-0.5, 0, 2);
//    glVertex3f(0.5, 0, 2);
//    glVertex3f(0.5, 6, 2);
//    glVertex3f(-0.5, 6, 2);
//    glVertex3f(-0.5, 0, 2);
//    glVertex3f(0.5, 0, 6);
//    glVertex3f(0.5, 6, 6);
//    glVertex3f(-0.5, 6, 6);
//    glVertex3f(-0.5, 0, 6);
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(255, 0, 0);
//    glVertex3f(0.5, 0, -6);
//    glVertex3f(0.5, 6, -6);
//    glVertex3f(0.5, 6, -2);
//    glVertex3f(0.5, 0, -2);
//    glVertex3f(-0.5, 0, -6);
//    glVertex3f(-0.5, 6, -6);
//    glVertex3f(-0.5, 6, -2);
//    glVertex3f(-0.5, 0, -2);
//    glVertex3f(0.5, 0, -2);
//    glVertex3f(0.5, 6, -2);
//    glVertex3f(-0.5, 6, -2);
//    glVertex3f(-0.5, 0, -2);
//    glVertex3f(0.5, 0, -6);
//    glVertex3f(0.5, 6, -6);
//    glVertex3f(-0.5, 6, -6);
//    glVertex3f(-0.5, 0, -6);
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(255, 0, 0);
//    glVertex3f(0.5, 4, -2);
//    glVertex3f(0.5, 6, -2);
//    glVertex3f(0.5, 6, 2);
//    glVertex3f(0.5, 4, 2);
//    glVertex3f(-0.5, 4, -2);
//    glVertex3f(-0.5, 6, -2);
//    glVertex3f(-0.5, 6, 2);
//    glVertex3f(-0.5, 4, 2);
//    glVertex3f(0.5, 4, -2);
//    glVertex3f(0.5, 4, 2);
//    glVertex3f(-0.5, 4, 2);
//    glVertex3f(-0.5, 4, -2);
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glColor3f(255, 0, 0);
//    glVertex3f(0.5, 6, -6);
//    glVertex3f(0.5, 6, 6);
//    glVertex3f(-0.5, 6, 6);
//    glVertex3f(-0.5, 6, -6);
//    glEnd();
//
//
//    glPopMatrix();
//}
//
//void afficher_porte(void)
//{
//    glPushMatrix();
//    glTranslated(0.5,0,-2);
//    glRotated(porte_ang,0,1,0);
//
//    glBegin(GL_QUADS);
//    glColor3f(0.65, 0.5, 0.39);
//    glVertex3f(0, 0, 0);
//    glVertex3f(0, 0, 4);
//    glVertex3f(0, 4, 4);
//    glVertex3f(0, 4, 0);
//    glVertex3f(-1, 0, 0);
//    glVertex3f(-1, 0, 4);
//    glVertex3f(-1, 4, 4);
//    glVertex3f(-1, 4, 0);
//    glVertex3f(0, 4, 0);
//    glVertex3f(0, 4, 4);
//    glVertex3f(-1, 4, 4);
//    glVertex3f(-1, 4, 0);
//    glVertex3f(0, 0, 4);
//    glVertex3f(0, 4, 4);
//    glVertex3f(-1, 4, 4);
//    glVertex3f(-1, 0, 4);
//    glVertex3f(0, 0, 0);
//    glVertex3f(0, 0, 4);
//    glVertex3f(-1, 0, 4);
//    glVertex3f(-1, 0, 0);
//    glEnd();
//
//
//
//    glPopMatrix();
//}
//
//void afficher_cylindre(void)
//{
//    glPushMatrix();
//    glTranslated(0.5,1,-2);
//    glRotated(90,1,0,0);
//    glColor3f(0.8, 0.498, 0.196);
//    gluCylinder(_quad,0.1,0.1,0.8,10,10);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0.5,3.5,-2);
//    glRotated(90,1,0,0);
//    glColor3f(0.8, 0.498, 0.196);
//    gluCylinder(_quad,0.1,0.1,0.8,10,10);
//    glPopMatrix();
//}
//
//void afficher_sol(void)
//{
//    glPushMatrix();
//    glBegin(GL_QUADS);
//    glColor3f(0, 1, 0);
//    glVertex3f(-20, 0, -20);
//    glVertex3f(-20, 0, 20);
//    glVertex3f(20, 0, 20);
//    glVertex3f(20, 0, -20);
//    glEnd();
//    glPopMatrix();
//}
//
//void init(void)
//{
//    calcul();
//    _quad = gluNewQuadric();
//}
//
//void afficher_menisque(void)
//{
//    double Rs,e=2,Rl=3;
//    double D;
//    double clip_plane11[]={0,0,1,0};
//    double clip_plane1[]={0,0,1,0};
//
//    Rs = ((e * e) + (Rl * Rl)) / e;
//    D = Rs - (e/2);
//
//    glPushMatrix();
//    glColor3ub(131,242,227);
//    gluCylinder(_quad,Rl+0.4,Rl+0.4,2,20,20);
//    glPopMatrix();
//
//    glPushMatrix();
//    glClipPlane(GL_CLIP_PLANE1,clip_plane11);
//    glEnable(GL_CLIP_PLANE1);
//    glColor4ub(131,242,227,255);
//    glTranslated (0,0,-D);
//    GLUquadric* qd1=gluNewQuadric();
//    gluSphere(qd1,Rs,20,20);
//    gluDeleteQuadric(qd1);
//    glDisable(GL_CLIP_PLANE1);
//    glTranslated (0,0,D);
//    glTranslated(0,0,2);
//    glClipPlane(GL_CLIP_PLANE1,clip_plane1);
//    glEnable(GL_CLIP_PLANE1);
//    glTranslated (0,0,-D);
//    GLUquadric* qd=gluNewQuadric();
//    gluSphere(qd,Rs,20,20);
//    gluDeleteQuadric(qd);
//    glDisable(GL_CLIP_PLANE1);
//    glTranslated (0,0,D);
//    glPopMatrix();
//
//
//}
//
//void afficher_quadrillage_modifie(quadrillage q, int pos_X)
//{
//    float Y_new_position=0, Z_new_position=0;
//    float ya = q.Pos_Y + (q.nb_ligne/2)-1, za = q.Pos_Z+(q.longueur/2)-1;    //centre objet
//    float Y_actuel= 0, Z_actuel= 0;
//    float r = 0.15;
//
//        for(int i=0; i<q.nb_ligne; i++) //  verticales
//        {
//            glBegin(GL_LINE_STRIP);
//            for(int j=0; j<q.longueur; j++)
//            {
//                Y_actuel = q.Pos_Y+i;
//                Z_actuel=q.Pos_Z+j;
//
//                if(Y_actuel>=ya && Z_actuel>=za) //
//                {
//                    Y_new_position = (Y_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                if(Y_actuel>=ya && Z_actuel<=za)
//                {
//                    Y_new_position = (Y_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                if(Y_actuel<=ya && Z_actuel<=za)
//                {
//                    Y_new_position = (Y_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                if(Y_actuel<=ya && Z_actuel>=za)
//                {
//                    Y_new_position = (Y_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                glVertex3f(pos_X ,Y_new_position ,Z_new_position);
//            }
//            glEnd();
//        }
//
//        for(int j=0; j<q.longueur; j++) // Lignes horizontales
//        {
//            glBegin(GL_LINE_STRIP);
//            for(int i=0; i<q.nb_ligne; i++)
//            {
//                Y_actuel = q.Pos_Y+i;
//                Z_actuel=q.Pos_Z+j;
//
//                if(Y_actuel>=ya && Z_actuel>=za) //
//                {
//                    Y_new_position = (Y_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                if(Y_actuel>=ya && Z_actuel<=za)
//                {
//                    Y_new_position = (Y_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                if(Y_actuel<=ya && Z_actuel<=za)
//                {
//                    Y_new_position = (Y_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//                if(Y_actuel<=ya && Z_actuel>=za)
//                {
//                    Y_new_position = (Y_actuel) + (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * cos(atan((Z_actuel)/(Y_actuel))));
//                    Z_new_position= (Z_actuel) - (pow(r*sqrt(((Y_actuel)-ya) * ((Y_actuel)-ya) + ((Z_actuel)-za) * ((Z_actuel)-za)),3) * sin(atan((Z_actuel)/(Z_actuel))));
//                }
//
//
//                glVertex3f(pos_X ,Y_new_position ,Z_new_position);
//            }
//            glEnd();
//        }
//}
//
//void afficher_system(quadrillage q)
//{
//
//
//    for(int i=0; i<q.nb_ligne ; i++)// Cadrillage initiale
//    {
//       afficher_ligne_blanche_verticale(q.Pos_X, q.Pos_Y+i, q.Pos_Z, q.longueur);
//    }
//
//
//
//   // LIGNES HORIZONTALES
//     for(int i=0; i<q.longueur;i++) // LIGNES HORIZONTALES
//    {
//        afficher_ligne_blanche_horizontale(q.Pos_X, q.Pos_Y, q.Pos_Z+i, q.nb_ligne);
//    }
//
//}
//
//void afficher_ligne_blanche_verticale(int X, int Y, int Z, int longueur)
//{
//    glColor3f(256,256,256);
//
//    glBegin(GL_LINE_STRIP); // Création plan original
//    for(int i=0; i<longueur ; i++)
//    {
//       glVertex3f(X,Y,Z+i);
//    }
//    glEnd();
//}
//
//void afficher_ligne_blanche_horizontale(int X, int Y, int Z, int longueur)
//{
//    glColor3f(256,256,256);
//
//    glBegin(GL_LINE_STRIP);
//    for(int i=0; i<longueur ; i++)
//    {
//       glVertex3f(X,Y+i,Z);
//    }
//    glEnd();
//
//}
//
////------------------------------------------------------------------//
//void afficher_lentille_menisque(void)
//{
//    float x;
//    float i;
//    float R11=17.5,R12=6.35,e1=0.5;
//    glPushMatrix();
//    glTranslated(12,0,0);
//    glBegin(GL_LINE_LOOP);
//
//    for(i=10;i>=-10;i-=0.05)
//    {
//        x=-sqrtf(powf(R11,2)-powf(i,2));
//        glVertex2f(x,i);
//    }
//
//    x=(-sqrtf(powf(R12,2)-powf(R12,2))+(R12-R11+e1));
//    glVertex2f(x,-10);
//
//    for(i=-R12;i<=R12;i+=0.05)
//    {
//        x=-sqrtf(powf(R12,2)-powf(i,2))+(R12-R11+e1);
//        glVertex2f(x,i);
//    }
//    glVertex2f(x,10);
//    glEnd();
//    glPopMatrix();
//
//
//}
//
//void afficher_lentille_biconvex1(void)
//{
//    float x;
//    float i;
//    float R21=48.1,R22=8.31,e2=1;
//
//    glPushMatrix();
//    glTranslatef(48.1+0.5+3.3,0,0);
//    glBegin(GL_LINE_LOOP);
//
//    for(i=10;i>=-10;i-=0.05)
//    {
//        x=-sqrtf(powf(R21,2)-powf(i,2));
//        glVertex2f(x,i);
//    }
//
//    x=(sqrtf(powf(R22,2)-powf(R22,2))+(R22-R21+e2));
//    glVertex2f(x,-10);
//
//    for(i=-R22;i<=R22;i+=0.05)
//    {
//        x=sqrtf(powf(R22,2)-powf(i,2))+(R22-R21+e2);
//        glVertex2f(x,i);
//    }
//    glVertex2f(x,10);
//
//    glEnd();
//
//    glPopMatrix();
//}
//
//void afficher_lentille_biconcave(void)
//{
//    float x;
//    float i;
//    float R21=8.31,R22=3.62,e2=0.7;
//
//    glPushMatrix();
//    glTranslated(11+3.3+1+0.1,0,0);
//    glBegin(GL_LINE_LOOP);
//
//    for(i=R21;i>=-R21;i-=0.05)
//    {
//        x=sqrtf(pow(R21,2)-powf(i,2));
//        glVertex2f(x,i);
//    }
//
//    x=(-sqrtf(powf(R22,2)-powf(R22,2))-(R22-R21-e2-8));
//    glVertex2f(x,-R21);
//
//    for(i=-R22;i<=R22;i+=0.05)
//    {
//        x=-sqrtf(powf(R22,2)-powf(i,2))-(R22-R21-e2-8);
//        glVertex2f(x,i);
//    }
//    glVertex2f(x,R21);
//
//    glEnd();
//
//    glPopMatrix();
//}
//
//void afficher_lentille_biconvex2(void)
//{
//    float x;
//    float i;
//    float R21=3.6,R22=15.7,e2=1.4;
//
//    glPushMatrix();
//    glTranslatef(3.6+0.5+3.3+22,0,0);
//    glBegin(GL_LINE_LOOP);
//
//    for(i=R21;i>=-R21;i-=0.05)
//    {
//        x=-sqrtf(powf(R21,2)-powf(i,2));
//        glVertex2f(x,i);
//    }
//
//    x=(sqrtf(powf(R22,2)-powf(-10,2))+(R22-R21+e2-25));
//    glVertex2f(x,-R21);
//
//    for(i=-10;i<=10;i+=0.05)
//    {
//        x=sqrtf(powf(R22,2)-powf(i,2))+(R22-R21+e2-25);
//        glVertex2f(x,i);
//    }
//    glVertex2f(x,R21);
//
//    glEnd();
//
//    glPopMatrix();
//}
//
//
//#endif // FONCTION_H_INCLUDED
