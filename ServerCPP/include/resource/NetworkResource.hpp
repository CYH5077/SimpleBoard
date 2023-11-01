#pragma once

#include "resource/NetworkUsageInfo.hpp"
#include "resource/NetworkInterfaceList.hpp"
#include "util/Result.hpp"

#include <string>

class NetworkResource {
public:
    explicit NetworkResource();
    virtual ~NetworkResource();

public:
    bool readNetworkUsageInfoPerSecond(std::string& networkInterfaceName, NetworkUsageInfo* networkUsageInfo, Result* result);
    bool readNetworkUsageInfo(std::string& networkInterfaceName, NetworkUsageInfo* networkUsageInfo, Result* result);

    bool getNetworkInterface(NetworkInterfaceList* interfaceList, Result* result);

public:
    static const std::string NETWORK_INTERFACE_PATH;
    static const std::string NETWORK_SEND_BYTES_FILE_NAME;
    static const std::string NETWORK_RECV_BYTES_FILE_NAME;
    static const std::string NETWORK_SEND_PACKET_FILE_NAME;
    static const std::string NETWORK_RECV_PACKET_FILE_NAME;

private:
    // 네트워크 정보 파일을 읽음.
    bool readNetworkUsageInfoFiles(std::string& networkInterfaceName, NetworkUsageInfo* networkUsageInfo, Result* result);
    bool readUsageInfo(std::string& path, int* value, Result* result);

    // 네트워크 트래픽 관련 파일 경로
    std::string getUsageSendSizePath(std::string& interfaceName);
    std::string getUsageRecvSizePath(std::string& interfaceName);
    std::string getUsageSendPacketPath(std::string& interfaceName);
    std::string getUsageRecvPacketPath(std::string& interfaceName);

    // 네트워크 인터페이스 리스트를 가져옴
    bool getNetworkInterfaceList(NetworkInterfaceList* interfaceList, Result* result);

    void calcNetworkUsagePerSecond(NetworkUsageInfo& beforeUsageInfo, NetworkUsageInfo& afterUsageInfo, NetworkUsageInfo* networkUsageInfo);
};