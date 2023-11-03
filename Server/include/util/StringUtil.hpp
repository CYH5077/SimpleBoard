#pragma once

#include <string>

class StringUtil {
public:
    explicit StringUtil();
    virtual ~StringUtil();

public:
    static std::string removeFirstOf(std::string& str, char token);
    static std::string removeLastOf(std::string& str, char token);
    
    static std::string removeFirstSpace(std::string& str);
    static std::string removeLastSpace(std::string& str);
    static std::string removeLastTab(std::string& str);
};