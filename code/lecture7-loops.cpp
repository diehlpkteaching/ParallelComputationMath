#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <execution>
#include <numeric>

int main(){


    std::vector<double> nums(900000000,0);

    {
    auto t1 = std::chrono::high_resolution_clock::now();
    auto result = std::accumulate(nums.begin(), nums.end(), 0.0);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
    std::cout << std::fixed << "std::accumulate result " << result
              << " took " << ms.count() << " ms\n";
    }

    {
    auto t1 = std::chrono::high_resolution_clock::now();
    auto result = std::reduce(
                    std::execution::par,
                    nums.begin(), nums.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
    std::cout << "std::reduce result "
              << result << " took " << ms.count() << " ms\n";
    }

    return 0; 
}
