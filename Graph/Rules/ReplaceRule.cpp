#include "ReplaceRule.hpp"  

namespace Graph{
    ReplaceRule::ReplaceRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool ReplaceRule::process()
    {
        // TODO: implement
        assert(0 && "ReplaceRule not implemented yet!");
        return false;
    }
            
    ReplaceRule::~ReplaceRule()
    {
        
    }    
}	
