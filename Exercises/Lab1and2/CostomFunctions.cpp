#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "CostomFunctions.h"


// Input and output
void read_input(std::string inputfile){   
    std::string line;

    //assuming the input file is under the same directory
    std::ifstream data_file(inputfile);

    //raise error if unable to open
    if (!data_file.is_open()) {
        std::cout << "Error occurs at opening the file: " << inputfile << std::endl;
        std::cout << "Empty input data returned!" << std::endl;
        return;
    } 

    //read the file
    std::getline(data_file, line);  //discard the first line
    while(std::getline(data_file, line)){
        //turn each line to a 2D double vector
        std::stringstream ssline(line);  //convert to input stream type

        std::string x, y;
        std::getline(ssline, x, ',');
        std::getline(ssline, y);

        data.push_back({std::stod(x), std::stod(y)});
    }
    data_file.close();

    return;
}


void print_input(std::vector<std::vector<double>> data){
    std::string input;

    std::cout << "Please enter the number of lines you'd like to print:" << std::endl;
    std::cin >> input;
    int N = std::stoi(input);

    //check the input value
    int length = data.size();
    if (N<=0){
        std::cout << "Invalid input, please enter a positive integer!" << std::endl;
        return;
    }
    else if (N>length){
        std::cout << "Input number larger than total number of data points!" << std::endl;
        std::cout << "Printing data in the first 5 lines only:" << std::endl;
        N = 5;
    }
    else{
        std::cout << "Printing data in the first " << N << " lines:" << std::endl;
    }

    //print the required lines of data
    for (int i=0; i<N; i++){
        std::cout << data[i][0] << ", " << data[i][1] <<std::endl;
    }

    return;
}


void print_output(std::string output, std::string path){
    std::ofstream output_file(path);
    output_file << output << std::endl;
    output_file.close();
    std::cout << output << std::endl; //also print in terminal
    std::cout << "...saved to output file: " << path << std::endl;
}


void print_output(std::vector<double> output, std::string path){
    std::ofstream output_file(path);
    for (int i=0; i<data.size(); i++){
        output_file << output[i] << std::endl;
        std::cout << output[i] << std::endl;
    }
    output_file.close();
    std::cout << "...saved to output file: " << path << std::endl;
}


// Calulations
double magnitude(double x, double y){
    return std::sqrt(x*x + y*y);
}


std::string fitting(std::string inputfile){
    // Fitting straight line with least squares method
    // (can change input to 'data' but 'inputfile' is required by the assignment...)

    //read the data
    read_input(inputfile);

    int N = data.size();
    double xi_sum, yi_sum, xiyi_sum, xi2_sum;
    
    //calculate the sum
    for (int i=0; i<data.size(); i++){
        double xi = data[i][0];
        double yi = data[i][1];

        xi_sum += xi;
        yi_sum += yi;
        xiyi_sum += xi*yi;
        xi2_sum += xi*xi;
    }

    //calculate the fit values
    double p = (N * xiyi_sum - xi_sum * yi_sum) / (N * xi2_sum - xi_sum * xi_sum);
    double q = (xi2_sum * yi_sum - xiyi_sum * xi_sum) / (N * xi2_sum - xi_sum * xi_sum);
    std::string fit_result = "y=" + std::to_string(p) + "x+" + std::to_string(q);

    return fit_result;
}