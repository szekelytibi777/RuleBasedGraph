#include "DeleteRule.hpp"  

namespace Graph{
    DeleteRule::DeleteRule(Graph &graph, SubGraph &original)
        : BaseRule(graph, original)
    {
            
    }

    bool DeleteRule::process()
    {

        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "DeleteRule not implemented yet!");
        #endif
        graph_.deleteSubGraph(originalPart_);
        return true;
    }
            
    DeleteRule::~DeleteRule()
    {
        
    }    
}	
