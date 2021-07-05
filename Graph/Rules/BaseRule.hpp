#pragma once
#include "../SubGraph.hpp"
#include "../Graph.hpp"
namespace Graph{
    class BaseRule{
        public:
            BaseRule(Graph &graph, SubGraph &original, SubGraph *modified = 0);
            virtual ~BaseRule();
            virtual bool process() = 0;
        protected:
            Graph     &graph_;
            SubGraph  &originalPart_;
            SubGraph  *modifiedPart_;
    };
}