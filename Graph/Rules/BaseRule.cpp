#include "BaseRule.hpp"  
#include "../SubGraph.hpp"
	
namespace Graph{
    BaseRule::BaseRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : graph_(graph)
        , originalPart_(original)
        , modifiedPart_(modified)
    {
            
    }
            
    BaseRule::~BaseRule()
    {
        
    }
}    
