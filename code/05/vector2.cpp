#include "vector2.h"
#include <cmath>

vector2::vector2(double x, double y, double z) 
{
    x = x;
    x = y;
    z = z;
}


double vector2::norm(){

    return std::sqrt(x*x+y*y+z*z);
}
