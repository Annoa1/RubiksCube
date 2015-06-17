/*!
 * \file src\Cube.cpp
 * \brief Fonctions associees a la classe Cube
 * \author Groupe 8
 * \version 1.0
 */


#include "Cube.h"

Cube::Cube()
{
    //initialisation du Cube
    for(int i=0; i<NBFACES; i++) {
        for(int j=0; j<NBCOL; j++) {
            for(int k=0; k<NBCOL; k++) {
                face[i][j][k] = i;
            }
        }
    }
    //ctor
}

void Cube::afficher() {

    //affichage de la face 1
    for(int i=0; i<NBCOL; i++) {
        for(int j=0; j<NBCOL; j++) {
            cout << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << face[0][i][j] << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //affichage des trois faces alignées
    for(int i=0; i<NBCOL; i++) {
        for(int j=0; j<NBCOL; j++) {
            cout << face[1][i][j] << "\t";;
        }
        for(int j=0; j<NBCOL; j++) {
            cout << face[2][i][j] << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << face[3][i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //affichage des deux dernières
    for(int i=0; i<NBCOL; i++) {
        for(int j=0; j<NBCOL; j++) {
            cout << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << face[4][i][j] << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for(int i=0; i<NBCOL; i++) {
        for(int j=0; j<NBCOL; j++) {
            cout << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << face[5][i][j] << "\t";
        }
        for(int j=0; j<NBCOL; j++) {
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "-\t-\t-\t-\t-\t-\t-\t-\t-\t" << endl;
}

void Cube::rotation(int numface, int sens) {
    int faceTemp[NBCOL][NBCOL];
    //on retourne toutes les case de la face
    if(sens == 1) {
        for(int i=0; i<NBCOL; i++) {
            for(int j=0; j<NBCOL; j++) {
                faceTemp[j][NBCOL-i-1] = face[numface][i][j];
            }
        }
    }
    else  {
        for(int i=0; i<NBCOL; i++) {
            for(int j=0; j<NBCOL; j++) {
                faceTemp[i][j] = face[numface][j][NBCOL-i-1];
            }
        }
    }

    for(int i=0; i<NBCOL; i++) {
        for(int j=0; j<NBCOL; j++) {
            face[numface][i][j] = faceTemp[i][j];
        }
    }


    //puis on tourne les voisins
    switch(numface) {
    case 0 :
        //Ses voisins sont 1, 2, 3, et 5
        if(sens == 1) {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[1][0][i];
                face[1][0][i] = face[2][0][i];
                face[2][0][i] = face[3][0][i];
                face[3][0][i] = face[5][NBCOL-1][i];
                face[5][NBCOL-1][i] = ligneTemp[i];
            }
        }
        else {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[1][0][i];
                face[1][0][i] = face[5][NBCOL-1][i];
                face[5][NBCOL-1][i] = face[3][0][i];
                face[3][0][i] = face[2][0][i];
                face[2][0][i] = ligneTemp[i];
            }
        }
        break;
    case 1 :
        //Ses voisins sont : 0, 2, 4, 6
        if(sens == 1) {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[0][i][0];
                face[0][i][0] = face[5][i][0];
                face[5][i][0] = face[4][i][0];
                face[4][i][0] = face[2][i][0];
                face[2][i][0] = ligneTemp[i];
            }
        }
        else {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[2][i][0];
                face[2][i][0] = face[4][i][0];
                face[4][i][0] = face[5][i][0];
                face[5][i][0] = face[0][i][0];
                face[0][i][0] = ligneTemp[i];
            }
        }
        break;
    case 2 :
        //Ses voisins sont 0, 1, 3, et 4
        if(sens == 1) {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[0][NBCOL-1][i];
                face[0][NBCOL-1][i] = face[1][NBCOL-i-1][NBCOL-1];
                face[1][NBCOL-i-1][NBCOL-1] = face[4][0][NBCOL-i-1];
                face[4][0][NBCOL-i-1] = face[3][i][0];
                face[3][i][0] = ligneTemp[i];
            }
        }
        else {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[3][i][0];
                face[3][i][0] = face[4][0][NBCOL-i-1];
                face[4][0][NBCOL-i-1] = face[1][NBCOL-i-1][NBCOL-1];
                face[1][NBCOL-i-1][NBCOL-1] = face[0][NBCOL-1][i];
                face[0][NBCOL-1][i] = ligneTemp[i];
            }
        }
        break;
    case 3 :
        //Ses voisins sont : 0, 2, 4, 6
        if(sens == 1) {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[0][i][NBCOL-1];
                face[0][i][NBCOL-1] = face[5][i][NBCOL-1];
                face[5][i][NBCOL-1] = face[4][i][NBCOL-1];
                face[4][i][NBCOL-1] = face[2][i][NBCOL-1];
                face[2][i][NBCOL-1] = ligneTemp[i];
            }
        }
        else {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[2][i][NBCOL-1];
                face[2][i][NBCOL-1] = face[4][i][NBCOL-1];
                face[4][i][NBCOL-1] = face[5][i][NBCOL-1];
                face[5][i][NBCOL-1] = face[0][i][NBCOL-1];
                face[0][i][NBCOL-1] = ligneTemp[i];
            }
        }
        break;
    case 4 :
        //Ses voisins sont : 1, 2, 3, 6
        if(sens == 1) {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[1][NBCOL-1][i];
                face[1][NBCOL-1][i] = face[2][NBCOL-1][i];
                face[2][NBCOL-1][i] = face[3][NBCOL-1][i];
                face[3][NBCOL-1][i] = face[6][0][i];
                face[6][0][i] = ligneTemp[i];
            }
        }
        else {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[6][0][i];
                face[6][0][i] = face[3][NBCOL-1][i];
                face[3][NBCOL-1][i] = face[2][NBCOL-1][i];
                face[2][NBCOL-1][i] = face[1][NBCOL-1][i];
                face[1][NBCOL-1][i] = ligneTemp[i];
            }
        }
        break;
    case 5 :
        //Ses voisins sont 0, 1, 3, et 4
        if(sens == 1) {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[0][0][i];
                face[0][0][i] = face[1][NBCOL-i-1][0];
                face[1][NBCOL-i-1][0] = face[4][NBCOL-1][NBCOL-i-1];
                face[4][NBCOL-1][NBCOL-i-1] = face[3][i][NBCOL-1];
                face[3][i][NBCOL-1] = ligneTemp[i];
            }
        }
        else {
            int ligneTemp[NBCOL];
            for(int i=0; i<NBCOL; i++) {
                ligneTemp[i] = face[3][i][NBCOL-1];
                face[3][i][NBCOL-1] = face[4][NBCOL-1][NBCOL-i-1];
                face[4][NBCOL-1][NBCOL-i-1] = face[1][NBCOL-i-1][0];
                face[1][NBCOL-i-1][0] = face[0][0][i];
                face[0][0][i] = ligneTemp[i];
            }
        }
        break;

    }
}


Cube::~Cube()
{
    //dtor
}
