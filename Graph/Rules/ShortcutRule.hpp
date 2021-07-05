#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class ShortCutRule : public BaseRule{
        public:
            ShortCutRule(Graph &graph, SubGraph &original, SubGraph *modified);
            ~ShortCutRule();
            bool process() override;
    };
}