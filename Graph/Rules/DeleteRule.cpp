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
                    Node* nsMain = graph_.getNodeById(ns->getID());
                    Node* esMain = graph_.getNodeById(es->getID());
                    assert((nsMain && esMain) && "Subgraph of this rule is inappropriate!");              
                    NodePtrs path;
                    int numOfPaths = graph_.shortestPathsBetween(*nsMain, *esMain, path);
                    if(numOfPaths > 0){
         //               std::cout << nsMain->getID() << " - " << esMain->getID() << " " << path.size() << std::endl;
                        for(Node* n: path){
                            std::cout << n->getID() << std::endl;
                            //n->setMarked(true);
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
