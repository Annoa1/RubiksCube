#include "fonction.h"

void calcul(void)
{
    image.x_p1 = 1/(1/objet.x_p1+1/d_focal);
    image.x_p2 = 1/(1/objet.x_p2+1/d_focal);
    image.y_p1 = objet.y_p1 * (image.x_p1/objet.x_p1);
    image.y_p2 = objet.y_p2 * (image.x_p2/objet.x_p2);
    image.z_p1 = objet.z_p1 * (image.x_p1/objet.x_p1);
    image.z_p2 = objet.z_p2 * (image.x_p2/objet.x_p2);
}
