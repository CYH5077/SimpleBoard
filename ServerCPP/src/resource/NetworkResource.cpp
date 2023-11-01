#include "resource/NetworkResource.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

NetworkResource::NetworkResource() {
    
}

NetworkResource::~NetworkResource() {

}

bool NetworkResource::readNetworkUsageInfo(NetworkUsageInfo* networkUsageInfo, Result* result) {
    if (networkUsageInfo == nullptr ||
        result           == nullptr) {
            return false;
        }

    return result->success();
}

bool NetworkResource::getNetworkInterface(NetworkInterfaceList* interfaceList, Result* result) {
    if (interfaceList == nullptr ||
        result        == nullptr) {
            return false;
    }

    return this->getNetworkInterfaceList(interfaceList, result);
}

bool NetworkResource::getNetworkInterfaceList(NetworkInterfaceList* interfaceList, Result* result) {
    std::filesystem::path interfaceListPath = "/sys/class/net";
    try {
        if (std::filesystem::exists(interfaceListPath) &&
            std::filesystem::is_directory(interfaceListPath)) {
                for (const auto& entry : std::filesystem::directory_iterator(interfaceListPath)) {
                    interfaceList->push_back(entry.path().filename().string());
                }
        }
    } catch (std::filesystem::filesystem_error& error) {
        return result->failed(-1, interfaceListPath.string() + " 경로 탐색중 오류가 발생했습니다. 오류 내용: " + error.what());
    }
    
    return result->success();
}