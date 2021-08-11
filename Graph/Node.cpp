#include <iostream>

#ifdef GRAPHVIZ_RENDERER
	#include "gvpp.hpp"
#endif
#include "Node.hpp"
#include "Common.hpp"
#include "Renderer.hpp"


namespace Graph{
    	
    Node::Node(std::string id)
        : inputs(0)
        , outputs(0)
        , id_(id)
    #ifdef GRAPHVIZ_RENDERER
        , display_node(0)
    #endif
        , level_(0)
    {
       
        //    std::cout << getID() << std::endl;
   }

    Node::Node(const Node& other)
    #ifdef GRAPHVIZ_RENDERER
        : display_node(other.display_node)
    #endif
    {
        *this = other; 
    }

	Node::~Node()
    {
 //       std::cout << "destructed: "+getID() << std::endl;
    }
    Node& Node::operator = (const Node&other)
    {
        level_ = other.level_;
        inputs = other.inputs;
        outputs = other.outputs;
        id_ = other.id_;
        return *this;
    }


    const std::string& Node::getID() const
    {
        return id_;
    }

    std::string Node::toString(bool showEdges) const
    {
        std::string iNodes = "[]";
        std::string oNodes = "[]";
        if(showEdges){
            iNodes = "[";
            for(Edge* e:inputs){
                if(e->fromNode())
                    iNodes += e->fromNode()->getID()+" ";
            }
            iNodes += "]";
            oNodes = "[";
            for(Edge* e:outputs){
                if(e->toNode())
                    oNodes += e->toNode()->getID()+" ";
            }
            oNodes += "]";
        }
        std::string s = iNodes+" <" + id_ +"> "+oNodes;
        return s;
    }   
    
}