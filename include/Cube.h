#ifndef CUBE_H
#define CUBE_H

#include <iostream>

#define NBFACES 6
#define NBCOL 3

using namespace std;
class Cube
{
    public:
        Cube();
        void afficher();
        virtual ~Cube();
        void rotation(int face, int sens);
        int face[NBFACES][NBCOL][NBCOL];
    protected:
    private:

};

#endif // CUBE_H
