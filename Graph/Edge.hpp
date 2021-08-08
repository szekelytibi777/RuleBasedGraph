
#pragma once
#include <string>
#include <string.h>
#include "Common.hpp"
#include "Node.hpp"
	
namespace Graph{
//!  An Edge class. 
/*!
  This class descript an Edge in the Graph
  with two Nodes connected by each other:
  fromNode and toNode
*/
	class Edge  
	{
		public:

			Edge(const std::string &from_node_id = "?", const std::string &to_node_id = "?");
			Edge(Node*fromPeakPtr, Node*toPeakPtr);
	
			Edge operator = (const Edge &other){ memcpy(this, &other, sizeof(other)); return *this;}
			const std::string & getTargetIdentifier(){return id_to;}
			const std::string & getSourceIdentifier(){return id_from;}
			Node*fromNode(){return from_node;}
			Node*toNode(){return to_node;}
			std::string toString();

			void init(NodeMap &map);


		private:
			std::string id_from;
			std::string id_to; 
			NodePtr from_node = 0;
			NodePtr to_node = 0;
			
	};

    typedef std::vector<Edge> Edges;
	
	typedef std::map<std::string, Edges*> EdgesMap;

}	
