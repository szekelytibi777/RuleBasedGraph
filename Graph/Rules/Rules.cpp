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
        std::ifstream input_stream(file_name);
       // input_stream.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
       try{
            unsigned num_of_rules = countLines(input_stream) + 1;
            std::string line;
            input_stream.seekg(0);
            std::size_t pos = input_stream.tellg();
            do
            {
                getline(input_stream, line);
                if(line.empty())
                    continue;
                RuleType rt = parseRuleType(line);
                std::vector<std::string> subgraphDescriptors = parseSubGraphDescriptors(line);
                assert((subgraphDescriptors.size() > 0 && subgraphDescriptors.size() <= 2) && "Rule descriptor must contains one or two subgraphs");
                SubGraph *oldSubGraph = 0;
                SubGraph *newSubGraph = 0;
                if(subgraphDescriptors.size() > 0){
                    oldSubGraph = new SubGraph(graph, subgraphDescriptors[0]);
                    subGraphs.push_back(oldSubGraph);
                }
                if(subgraphDescriptors.size() > 1){
                    newSubGraph = new SubGraph(graph, subgraphDescriptors[1]);
                    subGraphs.push_back(newSubGraph);
                }
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

            }while(!input_stream.eof()) ;
            input_stream.close();
        }
        catch(std::ifstream::failure e){
            input_stream.close();
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
        else if(name == "delete")
            return Rules::RuleType::Delete;
        else if(name == "insert")
            return Rules::RuleType::Insert;

        return Rules::RuleType::None;
    }

    std::vector<std::string> Rules::parseSubGraphDescriptors(std::string line)
    {
        std::vector<std::string> descriptors;
        size_t pos = 0;
        do{
            size_t startIndex = line.find("{", pos);

            size_t endIndex = line.find("}", startIndex);
            pos = endIndex;
            if( pos == std::string::npos)
                break;
            std::string descriptor = line.substr(startIndex+1, endIndex-startIndex-1);
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

        for(SubGraph* subGraph : subGraphs){
            delete subGraph;
        }
    }
}