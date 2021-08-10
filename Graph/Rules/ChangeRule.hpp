#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class ChangeRule : public BaseRule{
        public:
            ChangeRule(Graph &graph, SubGraph &original, SubGraph *modified);
            ~ChangeRule();
            bool process() override;
    };
}