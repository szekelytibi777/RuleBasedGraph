#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.hpp"
#include "Edge.hpp"
#include "Node.hpp"

namespace Graph{
//!  a SubGraph class. 
/*!
  This class descript a SubGraph
*/
    class SubGraph{
        public:
            SubGraph(Graph *graph, std::string &subGrafDescriptor);
            ~SubGraph();

            Node* createNode(const std::string id);
			Edge& createEdge(const std::string id_from, const std::string id_to);
			Edge& createEdge(Node *fromNodePtr, Node *toNodePtr);
			Node* getNodeById(const std::string &id);
            Node* startNode(){

            }
            Node* endNode(){

            }
            NodePtrs &inputs(){return inputNodes;}
            NodePtrs &outputs(){return outputNodes;}
            void setInputNodes(NodePtrs &newInputs, Graph &theGraph);
           
            void setOutputNodes(NodePtrs &newOutputs, Graph &theGraph);

            NodeMap &getNodeMap(){return node_map;}

        private:
	        NodeMap node_map;
			Edges edge_pool;

            std::string  parseFromId(const std::string &token);
			int parseToIdList(const std::string &token, std::vector<std::string> &outputTokens);
            NodePtrs inputNodes;
            NodePtrs outputNodes;
    };
}