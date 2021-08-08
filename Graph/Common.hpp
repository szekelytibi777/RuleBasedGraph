#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
#include <iomanip>

namespace Graph{
    class Edge;
    class Node;
    typedef Node* NodePtr;
    typedef std::vector<Edge*> EdgePtrs;
    typedef std::map<std::string, NodePtr> NodeMap;
    
    const int edgeNodesMultiplyFactor = 4;  // estimated average value. TODO: determination of the specific value
    const std::string idDummy = "dummi";
}

