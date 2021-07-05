#include "../Rules/Rules.hpp"  
#include "../../Utils.hpp"
#include "../SubGraph.hpp"
#include "ShortcutRule.hpp"
#include "ReplaceRule.hpp"
#include "DeleteRule.hpp"
#include "InsertRule.hpp"
	
namespace Graph
{

    Rules::Rules(Graph *graph, const std::string &file_name)
        : graph_(graph)
    {
        if(file_name.empty())
            return;
        std::ifstream input_stream;
        input_stream.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
            input_stream.open(file_name, std::ifstream::in);
            unsigned num_of_rules = countLines(input_stream) + 1;
            std::string line;
            do
            {
                std::getline(input_stream, line);
                RuleType rt = parseRuleType(line);
                std::vector<std::string> subgraphDescriptors = parseSubGraphDescriptor(line);
                assert((subgraphDescriptors.size() > 0 && subgraphDescriptors.size() < 2) && "Rule descriptor must contains one or two subgraphs");
                SubGraph *oldSubGraph = 0;
                SubGraph *newSubGraph = 0;
                if(subgraphDescriptors.size() > 0)
                    oldSubGraph = new SubGraph(graph, subgraphDescriptors[0]);
                if(subgraphDescriptors.size() > 1)
                    newSubGraph = new SubGraph(graph, subgraphDescriptors[1]);
                BaseRule *rulePtr = 0;
                switch(rt){
                    case Replace:
                        rulePtr = new ReplaceRule(*graph, *oldSubGraph, newSubGraph);
                    break;
                    case Shortcut:
                        rulePtr = new ShortCutRule(*graph, *oldSubGraph, newSubGraph);
                    break;
                    case Insert:
                        rulePtr = new InsertRule(*graph, *oldSubGraph, newSubGraph);
                    break;
                    case Delete:
                        rulePtr = new DeleteRule(*graph, *oldSubGraph);
                    break;
                    default:
                    break;
                }
                if(rulePtr)
                    rules.push_back(rulePtr);

                assert(0 && "lifecicle of SubGraph instance is not implemented!");
                //TODO: implement lifecicle of SubGraph instance is not implemented
            } while (!input_stream.eof());
            input_stream.close();
        }
        catch(std::ifstream::failure e){
            throw (e);
        }
    }

    Rules::RuleType Rules::parseRuleType(const std::string line)
    {
        std::string name = line.substr(0, line.find(':'));
        if(name == "replace")
            return Rules::RuleType::Replace;
        else if(name == "shortcut")
            return Rules::RuleType::Shortcut;
        else if(name == "Delete")
            return Rules::RuleType::Delete;
        else if(name == "insert")
            return Rules::RuleType::Insert;

        return Rules::RuleType::None;
    }

    std::vector<std::string> Rules::parseSubGraphDescriptor(std::string line)
    {
        std::vector<std::string> descriptors;
        size_t pos = 0;
        do{
            size_t startIndex = line.find("{", pos);
            size_t endIndex = line.find("}", startIndex);
            pos = endIndex;
            std::string descriptor = line.substr(startIndex, endIndex);
            descriptors.push_back(descriptor);
        }while(pos != std::string::npos);        
        return descriptors;
    }

    bool Rules::applyAll()
    {
        bool ret = true;
        for(BaseRule* rule : rules){
            if(rule){
                ret &= rule->process();
            }
        }
        return ret;
    }   

    Rules::~Rules()
    {
        for(BaseRule* rule : rules){
            if(rule)
                delete rule;
        }
    }
}