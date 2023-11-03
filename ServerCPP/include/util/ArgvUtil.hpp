#pragma once

#include <iostream>
#include <vector>

#include "util/ArgvItemList.hpp"
#include "util/ArgvItem.hpp"

class ArgvUtil {
public:
    explicit ArgvUtil();
    virtual ~ArgvUtil();

public:
    void setArgument(int argc, const char* argv[]);

    bool isEmpty();
    bool isValidOption(const std::string& option);
    bool getValue(const std::string& option, ArgvItem* argvItem);
    bool getValue(const std::string& option, std::string* value);
    
private:
    bool isOption(const char* option);

private:
    ArgvItemList argvList;
};
