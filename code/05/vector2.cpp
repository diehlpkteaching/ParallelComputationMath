#include "vector2.h"
#include <cmath>

vector2::vector2(double x, double y, double z) 
{
    this->x = x;
    this->y = y;
    this->z = z;
}


double vector2::norm(){

    return std::sqrt(x*x+y*y+z*z);
}
