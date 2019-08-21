// Read person's name and greet the person
#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";
    // Read the name
    std::string name;
    std::cin >> name;
    // Intention
    const std::string greeting = "Hi, " + name + "!";
    const size_t pad = 1;
    const size_t rows = pad * 2 + 3;
    const std::string::size_type cols = greeting.size() + pad * 2 + 2;
    // Writing 
    std::cout << std::endl;
    for(size_t r = 0; r != rows; r++){
        std::string::size_type c = 0;
        while (c != cols ) {
            if ( r == pad + 1 && c == pad + 1){
                std::cout << greeting;
                c += greeting.size();
            }
            else{
                if( r == 0 || r == rows -1 || c == 0 || c == cols - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
                ++c;
           }
            
    }
std::cout << std::endl;
}
    return 0;
}

