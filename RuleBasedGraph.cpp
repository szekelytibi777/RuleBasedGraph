// RuleBasedGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "Graph/Graph.hpp"

int main(int argc, char* argv[])
{
    std::string inputDataFilePath = "data/mintagráf.txt";
    if (argc != 2) {
        std::cout << "Usage:" << std::endl;
        std::cout << "\tmain <input_data_file_path>" << std::endl;
    }
    else {
        inputDataFilePath = std::string(argv[1]);
    }
    std::cout << "Construct the graph according to the input file: " << inputDataFilePath << std::endl;
    std::cout << "Initial graph" << std::endl;
    try {//
        Graph::Graph graph(inputDataFilePath);
        graph.logStatus();
        graph.show();
        std::cout << "Done." << std::endl;
    }
    catch (std::exception e) {
        std::cerr << "Error while loading the input file! \n" << e.what() << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
