#include <limits>
#include <iostream>
 
int main() 
{
  std::cout << "type\tround()\teps\tmin()\t\tmax()\n";
  std::cout << "double\t"
    << std::numeric_limits<double>::round_error() <<'\t'
    << std::numeric_limits<double>::epsilon() <<'\t'
    << std::numeric_limits<double>::min() <<'\t'
    << std::numeric_limits<double>::max() <<'\n';
}  


