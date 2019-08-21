#include <iostream>
#include <iomanip>

int main()
{
double sum = 0;
size_t count = 0;
double x = 0;
    while (std::cin >> x)
    {
        sum += x;
        ++count;
    }
std::cout << "Average: " 
    << std::setprecision(3) 
    << sum / count << std::endl;
}
