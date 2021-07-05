#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class DeleteRule : public BaseRule{
        public:
            DeleteRule(Graph &graph, SubGraph &original);
            ~DeleteRule();
            bool process() override;
    };
}