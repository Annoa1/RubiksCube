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
    protected:
    private:
        int face[NBFACES][NBCOL][NBCOL];
};

#endif // CUBE_H
