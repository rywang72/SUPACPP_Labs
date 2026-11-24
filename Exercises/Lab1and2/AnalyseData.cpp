#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

//define global variables
std::string inputfile = "input2D_float.txt";
std::ifstream data_file;
std::vector<std::vector<double>> data;
std::vector<double> data_mag;


////Functions
int read_input(std::string inputfile){   
    std::string line;

    //assuming the input file is under the same directory
    data_file.open(inputfile);

    //raise error if unable to open
    if (!data_file.is_open()) {
        std::cout << "Error occurs at opening the file: " << inputfile << std::endl;
        std::cout << "Empty input data returned!" << std::endl;
        return -1;
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

    return 0;
}


int print_input(std::vector<std::vector<double>> data){
    std::string input;

    std::cout << "Please enter the number of lines you'd like to print:" << std::endl;
    std::cin >> input;
    int N = std::stoi(input);

    //check the input value
    int length = data.size();
    if (N<=0){
        std::cout << "Invalid input, please enter a positive integer!" << std::endl;
        return -1;
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

    return 0;
}


double magnitude(double x, double y){
    return std::sqrt(x*x + y*y);
}




////Main
int main()
{   
    //read the data
    if (read_input(inputfile) != 0) {
        return -1;
    }

    //print the data
    if (print_input(data) != 0) {
        return -1;
    }

    //calculate and print the magnitudes
    // std::cout << "Magnitude of the input vectors:" << std::endl;
    for (int i=0; i<data.size(); i++){
        double mag = magnitude(data[i][0], data[i][1]);
        data_mag.push_back(mag);
        // std::cout << mag << std::endl;
    }
    // std::cout << "Size of output: " << data_mag.size() << std::endl;

    return 0;
}