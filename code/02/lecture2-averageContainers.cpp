#include <iostream>
#include <vector>
#include <numeric>

int main()
{
std::vector<double> values;
double x;
    while (std::cin >> x)
    {
        values.push_back(x);
    }
double sum = 
    std::accumulate(values.begin(), values.end(), 0.0f);
std::cout << "Average: "
    << sum / values.size() << std::endl;
}
