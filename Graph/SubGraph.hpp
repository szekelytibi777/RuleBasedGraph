#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.hpp"

namespace Graph{
    class SubGraph{
        public:
            SubGraph(Graph *graph, std::string &subGrafDescriptor);
            ~SubGraph();

        private:
            NodePtrs inputNodes;
            NodePtrs outputNodes;
    };
}