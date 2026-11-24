#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CostomFunctions.h"


//define global variables
std::string inputfile_data = "input2D_float.txt";
std::string inputfile_errors = "error2D_float.txt";
std::vector<std::vector<double>> data;
std::vector<double> data_mag;


////Main
int main(){   
    //ask user which option they'd like
    std::cout << "Which function would you like to use?" << std::endl;
    std::cout << "1. Print the first N lines of data;" << std::endl;
    std::cout << "2. Print the magnitude of every data point;" << std::endl;
    std::cout << "3. Fit a straight line to the data using least squares method;" << std::endl;
    std::cout << "Please choose 1, 2, or 3:" << std::endl;
    std::string input;
    std::cin >> input;
    int option = std::stoi(input);


    switch (option){
        case 1:{ //print the data
            data = read_input(inputfile_data);
            print_input(data);
            break;
        }

        case 2:{ //calculate and print the magnitudes
            data = read_input(inputfile_data);
            std::cout << "Magnitude of the input vectors:" << std::endl;
            for (int i=0; i<data.size(); i++){
                double mag = magnitude(data[i][0], data[i][1]);
                data_mag.push_back(mag);
            }
            print_output(data_mag, "Outputs/magnitudes.txt");
            break;
        }

        case 3:{ //least square method fitting
            std::vector<std::string> results = fitting(inputfile_data, inputfile_errors);
            std::ofstream clear_file("Outputs/least_square_fit.txt", std::ios::trunc);  //clear output file for this run
            std::cout << "Fit result from least square method:" << std::endl;
            print_output(results[0], "Outputs/least_square_fit.txt");
            std::cout << "Chi square test for y values:" << std::endl;
            print_output(results[1], "Outputs/least_square_fit.txt");
            // Need to change output structure
            break;
        }

    }

    return 0;
}