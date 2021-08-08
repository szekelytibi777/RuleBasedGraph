#include <iostream>
#include "Edge.hpp"
#include "Common.hpp"
#include "Renderer.hpp"
#include "../Utils.hpp"
#include "Graph.hpp"
	
 namespace Graph{


    Edge::Edge(const std::string &from_node_id, const std::string &to_node_id)
        : id_from(from_node_id)
        , id_to(to_node_id)
    {
    #ifdef GRAPHVIZ_RENDERER
//        Renderer::instance().renderEdge(*from_peak->getRenderNode(), *to_peak->getRenderNode());
    #endif
        from_node = Graph::instance().getNodeById(from_node_id);
        to_node = Graph::instance().getNodeById(to_node_id);
    }

    Edge::Edge(Node* fromNodePtr, Node* toNodePtr)
        : from_node(fromNodePtr)
        , to_node(toNodePtr)
    {
        if(from_node)
            id_from = from_node->getID();
        if(to_node)
            id_to = to_node->getID();
    #ifdef GRAPHVIZ_RENDERER
     //   Renderer::instance().renderEdge(*from_peak->getRenderNode(), *to_peak->getRenderNode());
    #endif
    }

	void Edge::init(NodeMap &map)
    {
        from_node = map.at(id_from);
        to_node = map.at(id_to);
    }

	std::string Edge::toString()
    {
        std::string s = intToHex((unsigned long)this) + " " + id_from + " -> " + id_to;
        return s;
    }

        
}
