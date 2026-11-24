#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CostomFunctions.h"


//define variables
std::string inputfile_data = "input2D_float.txt";
std::string inputfile_errors = "error2D_float.txt";
std::vector<std::vector<double>> data;
std::vector<double> data_mag, x_pow_y;


////Main
int main(){   
    data = read_input(inputfile_data);

    while(true){  //runs until return 0
        //ask user which option they'd like
        std::cout << "Which function would you like to use?" << std::endl;
        std::cout << "1. Print the first N lines of data;" << std::endl;
        std::cout << "2. Calculate the magnitude of the position vector of each data point;" << std::endl;
        std::cout << "3. Fit a straight line to the data points using least squares method;" << std::endl;
        std::cout << "4. Calculate x^y of each data point;" << std::endl;
        std::cout << "5. Exit;" << std::endl;
        std::cout << "Please choose a number from action 1 to 5:" << std::endl;
        std::string input;
        std::cin >> input;
        int option = std::stoi(input);

        switch (option){
            case 1:{ //print the data
                print_input(data);
                break;
            }

            case 2:{ //calculate and print the magnitudes
                std::cout << "Magnitude of the position vectors:" << std::endl;
                for (int i=0; i<data.size(); i++){
                    double mag = magnitude(data[i][0], data[i][1]);
                    data_mag.push_back(mag);
                }
                print_output(data_mag, "Outputs/magnitudes.txt");
                break;
            }

            case 3:{ //least square method fitting
                std::ofstream clear_file("Outputs/least_square_fit.txt", std::ios::trunc);  //clear output file for this run
                
                std::vector<std::string> results = fitting(inputfile_data, inputfile_errors);
                std::cout << "Fit result from least square method:" << std::endl;
                print_output(results[0], "Outputs/least_square_fit.txt");
                std::cout << "Chi square test for y values:" << std::endl;
                print_output(results[1], "Outputs/least_square_fit.txt");
                break;
            }

            case 4:{
                std::cout << "Value of x^y of each point:" << std::endl;
                for (int i=0; i<data.size(); i++){
                    double xi_pow_yi = RecursiveMultiplier(data[i][0], data[i][1]);
                    x_pow_y.push_back(xi_pow_yi);
                }
                print_output(x_pow_y, "Outputs/x_power_y.txt");
                break;
            }

            case 5:{
                std::cout << "Exiting..." << std::endl;
                return 0;
            }
        }
    }

    return 0;
}