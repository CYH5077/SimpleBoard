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
    
    void setMaximumSendSize(int sendSize);
    void setMaximumRecvSize(int recvSize);
    void setMaximumSendPacket(int sendPacket);
    void setMaximumRecvPacket(int recvPacket);


    // Getter
    int getSendSize(); // 초당 보낸 데이터 크기
    int getRecvSize(); // 초당 받은 데이터 크기
    int getTotalSize(); // 초당 보내고 받은 데이터의 크기
    int getSendPacket(); // 초당 보낸 패킷의 개수
    int getRecvPacket(); // 초당 받은 패킷의 개수
    int getTotalPacket(); // 초당 보내가 받은 패킷의 개수

    int getMaximumSendSize();
    int getMaximumRecvSize();
    int getMaximumTotalSize();
    int getMaximumSendPacket();
    int getMaximumRecvPacket();
    int getMaximumTotalPacket();
    
private:
    // 초당 보내고 받은 데이터의 크기
    int sendSize;
    int recvSize;

    // 초당 보내고 받은 패킷
    int sendPacket;
    int recvPacket;

    // 최대 최소값 NetworkResource::readNetworkUsageInfoPerSecond() 함수 에서 
    // 계속해서 같은 NetworkUsageInfo 인스턴스를 사용해여 위의 함수를 호출하면 해당 값이 초기화됨
    int maximumSendSize; // 수신 최고기록
    int maximumRecvSize; // 송신 최고기록
    int maximumSendPacket; // 수신 패킷 최고기록
    int maximumRecvPacket; // 송신 패킷 최고기록
};