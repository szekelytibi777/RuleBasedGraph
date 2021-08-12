#include "AddRule.hpp"  
#include "../../Utils.hpp"

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

        NodePtr fromNode = graph_.transFormedNodePtr(originalPart_.firstNode());
        NodePtr toNode = graph_.transFormedNodePtr(originalPart_.lastNode());
        if(toNode->getID() == "0")
            toNode = 0;
        if(fromNode->getID() == "0")
            fromNode = 0;
        originalPart_.getNodeMap().erase("0");

              
        graph_.addSubGraph2(*modifiedPart_, false, fromNode, toNode);

         
        return false;
    }
            
    AddRule::~AddRule()
    {
        
    }    
}	