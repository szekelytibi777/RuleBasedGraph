#include "InsertRule.hpp"  

namespace Graph{
    InsertRule::InsertRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool InsertRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "InsertRule not implemented yet!");
        #endif
          if(!originalPart_.inputs().empty() && !originalPart_.outputs().empty()){
            for(Node* ns : originalPart_.inputs()){
                for(Node* es : originalPart_.outputs()){
                    Node* nsMain = graph_.getNodeById(ns->getID());
                    Node* esMain = graph_.getNodeById(es->getID());
                    assert((nsMain && esMain) && "Subgraph of this rule is inappropriate!");              
                    NodePtrs path;
                    int numOfPaths = graph_.shortestPathsBetween(*nsMain, *esMain, path);
                    // TODO: Solve multiple paths
                    if(numOfPaths > 0){
                        Node* fromNode = path.front();
                        Node* toNode = path.back();
                       
                        graph_.insertSubGraph(*modifiedPart_, fromNode, toNode);
                        return true;
                    }
                }
            }

        }
        return false;
    }
            
    InsertRule::~InsertRule()
    {
        
    }    
}	
