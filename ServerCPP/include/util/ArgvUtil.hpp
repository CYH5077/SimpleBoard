#pragma once

#include <iostream>
#include <vector>

#include "util/ArgvItem.hpp"

class ArgvUtil {
public:
    static ArgvUtil* getInstance();

public:
    void setArgument(int argc, const char* argv[]);

    bool isValidOption(std::string& option);
    bool getValue(std::string& option, ArgvItem* argvItem);

private:
    bool isOption(const char* option);


private:
    explicit ArgvUtil();
    virtual ~ArgvUtil();

private:
    static ArgvUtil instance;

    std::vector<ArgvItem> argvList;
};
