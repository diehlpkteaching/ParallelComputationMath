#include <iostream>

double * func(int i){

    return new double(i);
}

int main(int n, char** args)
{

    double* value = func(0);
    delete value;
}
