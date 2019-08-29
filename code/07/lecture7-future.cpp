#include<future>
#include<iostream>

int compute(int data){

return data * 2;

}

int main(void){

int P,X = 1;


std::future<int> f1 = std::async(compute,P);
auto f2 = std::async(compute,X);

std::cout << compute(f1.get() + f2.get()) << std::endl;

return EXIT_SUCCESS;

}

