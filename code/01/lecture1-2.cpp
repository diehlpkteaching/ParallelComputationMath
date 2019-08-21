// Read person's name and greet the person
#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";
    // Read the name
    std::string name;
    std::cin >> name;
    // Writing the name
    std::cout << "Hi, " << name << "!" << std::endl;
    return 0;
}
