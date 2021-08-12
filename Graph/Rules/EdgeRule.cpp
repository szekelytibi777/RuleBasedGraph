#include "EdgeRule.hpp"  
#include "../../Utils.hpp"

namespace Graph{
    EdgeRule::EdgeRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool EdgeRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "AddRule not implemented yet!");
        #endif

        NodePtr fromNode = graph_.transFormedNodePtr(originalPart_.firstNode());
        NodePtr toNode = graph_.transFormedNodePtr(originalPart_.lastNode());
        if(toNode && toNode->getID() == "0")
            toNode = 0;
        if(fromNode && fromNode->getID() == "0")
            fromNode = 0;
        originalPart_.getNodeMap().erase("0");

        graph_.connectNodes(fromNode, toNode);
           
             
        return false;
    }
            
    EdgeRule::~EdgeRule()
    {
        
    }    
}	