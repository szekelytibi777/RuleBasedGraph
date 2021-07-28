#include "ShortcutRule.hpp"  

namespace Graph{
    ShortCutRule::ShortCutRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool ShortCutRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "ShortcutRule not implemented yet!");
        #endif
        return false;
    }
            
    ShortCutRule::~ShortCutRule()
    {
        
    }    
}	
