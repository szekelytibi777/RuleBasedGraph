#include "DeleteRule.hpp"  

namespace Graph{
    DeleteRule::DeleteRule(Graph &graph, SubGraph &original)
        : BaseRule(graph, original)
    {
            
    }

    bool DeleteRule::process()
    {
        // TODO: implement
        assert(0 && "DeleteRule not implemented yet!");
        return false;
    }
            
    DeleteRule::~DeleteRule()
    {
        
    }    
}	
