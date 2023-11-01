#pragma once

class NetworkUsageInfo {
public:
    explicit NetworkUsageInfo();
    virtual ~NetworkUsageInfo();

public:
    // Setter
    void setSendSizePerSecond(int sendSizePerSecond);
    void setRecvSizePerSecond(int recvSizePerSecond);
    
    void setSendPacketPerSecond(int sendPacketPerSecond);
    void setRecvPacketPerSecond(int recvPacketPerSecond);


    // Getter
    int getSendSizePerSecond(); // 초당 보낸 데이터 크기
    int getRecvSizePerSecond(); // 초당 받은 데이터 크기
    int getTotalSizePerSecond(); // 초당 보내고 받은 데이터의 크기
    
    int getSendPacketPerSecond(); // 초당 보낸 패킷의 개수
    int getRecvPacketPerSecond(); // 초당 받은 패킷의 개수
    int getTotalPacketPerSecond(); // 초당 보내가 받은 패킷의 개수

private:
    // 초당 보내고 받은 데이터의 크기
    int sendSizePerSecond;
    int recvSizePerSecond;

    // 초당 보내고 받은 패킷
    int sendPacketPerSecond;
    int recvPacketPerSecond;
};