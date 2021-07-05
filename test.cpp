#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "Utils.hpp"
#include "Graph/Graph.hpp"
//#include "gvpp.hpp"
#include "Graph/Renderer.hpp"

using namespace std;



std::string what_last = "TEST";
void _________check________(bool result = true, std::string what = "", bool fail_msg_only = false)
{
   if(!what.empty())
      what_last = what;
   else
      what = what_last;
   std::string failed("FAILED: "); 
   if(result){
      if(!fail_msg_only)
         std::cout << "SUCCESSFUL: " << what << std::endl;
   }
   else{
      std::cout << "FAILED: " << what << std::endl;
      assert(result);
   }
}

void _________DONE________()
{
   std::cout << "               **************" << std::endl;
   std::cout << "all tests were * SUCCESSFUL *" << std::endl;
   std::cout << "               **************" << std::endl;
}

int test(int argc, char *argv[]) {
   cout << "Test Aimotive gráf framework" <<std::endl; 
   int numberOfNodes = 10;
   if(argc != 2){
        std::cout << "Usage:" << std::endl;
        std::cout << "\ttest <number_of_peaks>" << std::endl;
    }
    else{
       numberOfNodes = atoi(argv[1]);

    }
   #ifdef GRAPHVIZ_RENDERER
   Graph::Renderer renderer;
   #endif
  

  
   Graph::Graph graph(numberOfNodes, numberOfNodes *Graph::edgeNodesMultiplyFactor);


   for(int i = 0; i < numberOfNodes; i++){
      std::string id_str = getIdStr(i);
      Graph::Node *p = graph.instance().createNode(id_str); 
   }

  
   _________check________(graph.instance().getNodeMap().size() == numberOfNodes, "Creating Peaks");
   
   for(int i = 0; i < numberOfNodes; i++){
      std::string id_str = getIdStr(i);

      Graph::Node *p = graph.instance().getNodeById(id_str);
      _________check________(p,"Acessing Peaks",true);
   }
   _________check________();
//   std::cout << "SUCCESS: Acessing Peaks" << std::endl;

   Graph::Node *p_start = graph.instance().createNode("start");
   Graph::Node *p_end = graph.instance().createNode("end");

   Graph::NodePtrs nodesArray(numberOfNodes);
   nodesArray.clear(); 
   for(int i = 0; i < numberOfNodes; i++){
      std::string id_str = getIdStr(i);
      Graph::Node *p = graph.instance().getNodeById(id_str);
      _________check________(p,"Preparing of output Edges",true); 
      nodesArray.push_back(p);
   }
   //std::cout << "SUCCESS: Preparing of output Edges" << std::endl;
   _________check________();
   Graph::EdgePtrs from_edge_ptrs(numberOfNodes);
   from_edge_ptrs.clear();
   Graph::EdgePtrs to_edge_ptrs(numberOfNodes);
   to_edge_ptrs.clear();
   bool succes = graph.createEdges(p_start, nodesArray, &from_edge_ptrs);
   succes |= graph.createEdges(nodesArray, p_end, &to_edge_ptrs);
   _________check________(succes,"Creating Edges");
 
   _________DONE________();

   #ifdef GRAPHVIZ_RENDERER
   renderer.show();
   #endif
   
   return 0;
}