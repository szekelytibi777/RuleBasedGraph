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

    }

    Node::Node(const Node& other)
    #ifdef GRAPHVIZ_RENDERER
        : display_node(other.display_node)
    #endif
    {
        *this = other; 
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

    std::string Node::toString() const
    {
        std::string s = "[" + id_ +"]";
        return s;
    }   
    
}