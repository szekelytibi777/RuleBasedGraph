#include "NewNodesRule.hpp"  
namespace Graph{
    NewNodesRule::NewNodesRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool NewNodesRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "InsertRule not implemented yet!");
        #endif

        graph_.addNewNodes(*modifiedPart_);
          
        return false;
    }
            
    NewNodesRule::~NewNodesRule()
    {
        
    }    
}	
