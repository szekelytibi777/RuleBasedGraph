#include "SubGraph.hpp"  

#include "../Utils.hpp" 
	
namespace Graph{
    SubGraph::SubGraph(Graph *graph,  std::string &subGrafDescriptor)
    {
        // TODO: buid SubGraph from descriptor string
        //assert(0 && "SubGraph builder is not implemented yet");
        std::istringstream ss(subGrafDescriptor);
        std::string token;
        while(getline(ss, token, ';'))
        {
            std::string from_node_id = parseFromId(token);
            
            NodePtr p = createNode(from_node_id);
        
            std::vector<std::string> tokens;
            parseToIdList(token, tokens);
            
            for(const std::string& to_node_id : tokens){
                createNode(to_node_id);
                createEdge(getNodeById(from_node_id), getNodeById(to_node_id));
            }
        }
        /*
        for(const std::string &id : inputIds)
        {
            NodePtr np = graph->getNodeById(id);
            assert(np);
            if(np){
                inputNodes.push_back(np);
            }
        }

        for(const std::string &id : outputIds)
        {
            NodePtr np = graph->getNodeById(id);
            assert(np);
            if(np){
                outputNodes.push_back(np);
            }
        }
        */

    }
        
    std::string SubGraph::parseFromId(const std::string &token)
    {
        std::string s = token.substr(0, token.find(':'));
        return s;
    }

	int SubGraph::parseToIdList(const std::string &token, std::vector<std::string> &outputTokens)
    {
        std::string other_peaks = std::string(token.substr(token.find(':')+1));
        splitString(outputTokens, other_peaks);
        return outputTokens.size();
    }

    Node* SubGraph::createNode(const std::string id)
    {

        if(node_map.count(id) == 0)
            node_map[id] =  new Node(id);

        return node_map[id];
    }

	Node* SubGraph::getNodeById(const std::string &id)
    {
        int count = node_map.count(id);
        if(count ==  1)
            return node_map[id];
        else
            return 0;//dummyPeak;
    }


	Edge& SubGraph::createEdge(const std::string id_from, const std::string id_to)
    {
        edge_pool.emplace(edge_pool.end(),Edge(id_from, id_to));
        return edge_pool.back();
    }

	Edge& SubGraph::createEdge(Node *fromNodePtr, Node *toNodePtr)
    {
        assert(fromNodePtr != 0);
        assert(toNodePtr != 0);
        edge_pool.emplace(edge_pool.end(),Edge(fromNodePtr, toNodePtr));
        return edge_pool.back();
    }

    SubGraph::~SubGraph()
    {
        
    }
}    
