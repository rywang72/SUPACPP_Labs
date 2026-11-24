#include <iostream>
#include <cmath>
#include <vector>

double x = 7.5;
double y = 3.4;

int main()
{
    std::vector<double> k = {x, y};
    double mag = std::sqrt(x*x + y*y);
    std::cout << "The magnitude of the vector is " << mag << std::endl;

    return 0;
}

