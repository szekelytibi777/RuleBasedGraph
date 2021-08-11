#include "AddRule.hpp"  

namespace Graph{
    AddRule::AddRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool AddRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "AddRule not implemented yet!");
        #endif
        NodePtr origNode = graph_.transFormedNodePtr(std::prev(originalPart_.getNodeMap().end())->second);
        
        graph_.addSubGraph2(*modifiedPart_, origNode, 0);

         
        return false;
    }
            
    AddRule::~AddRule()
    {
        
    }    
}	