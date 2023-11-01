#include "resource/NetworkUsageInfo.hpp"

NetworkUsageInfo::NetworkUsageInfo() {
    this->sendSize = 0;
    this->recvSize = 0;
    this->sendPacket = 0;
    this->recvPacket = 0;
}

NetworkUsageInfo::~NetworkUsageInfo() {

}

void NetworkUsageInfo::setSendSize(int sendSize) {
    this->sendSize = sendSize;
}

void NetworkUsageInfo::setRecvSize(int recvSize) {
    this->recvSize = recvSize;
}

void NetworkUsageInfo::setSendPacket(int sendPacket) {
    this->sendPacket = sendPacket;
}

void NetworkUsageInfo::setRecvPacket(int recvPacket) {
    this->recvPacket = recvPacket;
}

int NetworkUsageInfo::getSendSize() {
    return this->sendSize;
}

int NetworkUsageInfo::getRecvSize() {
    return this->recvSize;
}

int NetworkUsageInfo::getTotalSize() {
    return this->sendSize + this->recvSize;
}

int NetworkUsageInfo::getSendPacket() {
    return this->sendPacket;
}

int NetworkUsageInfo::getRecvPacket() {
    return this->recvPacket;
}

int NetworkUsageInfo::getTotalPacket() {
    return this->sendPacket + this->recvPacket;
}