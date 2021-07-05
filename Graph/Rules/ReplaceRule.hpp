#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class ReplaceRule : public BaseRule{
        public:
            ReplaceRule(Graph &graph, SubGraph &original, SubGraph *modified);
            ~ReplaceRule();
            bool process() override;
    };
}