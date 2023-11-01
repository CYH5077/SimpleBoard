#pragma once

#include "resource/NetworkUsageInfo.hpp"
#include "resource/NetworkInterfaceList.hpp"
#include "util/Result.hpp"

#include <vector>
#include <string>

class NetworkResource {
public:
    explicit NetworkResource();
    virtual ~NetworkResource();

public:
    bool readNetworkUsageInfo(NetworkUsageInfo* networkUsageInfo, Result* result);

    bool getNetworkInterface(NetworkInterfaceList* interfaceList, Result* result);

private:
    bool getNetworkInterfaceList(NetworkInterfaceList* interfaceList, Result* result);

};