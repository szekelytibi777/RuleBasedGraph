#pragma once
#include <cassert>
#include <string.h>
#ifdef GRAPHVIZ_RENDERER
	#include "gvpp.hpp"
#endif
#include "Common.hpp"


namespace Graph{
	class Edge;
	class Node
	{

		public:
			Node(std::string id = "x");
			Node(const Node& other);
			
			Node& operator = (const Node& other);

			void addInputEdge(Edge *edge){inputs.push_back(edge);}
			void addOutputEdge(Edge *edge){outputs.push_back(edge);}

			unsigned getLevel() const  {return level_;}
			void setLevel(unsigned level) {level_ = level;}
			 
			const std::string& getID() const;

			EdgePtrs& getInputEdges() {return inputs;}
			EdgePtrs& getOutputEdges() {return outputs;}
		
			void touch(){touched++;}
			int getTouched(){return touched;}


			void setX(int x) { xPos = x; }
			int getX() { return xPos; }
			
			std::string toString(bool showEdges = false) const;
		#ifdef GRAPHVIZ_RENDERER
			gvpp::Node<char>* getRenderNode()const {return display_node;}
			void setRenderNode(gvpp::Node<char>* gvpp_node){display_node = gvpp_node;}
		#endif

		void setMarked(bool m = true){marked_ = m;}
		bool marked() {return marked_;}

		bool operator == (const Node& other){
			return other.getID() == getID();
		}


		private:
			EdgePtrs inputs;
			EdgePtrs outputs;
			std::string id_;
		
		#ifdef GRAPHVIZ_RENDERER
			gvpp::Node<char>* display_node;
		#endif
			int xPos = -1;
			unsigned level_;
			int  touched = 0;

			bool marked_ = false;
	};

	typedef std::vector<Node> Nodes;
	typedef std::vector<Node*> NodePtrs;
	typedef std::vector<Node&> NodeRefs;

}
