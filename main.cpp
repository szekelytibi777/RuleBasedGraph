#include <unistd.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "Graph/Graph.hpp"
#include "Graph/Renderer.hpp"
#include "Graph/Rules/Rules.hpp"
#include "gvpp/src/gvpp.hpp"
#define APPLY_RULES
// 
using namespace std;
gvpp::Graph<> * renderGraph  = 0;
int main(int argc, char *argv[]){

    std::string inputDataFilePath = "data/input.txt";
    std::string rulesFilePath = "data/graph_rules copy.txt";  
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
        std::cout << "Execution was successful." << std::endl;
        graph->logStatus();
    }
    catch(std::exception e){
        std::cerr << "Failed to read data file! \n" << e.what() << std::endl;
    }
   
#ifdef APPLY_RULES
    try{
        
        Graph::Rules rules(graph, rulesFilePath); 
        rules.applyAll();
        std::cout << "Rules are applied successfully." << std::endl;
        graph->logStatus();
    }
    catch(std::exception e){
        std::cerr << "Failed to read data file! \n" << e.what() << std::endl;
    }
#endif
    std::cout << "----------------------" << std::endl;
    graph->buildRenderedGraph();
    graph->logStatus();
    #ifdef GRAPHVIZ_RENDERER
        renderer->show();
    #endif
    std::cout << "----------------------" << std::endl;
    usleep(1000000);
    delete graph;
    return 0;
}