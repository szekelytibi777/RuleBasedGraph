#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class NewNodesRule : public BaseRule{
        public:
            NewNodesRule(Graph &graph, SubGraph &original, SubGraph *modified);
            ~NewNodesRule();
            bool process() override;
    };
}