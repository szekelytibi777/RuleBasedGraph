#pragma once

#include <limits.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Edge.hpp"
#include "Node.hpp"
#include "Common.hpp"


#include "../gvpp/src/gvpp.hpp"


namespace Graph{	
	class SubGraph;
//!  The Graph class. 
/*!
  This class descript the Graph
*/
	class Graph  
	{
		public:

			Graph(const std::string &file_name, gvpp::Graph<> *renderGraph = 0);
			Graph(unsigned numberofNodes, unsigned numberOfEdges, gvpp::Graph<> *renderGraph = 0);
			~Graph();
			static Graph& instance();
			
			NodeMap& getNodeMap(){return node_map;}

			void walk(Node* peak_ptr, int level=0);
			Node* createNode(const std::string id);
			Edge& createEdge(const std::string id_from, const std::string id_to);
			Edge& createEdge(Node *fromNodePtr, Node *toNodePtr);
			Node* getNodeById(const std::string &id);
			Node* transFormedNodePtr(Node *nodePtr);

			bool createEdges(Node* fromNode, NodePtrs &toArray, EdgePtrs* outEdges = 0);
			bool createEdges(NodePtrs& fromArray, Node* toNode, EdgePtrs* outEdges = 0);

			bool findPathsBetween(Node &startNode, Node &endNode, std::vector<NodePtrs> &path);
			int shortestPathsBetween(Node &startNode, Node &endNode, NodePtrs &resultPath);
			void logStatus();
			void buildRenderedGraph();
			int deleteMarkedNodes();
			void show();
			void printNodes();
			void addSubGraph(SubGraph &subGraph);
		private:
			static Graph *instance_;
			NodeMap node_map;
			Edges edge_pool;
			int maxLevel = -1;
			int maxWidth = -1;
			void calculateNodeLevels();
			
	
			void initEdges();
			void initNodes();

			std::string  parseFromId(const std::string &line);
			int parseToIdList(const std::string &line , std::vector<std::string> &outputTokens);
			bool walkTo(Node& node,const Node &endNode, std::vector<NodePtrs> &resultPaths, NodePtrs pathTmp, int deepth);


			gvpp::Graph<> *gvpp_graph_;
	};
}
