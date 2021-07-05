#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BaseRule.hpp"

namespace Graph
{
    class Rules{
        public:
            
            Rules(Graph *graph, const std::string &file_name);
            ~Rules();
            bool applyAll();

            enum RuleType{
                None,
                Replace,
                Shortcut,
                Insert,
                Delete
            };
        private:
            std::vector<BaseRule*> rules;
            Graph *graph_;
            RuleType parseRuleType(const std::string line);
            std::vector<std::string> parseSubGraphDescriptor(std::string line);
    };
}