#include "resource/NetworkResource.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <thread>
#include <chrono>

const std::string NetworkResource::NETWORK_INTERFACE_PATH = "/sys/class/net";
const std::string NetworkResource::NETWORK_SEND_BYTES_FILE_NAME = "statistics/tx_bytes";
const std::string NetworkResource::NETWORK_RECV_BYTES_FILE_NAME = "statistics/rx_bytes";
const std::string NetworkResource::NETWORK_SEND_PACKET_FILE_NAME = "statistics/tx_packets";
const std::string NetworkResource::NETWORK_RECV_PACKET_FILE_NAME = "statistics/rx_packets";

NetworkResource::NetworkResource() {
    
}

NetworkResource::~NetworkResource() {

}

bool NetworkResource::readNetworkUsageInfoPerSecond(std::string& networkInterfaceName, NetworkUsageInfo* networkUsageInfo, Result* result) {
    if (networkUsageInfo == nullptr ||
        result           == nullptr) {
        return false;
    }

    NetworkUsageInfo beforeUsageInfo;
    NetworkUsageInfo afterUsageInfo;
    if (!this->readNetworkUsageInfoFiles(networkInterfaceName, &beforeUsageInfo, result)) {
        return result->isSuccess();
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (!this->readNetworkUsageInfoFiles(networkInterfaceName, &afterUsageInfo, result)) {
        return result->isSuccess();
    }

    this->calcNetworkUsagePerSecond(beforeUsageInfo, afterUsageInfo, networkUsageInfo);
    this->calcNetworkUsageMaximum(networkUsageInfo);

    return result->success();
}

bool NetworkResource::getNetworkInterface(NetworkInterfaceList* interfaceList, Result* result) {
    if (interfaceList == nullptr ||
        result        == nullptr) {
        return false;
    }

    return this->getNetworkInterfaceList(interfaceList, result);
}

bool NetworkResource::readNetworkUsageInfoFiles(std::string& networkInterfaceName, NetworkUsageInfo* networkUsageInfo, Result* result) {
    int value = 0;

    std::string sendSizeFilePath = this->getUsageSendSizePath(networkInterfaceName);
    if (!this->readUsageInfo(sendSizeFilePath, &value, result)) {
        return result->isSuccess();
    }
    networkUsageInfo->setSendSize(value);

    std::string recvSizeFilePath = this->getUsageRecvSizePath(networkInterfaceName);
    if (!this->readUsageInfo(recvSizeFilePath, &value, result)) {
        return result->isSuccess();
    }
    networkUsageInfo->setRecvSize(value);

    std::string sendPacketFilePath = this->getUsageSendPacketPath(networkInterfaceName);
    if (!this->readUsageInfo(sendPacketFilePath, &value, result)) {
        return result->isSuccess();
    }
    networkUsageInfo->setSendPacket(value);

    std::string recvPacketFilePath = this->getUsageRecvPacketPath(networkInterfaceName);
    if (!this->readUsageInfo(recvPacketFilePath, &value, result)) {
        return result->isSuccess();
    }
    networkUsageInfo->setRecvPacket(value);

    return result->success();
}

bool NetworkResource::readUsageInfo(std::string& path, int* value, Result* result) {
    if (value  == nullptr ||
        result == nullptr) {
        return false;
    }

    std::ifstream inputFileStream(path);
    if (!inputFileStream.is_open()) {
        return result->failed(-1, path + " 파일을 열지 못했습니다.");
    }

    std::string readLine;
    std::getline(inputFileStream, readLine);
    *value = std::stoi(readLine);

    return result->success();
}

std::string NetworkResource::getUsageSendSizePath(std::string& interfaceName) {
    return this->NETWORK_INTERFACE_PATH + "/" + interfaceName + "/" + this->NETWORK_SEND_BYTES_FILE_NAME;
}

std::string NetworkResource::getUsageRecvSizePath(std::string& interfaceName) {
    return this->NETWORK_INTERFACE_PATH + "/" + interfaceName + "/" + this->NETWORK_RECV_BYTES_FILE_NAME;
}

std::string NetworkResource::getUsageSendPacketPath(std::string& interfaceName) {
    return this->NETWORK_INTERFACE_PATH + "/" + interfaceName + "/" + this->NETWORK_SEND_PACKET_FILE_NAME;
}

std::string NetworkResource::getUsageRecvPacketPath(std::string& interfaceName) {
    return this->NETWORK_INTERFACE_PATH + "/" + interfaceName + "/" + this->NETWORK_RECV_PACKET_FILE_NAME;
}

bool NetworkResource::getNetworkInterfaceList(NetworkInterfaceList* interfaceList, Result* result) {
    std::filesystem::path interfaceListPath = this->NETWORK_INTERFACE_PATH;
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

void NetworkResource::calcNetworkUsagePerSecond(NetworkUsageInfo& beforeUsageInfo, NetworkUsageInfo& afterUsageInfo, NetworkUsageInfo* networkUsageInfo) {
    int sendSize = afterUsageInfo.getSendSize() - beforeUsageInfo.getSendSize();
    int recvSize = afterUsageInfo.getRecvSize() - beforeUsageInfo.getRecvSize();
    int sendPacket = afterUsageInfo.getSendPacket() - beforeUsageInfo.getSendPacket();
    int recvPacket = afterUsageInfo.getRecvPacket() - beforeUsageInfo.getRecvPacket();

    networkUsageInfo->setSendSize(sendSize);
    networkUsageInfo->setRecvSize(recvSize);
    networkUsageInfo->setSendPacket(sendPacket);
    networkUsageInfo->setRecvPacket(recvPacket);
}

void NetworkResource::calcNetworkUsageMaximum(NetworkUsageInfo* usageInfo) {
    int sendSize = usageInfo->getSendSize() >= usageInfo->getMaximumSendSize() ? usageInfo->getSendSize() : usageInfo->getMaximumSendSize();
    int recvSize = usageInfo->getRecvSize() >= usageInfo->getMaximumRecvSize() ? usageInfo->getRecvSize() : usageInfo->getMaximumRecvSize();
    int sendPacket = usageInfo->getSendPacket() >= usageInfo->getMaximumSendPacket() ? usageInfo->getSendPacket() : usageInfo->getMaximumSendPacket();
    int recvPacket = usageInfo->getRecvPacket() >= usageInfo->getMaximumRecvPacket() ? usageInfo->getRecvPacket() : usageInfo->getMaximumRecvPacket();

    usageInfo->setMaximumSendSize(sendSize);
    usageInfo->setMaximumRecvSize(recvSize);
    usageInfo->setMaximumSendPacket(sendPacket);
    usageInfo->setMaximumRecvPacket(recvPacket);
}