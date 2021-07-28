#include <cassert>

#include "Common.hpp"
#include "Graph.hpp"  
#include "../Utils.hpp"
#include "Renderer.hpp"
#include "../gvpp/src/gvpp.hpp"



namespace Graph{

    Graph * Graph::instance_ = 0;
    Graph& Graph::instance()
    { 
        assert(instance_ != 0);
        return *instance_;
    }

	Node* Graph::createNode(const std::string id)
    {

        if(node_map.count(id) == 0)
            node_map[id] =  new Node(id);

        return node_map[id];
    }

	Node* Graph::getNodeById(const std::string &id)
    {
        int count = node_map.count(id);
        if(count ==  1)
            return node_map[id];
        else
            return 0;//dummyPeak;
    }


	Edge& Graph::createEdge(const std::string id_from, const std::string id_to)
    {
        edge_pool.emplace(edge_pool.end(),Edge(id_from, id_to));
        return edge_pool.back();
    }

	Edge& Graph::createEdge(Node *fromNodePtr, Node *toNodePtr)
    {
        assert(fromNodePtr != 0);
        assert(toNodePtr != 0);
        edge_pool.emplace(edge_pool.end(),Edge(fromNodePtr, toNodePtr));
        return edge_pool.back();
    }

    bool Graph::createEdges(Node* fromNode, NodePtrs &toArray, EdgePtrs* outEdges)
    {
        assert(outEdges);

        outEdges->clear();
        outEdges->reserve(toArray.size());

        for(Node* node : toArray){
            Edge *e = &createEdge(fromNode, node);
            outEdges->push_back(e);
        }
        return outEdges->size() > 0;
    }

    bool Graph::createEdges(NodePtrs& fromArray, Node* toNode, EdgePtrs* outEdges)
    {
        assert(outEdges);

        outEdges->clear();
        outEdges->reserve(fromArray.size());

        for(Node* node : fromArray){
            Edge *e = &createEdge(node, toNode);
            outEdges->push_back(e);
        }
        return outEdges->size() > 0;
    }

	std::string Graph::parseFromId(const std::string &line)
    {
        std::string s = line.substr(0, line.find(':'));
        return s;
    }

	int Graph::parseToIdList(const std::string &line, std::vector<std::string> &outputTokens)
    {
        std::string other_peaks = std::string(line.substr(line.find(':')+1));
        splitString(outputTokens, other_peaks);
        return outputTokens.size();
    }


	Graph::Graph(unsigned numberofNodes, unsigned numberOfEdges, gvpp::Graph<> *renderGraph)
        : gvpp_graph_(renderGraph)
    {
        Graph::instance_ = this;
        node_map.reserve(numberofNodes);
        edge_pool.reserve(numberOfEdges);
    }

    Graph::Graph(const  std::string &file_name, gvpp::Graph<> *renderGraph)
        : gvpp_graph_(renderGraph)
    {

        Graph::instance_ = this;
        if(file_name.empty())
            return;
        std::ifstream input_stream;
        input_stream.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
        
            input_stream.open(file_name, std::ifstream::in);
            unsigned num_of_peaks = countLines(input_stream) + 1;
            // avoid unnecessary memory operations -----------------
            // The vector named _pool contains the instances of the object
            // during processing we only refer to them
            node_map.reserve(num_of_peaks);
            edge_pool.reserve(num_of_peaks*edgeNodesMultiplyFactor);
           // edge_map.reserve(num_of_peaks*edgeNodesMultiplyFactor);
            //edges_pool.reserve(num_of_peaks*2); // for pinputs and for outputs
            // ------------------------------------------------------
            std::string line;
            while(!std::getline(input_stream, line).eof())
            {
                if(line.empty())
                    continue;
                std::string from_node_id = parseFromId(line);
               
                NodePtr p = createNode(from_node_id);
            
                std::vector<std::string> tokens;
                parseToIdList(line, tokens);
                
                for(const std::string& to_node_id : tokens){
                    createNode(to_node_id);
                    createEdge(getNodeById(from_node_id), getNodeById(to_node_id));
                }
            };
       
            input_stream.close();
        }
        catch(std::ifstream::failure e){
            throw (e);
        }

        initEdges();
        initNodes();
        calculateNodeLevels();
        buildRenderedGraph();
    }

    void Graph::initEdges()
    {
        for(Edge &e : edge_pool){
            e.init(getNodeMap());
        }
    }

    void Graph::initNodes()
    {
        for(Edge &e : edge_pool){
            Node* from_node = e.fromNode();
            Node* to_node = e.toNode();
            to_node->addInputEdge(&e);
            from_node->addOutputEdge(&e);
        }
    }

    void Graph::calculateNodeLevels()
    {
        NodePtrs startNodes;
        for(auto &e : node_map){
            NodePtr node_ptr = e.second;
            assert(node_ptr);
            if(node_ptr->getInputEdges().size()==0){
                startNodes.push_back(node_ptr);
            }
          
        }
        for(NodePtr node_ptr: startNodes){
            walk(node_ptr, 1);
        }

        std::vector< std::vector<int>> widthsOnLevel(maxLevel);
        for (auto& pair : node_map) {
            NodePtr& node = pair.second;
        }
        for (std::vector<int>& v : widthsOnLevel) {
            int width = 0;
            for (int w : v) {
                width += w;
            }
            if (width > maxWidth)
                maxWidth = width;
        }

        int gap = maxWidth / (startNodes.size()+1);
        int x = gap;
        for (NodePtr node : startNodes) {
            node->setX(x);
            x += gap + 1;
        }
    }

	void Graph::walk(Node* node_ptr, int level)
    {
        maxLevel = level;
        int prev_level = node_ptr->getLevel();
        node_ptr->setLevel(level);
        std::string levelstr= "level:";
        levelstr += std::to_string(level);
        std::string label = node_ptr->getID()+levelstr;
       // peak_ptr->setLabel(label);
        for(Edge* edge_ptr: node_ptr->getOutputEdges()){
            Node *to_node_ptr = edge_ptr->toNode();
            to_node_ptr->touch();
            int cur_level = to_node_ptr->getLevel(); 
           // std::cout << to_peak_ptr->getID() <<  " " <<to_peak_ptr->getInputEdges().size() << " " << to_peak_ptr->getTouched()<< std::endl;
            assertm( to_node_ptr->getTouched()  <= to_node_ptr->getInputEdges().size()+10, "The descripted graph is circular");
            walk(to_node_ptr,level+1);
        }
    }

    void Graph::logStatus()
    {
        std::cout << "Number of peaks: " << node_map.size() << std::endl;
        std::cout << "Number of edges: " << edge_pool.size() << std::endl;
    }

    void Graph::buildRenderedGraph()
    {
        for(auto pair : node_map){
            Node *peak = pair.second;
            std::string label = peak->getID()+"("+std::to_string(peak->getLevel())+")";
            peak->setRenderNode(Renderer::instance().createRenderNode(peak->getID(), label));
        }
        for(auto pair : node_map){
            Node *peak = pair.second;
            EdgePtrs &eptrs = peak->getOutputEdges();
            for(Edge*e : eptrs){
                Node* p2 = e->toNode();
                Renderer::instance().renderEdge(*peak->getRenderNode(), *p2->getRenderNode());
            } 
        }
    }

    void Graph::show()
    {
        assert(maxLevel >= 0);
    }

    Graph::~Graph(){
        for(auto &e : node_map){
            delete e.second;
        }
    }
}