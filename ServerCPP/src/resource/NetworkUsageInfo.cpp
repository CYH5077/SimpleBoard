#include "resource/NetworkUsageInfo.hpp"

NetworkUsageInfo::NetworkUsageInfo() {

}

NetworkUsageInfo::~NetworkUsageInfo() {

}

void NetworkUsageInfo::setSendSizePerSecond(int sendSizePerSecond) {
    this->sendSizePerSecond = sendSizePerSecond;
}

void NetworkUsageInfo::setRecvSizePerSecond(int recvSizePerSecond) {
    this->recvSizePerSecond = recvSizePerSecond;
}

void NetworkUsageInfo::setSendPacketPerSecond(int sendPacketPerSecond) {
    this->sendPacketPerSecond = sendPacketPerSecond;
}

void NetworkUsageInfo::setRecvPacketPerSecond(int recvPacketPerSecond) {
    this->recvPacketPerSecond = recvPacketPerSecond;
}

int NetworkUsageInfo::getSendSizePerSecond() {
    return this->sendSizePerSecond;
}

int NetworkUsageInfo::getRecvSizePerSecond() {
    return this->recvSizePerSecond;
}

int NetworkUsageInfo::getTotalSizePerSecond() {
    return this->sendSizePerSecond + this->recvSizePerSecond;
}

int NetworkUsageInfo::getSendPacketPerSecond() {
    return this->sendPacketPerSecond;
}

int NetworkUsageInfo::getRecvPacketPerSecond() {
    return this->recvPacketPerSecond;
}

int NetworkUsageInfo::getTotalPacketPerSecond() {
    return this->sendPacketPerSecond + this->recvPacketPerSecond;
}