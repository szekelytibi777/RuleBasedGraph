#include "ChangeRule.hpp"  

namespace Graph{
    ChangeRule::ChangeRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool ChangeRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "ChangeRule not implemented yet!");
        #endif
        originalPart_.getNodeMap().erase("0");
        modifiedPart_->getNodeMap().erase("0");
        Node* oldNode = originalPart_.getNodeMap().begin()->second;
        Node* newNode = modifiedPart_->getNodeMap().begin()->second;
        graph_.changeNodes(oldNode, newNode);
   
        return false;
    }
            
    ChangeRule::~ChangeRule()
    {
        
    }    
}	
