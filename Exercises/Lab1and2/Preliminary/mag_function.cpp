#include <iostream>
#include <cmath>
#include <string>

std::string input;

int main()
{   
    // input
    std::cout << "Please enter the value of x: " << std::endl;
    std::cin >> input;
    double x = std::stod(input);

    std::cout << "Please enter the value of y: " << std::endl;
    std::cin >> input;
    double y = std::stod(input);

    double mag = std::sqrt(x*x + y*y);
    std::cout << "The magnitude of the vector is " << mag << std::endl;

    return 0;
}