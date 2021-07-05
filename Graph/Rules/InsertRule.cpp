#include "InsertRule.hpp"  

namespace Graph{
    InsertRule::InsertRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool InsertRule::process()
    {
        // TODO: implement
        assert(0 && "InsertRule not implemented yet!");
        return false;
    }
            
    InsertRule::~InsertRule()
    {
        
    }    
}	
