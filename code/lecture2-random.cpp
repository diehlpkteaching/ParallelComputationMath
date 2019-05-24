// Include for using rand
#include <cstdlib>
#include <iostream>
//Include for getting the current time
#include <ctime>
 
int main() 
{
    // Use the current time as random seed
    std::srand(std::time(0)); 
    // Get one random number
    int random_variable = std::rand();
    std::cout 
        << "Random value on [0 " << RAND_MAX << "]: " 
        << random_variable << '\n';
}
