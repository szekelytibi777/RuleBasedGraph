#include <iostream>
#include <fstream>

#include "Graph/Graph.hpp"
#include "Graph/Renderer.hpp"
#include "Graph/Rules/Rules.hpp"

using namespace std;
int main(int argc, char *argv[]){

    std::string inputDataFilePath = "data/mintagráf.txt";
    std::string rulesFilePath = "date/rules.txt";  
    if(argc == 3){
        inputDataFilePath = std::string(argv[1]);
        rulesFilePath = std::string(argv[2]);
    }
    else if(argc == 2){
        inputDataFilePath = std::string(argv[1]);
    }
    else{
        std::cout << "Usage:" << std::endl;
        std::cout << "\tmain <input_data_file_path> <rules_file_path>" << std::endl;
    }

    std::cout << "Construct the graph according to the input file: " << inputDataFilePath << std::endl;

    #ifdef GRAPHVIZ_RENDERER
    Graph::Renderer renderer;
    #endif
    cout << "Rule based graph" << endl;
    Graph::Graph * graph = 0;
    try{ 
        graph = new Graph::Graph(inputDataFilePath);
        graph->logStatus();
        std::cout << "Execution was successful." << std::endl;
    }
    catch(std::exception e){
        std::cerr << "Failed to read data file! \n" << e.what() << std::endl;
    }
    #ifdef GRAPHVIZ_RENDERER
        renderer.show();
    #endif
    
    try{
        Graph::Rules rules(graph, rulesFilePath); 
        std::cout << "Rules are applied successfully." << std::endl;
    }
    catch(std::exception e){
        std::cerr << "Failed to read data file! \n" << e.what() << std::endl;
    }
    delete graph;
    return 0;
}