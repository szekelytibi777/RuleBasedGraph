#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class AddRule : public BaseRule{
        public:
            AddRule(Graph &graph, SubGraph &original, SubGraph *modified);
            ~AddRule();
            bool process() override;
    };
}