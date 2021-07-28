#include "DeleteRule.hpp"  

namespace Graph{
    DeleteRule::DeleteRule(Graph &graph, SubGraph &original)
        : BaseRule(graph, original)
    {
            
    }

    bool DeleteRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "DeleteRule not implemented yet!");
        #endif
        if(!originalPart_.inputs().empty() && !originalPart_.outputs().empty()){
            for(Node* ns : originalPart_.inputs()){
                for(Node* es : originalPart_.outputs()){
                    NodePtrs path;
                    if(graph_.findPathBetween(*ns, *es, path)){
                        for(Node* n: path){
                            n->setMarked();
                        }
                    }
                }
            }

        }
        return true;
    }
            
    DeleteRule::~DeleteRule()
    {
        
    }    
}	
