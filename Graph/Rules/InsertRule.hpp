#pragma once
#include "BaseRule.hpp"
namespace Graph{
    class InsertRule : public BaseRule{
        public:
            InsertRule(Graph &graph, SubGraph &original, SubGraph *modified);
            ~InsertRule();
            bool process() override;
    };
}