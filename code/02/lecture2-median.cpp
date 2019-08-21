#include <iostream>
#include <vector>
#include <algorithm>

int main(){
typedef std::vector<double>::size_type vec_sz;
std::vector<double> values;
double x;
    while (std::cin >> x)
    {
        values.push_back(x);
    }
std::sort(values.begin(),values.end());
vec_sz mid = values.size() / 2;
double median = values.size() % 2 == 0 ? 
    0.5*(values[mid]+values[mid-1]) : values[mid];
std::cout << "Median: "
    << median << std::endl;
}
