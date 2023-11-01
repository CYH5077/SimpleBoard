#pragma once

class NetworkUsageInfo {
public:
    explicit NetworkUsageInfo();
    virtual ~NetworkUsageInfo();

public:
    // Setter
    void setSendSize(int sendSize);
    void setRecvSize(int recvSize);
    
    void setSendPacket(int sendPacket);
    void setRecvPacket(int recvPacket);


    // Getter
    int getSendSize(); // 초당 보낸 데이터 크기
    int getRecvSize(); // 초당 받은 데이터 크기
    int getTotalSize(); // 초당 보내고 받은 데이터의 크기
    
    int getSendPacket(); // 초당 보낸 패킷의 개수
    int getRecvPacket(); // 초당 받은 패킷의 개수
    int getTotalPacket(); // 초당 보내가 받은 패킷의 개수

private:
    // 초당 보내고 받은 데이터의 크기
    int sendSize;
    int recvSize;

    // 초당 보내고 받은 패킷
    int sendPacket;
    int recvPacket;
};