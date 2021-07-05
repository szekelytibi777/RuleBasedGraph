#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.hpp"
#include "Node.hpp"
#include "Common.hpp"
#ifdef GRAPHVIZ_RENDERER
	#include "gvpp.hpp"
#endif

namespace Graph{	

	class Graph  
	{
		public:

			Graph(const std::string &file_name);
			Graph(unsigned numberofNodes, unsigned numberOfEdges);
			~Graph();
			static Graph& instance();
			
			NodeMap& getNodeMap(){return node_map;}

			void walk(Node* peak_ptr, int level=0);
			Node* createNode(const std::string id);
			Edge& createEdge(const std::string id_from, const std::string id_to);
			Edge& createEdge(Node *fromNodePtr, Node *toNodePtr);
			Node* getNodeById(const std::string &id);

			bool createEdges(Node* fromNode, NodePtrs &toArray, EdgePtrs* outEdges = 0);
			bool createEdges(NodePtrs& fromArray, Node* toNode, EdgePtrs* outEdges = 0);

			void logStatus();
			

			void buildRenderedGraph();
			
			void show();
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
		#ifdef GRAPHVIZ_RENDERER
			gvpp::Graph<> gvpp_graph;
		#endif
	
	};
}
