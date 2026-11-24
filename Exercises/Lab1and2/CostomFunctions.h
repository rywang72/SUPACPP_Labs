#pragma once
#include<string>
#include<vector>

//declare global variables
extern std::string inputfile;
extern std::vector<std::vector<double>> data;
extern std::vector<double> data_mag;

//declare functions
void read_input(std::string);
void print_input(std::vector<std::vector<double>>);
void print_output(std::string, std::string);
void print_output(std::vector<double>, std::string);
double magnitude(double, double);
std::string fitting(std::string);