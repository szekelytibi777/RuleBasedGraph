#include "ReplaceRule.hpp"  

namespace Graph{
    ReplaceRule::ReplaceRule(Graph &graph, SubGraph &original, SubGraph *modified)
        : BaseRule(graph, original, modified)
    {
            
    }

    bool ReplaceRule::process()
    {
        // TODO: implement
        #ifdef ASSERT_UNIMPLEMENTED_FUNCTIONS
        assert(0 && "ReplaceRule not implemented yet!");
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
                        for(Node* n : path){
                            std::cout << n->toString() << std::endl;
                        }
         //               std::cout << nsMain->getID() << " - " << esMa((in->getID() << " " << path.size() << std::endl;
                        Node* fromNode = path.front()->getInputEdges().empty() ? 0 : path.front()->getInputEdges().front()->fromNode();
                        Node* toNode = path.back()->getOutputEdges().empty() ? 0 : path.back()->getOutputEdges().front()->toNode();
                        if(fromNode)
                            std::cout << fromNode->toString(true) << std::endl;
                        if(toNode)
                            std::cout << toNode->toString(true) << std::endl;                           

                        for(Node* n: path){
                            n->setMarked(true);
                        }
                        graph_.deleteMarkedNodes();
                       
                        graph_.addSubGraph(*modifiedPart_, fromNode, toNode);
                    }
                }
            }

        }
        return false;
    }
            
    ReplaceRule::~ReplaceRule()
    {
        
    }    
}	
