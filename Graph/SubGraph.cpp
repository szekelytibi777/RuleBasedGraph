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
            std::cout << from_node_id << std::endl;
            if(!first_node)
                first_node = createNode(from_node_id);

 
            NodePtr p = createNode(from_node_id);
        
            std::vector<std::string> tokens;
            parseToIdList(token, tokens);
            
            for(const std::string& to_node_id : tokens){
                Node* to_node = getNodeById(to_node_id);
                last_node = to_node;
           
                Node *fn = getNodeById(from_node_id);
                Node *tn = getNodeById(to_node_id);
                Edge &e = createEdge( fn, tn);
                e.init(node_map);
                fn->addOutputEdge(&e);
                tn->addInputEdge(&e);
            } 
        }
        //identify start and end nodes of this SubGraph
        inputNodes.clear();
        outputNodes.clear();
        for(auto &p : node_map){
            if(p.second->getInputEdges().empty())
                inputNodes.push_back(p.second);
            if(p.second->getOutputEdges().empty())
                outputNodes.push_back(p.second);
        }
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
        if(count ==  0)
            node_map[id] = new Node(id);
        return node_map[id];
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

    void SubGraph::setInputNodes(NodePtrs &newInputs, Graph &theGraph){
        inputNodes.clear();
        for(Node*n : newInputs){
            inputNodes.push_back(theGraph.transFormedNodePtr(n));
        }
    }
    void SubGraph::setOutputNodes(NodePtrs &newOutputs, Graph &theGraph){
        outputNodes.clear();
        for(Node*n : newOutputs){
            outputNodes.push_back(theGraph.transFormedNodePtr(n));
        }
    }
    
    std::string SubGraph::toString()
    {
        std::string ret;
        for(auto &p : node_map){
            ret += p.second->toString(true) + "\n";
        }
        return ret;
    }

    SubGraph::~SubGraph()
    {
        
    }
}    
