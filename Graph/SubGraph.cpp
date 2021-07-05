#include "SubGraph.hpp"  
	
namespace Graph{
    SubGraph::SubGraph(Graph *graph,  std::string &subGrafDescriptor)
    {
        // TODO: buid SubGraph from descriptor string
        assert(0 && "SubGraph builder is not implemented yet");
        /*
        for(const std::string &id : inputIds)
        {
            NodePtr np = graph->getNodeById(id);
            assert(np);
            if(np){
                inputNodes.push_back(np);
            }
        }

        for(const std::string &id : outputIds)
        {
            NodePtr np = graph->getNodeById(id);
            assert(np);
            if(np){
                outputNodes.push_back(np);
            }
        }
        */
    }
        
    SubGraph::~SubGraph()
    {
        
    }
}    
