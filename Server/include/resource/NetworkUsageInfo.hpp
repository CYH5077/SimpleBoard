#pragma once

class NetworkUsageInfo {
public:
    explicit NetworkUsageInfo();
    explicit NetworkUsageInfo(const NetworkUsageInfo& usageInfo);
    virtual ~NetworkUsageInfo();

public:
    // Setter
    void setSendSize(const int sendSize);
    void setRecvSize(const int recvSize);
    void setSendPacket(const int sendPacket);
    void setRecvPacket(const int recvPacket);
    
    void setMaximumSendSize(const int sendSize);
    void setMaximumRecvSize(const int recvSize);
    void setMaximumSendPacket(const int sendPacket);
    void setMaximumRecvPacket(const int recvPacket);


    // Getter
    int getSendSize() const; // 초당 보낸 데이터 크기
    int getRecvSize() const; // 초당 받은 데이터 크기
    int getTotalSize() const; // 초당 보내고 받은 데이터의 크기
    int getSendPacket() const; // 초당 보낸 패킷의 개수
    int getRecvPacket() const; // 초당 받은 패킷의 개수
    int getTotalPacket() const; // 초당 보내가 받은 패킷의 개수

    int getMaximumSendSize() const;
    int getMaximumRecvSize() const;
    int getMaximumTotalSize() const;
    int getMaximumSendPacket() const;
    int getMaximumRecvPacket() const;
    int getMaximumTotalPacket() const;
    
public:
    NetworkUsageInfo& operator=(const NetworkUsageInfo& usageInfo) {
        this->sendSize = usageInfo.sendSize;
        this->recvSize = usageInfo.recvSize;

        this->sendPacket = usageInfo.sendPacket;
        this->recvPacket = usageInfo.recvPacket;
        
        return *this;
    }

private:
    // 초당 보내고 받은 데이터의 크기
    int sendSize;
    int recvSize;

    // 초당 보내고 받은 패킷
    int sendPacket;
    int recvPacket;

    // 아래 값들은 객체 대입 연산자 사용시 복사가 되지 않음.
    // 최대 최소값 SystemUsageInfo::calcNetworkUsageMaximum() 함수 에서 
    // 계속해서 같은 NetworkUsageInfo 인스턴스를 사용해여 위의 함수를 호출하면 해당 값이 초기화됨
    int maximumSendSize; // 수신 최고기록
    int maximumRecvSize; // 송신 최고기록
    int maximumSendPacket; // 수신 패킷 최고기록
    int maximumRecvPacket; // 송신 패킷 최고기록
};