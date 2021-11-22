#include <iostream>

int main(int n, char** args)
{
    double * pointer = new double[5];
    std::cout << pointer[6] << std::endl;
    return 0;
}
