#include <unistd.h>
#include <iostream>
#include <fstream>

#include "Graph/Graph.hpp"
#include "Graph/Renderer.hpp"
#include "Graph/Rules/Rules.hpp"
#include "gvpp/src/gvpp.hpp"

using namespace std;
gvpp::Graph<> * renderGraph  = 0;
int main(int argc, char *argv[]){

    std::string inputDataFilePath = "data/input.txt";
    std::string rulesFilePath = "data/graph_rules copy 2.txt";  
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
    std::cout << "Applying rule according to the input file: " << rulesFilePath << std::endl;

    
    #ifdef GRAPHVIZ_RENDERER
        Graph::Renderer *renderer = new Graph::Renderer();
        renderGraph =  renderer->getGvppGraphPtr();
    #endif


    cout << "Rule based graph" << endl;
    Graph::Graph * graph = 0;
    try{ 
        graph = new Graph::Graph(inputDataFilePath, renderGraph);
        graph->logStatus();
        std::cout << "Execution was successful." << std::endl;
    }
    catch(std::exception e){
        std::cerr << "Failed to read data file! \n" << e.what() << std::endl;
    }
   
   
    try{
        Graph::Rules rules(graph, rulesFilePath); 
        std::cout << "Rules are applied successfully." << std::endl;
    }
    catch(std::exception e){
        std::cerr << "Failed to read data file! \n" << e.what() << std::endl;
    }
    #ifdef GRAPHVIZ_RENDERER
        renderer->show();
    #endif
    usleep(1000000);
    delete graph;
    return 0;
}