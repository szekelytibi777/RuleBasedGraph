#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
#include <iomanip>
#define GRAPHVIZ_RENDERER 1
namespace Graph{
    class Edge;
    class Node;
    typedef Node* NodePtr;
    typedef std::vector<Edge*> EdgePtrs;
    typedef std::unordered_map<std::string, NodePtr> NodeMap;
    
    const int edgeNodesMultiplyFactor = 4;  // estimated average value. TODO: determination of the specific value
    const std::string idDummy = "dummi";
}

