#include <iostream>

int main(int n, char** args)
{
    double * pointer = new double(2);
    std::cout << *pointer << std::endl;
    delete [] pointer;
    return 0;
}
