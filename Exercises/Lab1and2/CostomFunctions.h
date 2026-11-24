#pragma once
#include<string>
#include<vector>

// Declare functions
//input and output
std::vector<std::vector<double>> read_input(std::string);
void print_input(std::vector<std::vector<double>>);
void print_output(std::string, std::string);
void print_output(std::vector<double>, std::string);

//calculations
double magnitude(double, double);
std::vector<std::string> fitting(std::string, std::string);
double chi_square_test(double, double, std::vector<std::vector<double>>, std::vector<std::vector<double>>);
double RecursiveMultiplier(double, double);
