#include<iostream>


int main(int argc, char** argv)
{
   std::cout << argc << " argument(s)" << std::endl;
   
   for (size_t i = 0; i < argc ; i++)
   {
	std::cout << argv[i] << std::endl;
   }

   return EXIT_SUCCESS;
}
