#pragma once

#include <vector>
#include <string>

class NetworkInterfaceList : public std::vector<std::string> {
public:
    explicit NetworkInterfaceList();
    virtual ~NetworkInterfaceList();
};