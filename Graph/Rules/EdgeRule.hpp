#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class EdgeRule : public BaseRule{
        public:
            EdgeRule(Graph &graph, SubGraph &original, SubGraph *modified = 0);
            ~EdgeRule();
            bool process() override;
    };
}