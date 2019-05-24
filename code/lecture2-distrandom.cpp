// Include for advanced random numbers
#include <random>
#include <iostream>
 
int main()
{
    //Generate a random number device
    std::random_device rd;  
    //Set the standard mersenne_twister_engine
    std::mt19937 gen(rd()); 
    //Specify the interval [1,6]
    std::uniform_int_distribution<size_t> dis(1, 6);
    //Specifiy the interval [1.0,6.0]
    std::uniform_real_distribution<double> disd(1,6); 
    std::cout << dis(gen) << " " << disd(gen) << '\n';
}
