
#pragma once
#ifdef GRAPHVIZ_RENDERER
	#include "../gvpp/src/gvpp.hpp"
	#include "Graph.hpp"


namespace Graph
{
	class Renderer  
	{
		public:
			static Renderer& instance(); 
			Renderer();
			gvpp::Node<char>* createRenderNode(const std::string &id, const std::string &label);
			void renderEdge(gvpp::Node<> &n_from, gvpp::Node<> &n_to);
			void show();
			gvpp::Graph<> *getGvppGraphPtr(){ return &graph; }

		private:
			gvpp::Graph<> graph;
			static Renderer* instance_;

	};
}
#endif
