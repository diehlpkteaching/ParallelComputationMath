#include <vector>
#include <algorithm>
#include <iostream>
#include <execution>

void print(int i)
{
std::cout << i << std::endl;
}

int main(){

    std::vector<int> nums(1000000,0);
 
    //std::for_each(nums.begin(), nums.end(), print);

    std::for_each(std::execution::par_unseq,nums.begin(), nums.end(), print);

    return 0; 
}
