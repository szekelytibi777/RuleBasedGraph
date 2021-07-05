#include "ShortcutRule.hpp"  

namespace Graph{
    ShortCutRule::ShortCutRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool ShortCutRule::process()
    {
        // TODO: implement
        assert(0 && "ShortcutRule not implemented yet!");
        return false;
    }
            
    ShortCutRule::~ShortCutRule()
    {
        
    }    
}	
