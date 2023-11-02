#pragma once

#include <string>

class ArgvItem {
public:
    explicit ArgvItem();
    explicit ArgvItem(std::string& option, std::string& value);
    virtual ~ArgvItem();

public:
    void setOption(std::string& option);
    void setValue(std::string& value);

    const std::string& getOption() const;
    const std::string& getValue() const;

private:
    std::string option;
    std::string value;
};