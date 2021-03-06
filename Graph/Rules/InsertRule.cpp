#include "InsertRule.hpp"  

namespace Graph{
    InsertRule::InsertRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool InsertRule::process()
    {
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
                        Node* n = graph_.getNodeById(path.front()->getID()); 
                        
                        Node* fromNode = graph_.transFormedNodePtr(path.front());
                        Node* toNode = graph_.transFormedNodePtr(path.back());
                        std::cout << fromNode->toString(true) << std::endl;
                
                        graph_.addSubGraph2(*modifiedPart_, true,fromNode, toNode);
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
