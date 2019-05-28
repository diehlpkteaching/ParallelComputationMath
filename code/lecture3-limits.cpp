#include <limits>
#include <iostream>
 
int main() 
{
  std::cout << "type\tmin()\t\tmax()\n";
  std::cout << "int\t"
    << std::numeric_limits<unsigned int>::min() << '\t'
    << std::numeric_limits<unsigned int>::max() << '\n';
  std::cout << "int\t"
    << std::numeric_limits<int>::min() << '\t'
    << std::numeric_limits<int>::max() << '\n';
}
