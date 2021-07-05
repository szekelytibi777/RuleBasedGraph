#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define assertm(exp, msg) assert(((void)msg, exp))

inline unsigned splitString(std::vector<std::string> &tokens, const std::string &str, char delimeter = ',')
{
    tokens.clear();
    std::vector<std::string> result;
    size_t i0 = 0;
    size_t i1 = 0;
    do
    {
        std::string token; 
        i1 = str.find(delimeter, i0);
        token = str.substr(i0,i1-i0);
        i0 = i1+1;
        if(!token.empty())
            tokens.push_back(token);
    } while (i1 != std::string::npos);

    return tokens.size();
}

inline unsigned countLines(std::ifstream &stream){
    unsigned count = std::count(std::istreambuf_iterator<char>(stream),  std::istreambuf_iterator<char>(), '\n'); 
    stream.clear();
    stream.seekg(0);   
    return count;
}

inline std::string getIdStr(int n, const std::string &pf = "A"){
    std::string id_str = pf+std::to_string(n);
    return id_str;
}