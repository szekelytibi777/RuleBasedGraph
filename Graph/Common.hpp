#pragma once
#include <unordered_map>
#include <vector>

namespace Graph{
    class Edge;
    class Node;
    typedef Node* NodePtr;
    typedef std::vector<Edge*> EdgePtrs;
    typedef std::unordered_map<std::string, NodePtr> NodeMap;


    const int edgeNodesMultiplyFactor = 4;  // estimated average value. TODO: determination of the specific value
    const std::string idDummy = "dummi";
}
