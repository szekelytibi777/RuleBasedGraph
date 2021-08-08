#ifdef GRAPHVIZ_RENDERER
#include <cassert>
#include "Renderer.hpp"  


namespace Graph
{

    Renderer * Renderer::instance_ = 0;
    Renderer::Renderer()
        : graph(true, "AIMOTIVE")
    {
        Renderer::instance_ = this;
    }

    Renderer& Renderer::instance()
    {
        assert(instance_);
        return *Renderer::instance_;
    }

    void Renderer::show()
    {
         renderToFile(graph, "dot", "x11");
    }

    gvpp::Node<char>* Renderer::createRenderNode(const std::string &id, const std::string &label)
    {
    #ifndef _GLIBCXX_DEBUG
        gvpp::Node<char> &n = graph.addNode(id, label,false);
        return &n;
    #else
        return 0;
    #endif
    }

    void Renderer::renderEdge(gvpp::Node<> &n_from, gvpp::Node<> &n_to)
    {
       graph.addEdge(n_from, n_to);
    }
}
#endif
