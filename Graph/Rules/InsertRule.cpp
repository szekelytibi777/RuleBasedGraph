#include "InsertRule.hpp"  

namespace Graph{
    InsertRule::InsertRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool InsertRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "InsertRule not implemented yet!");
        #endif
        return false;
    }
            
    InsertRule::~InsertRule()
    {
        
    }    
}	
