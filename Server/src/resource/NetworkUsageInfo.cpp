#include "resource/NetworkUsageInfo.hpp"

NetworkUsageInfo::NetworkUsageInfo() {
    this->sendSize = 0;
    this->recvSize = 0;
    this->sendPacket = 0;
    this->recvPacket = 0;

    this->maximumSendSize = 0;
    this->maximumRecvSize = 0;
    this->maximumSendPacket = 0;
    this->maximumRecvPacket = 0;
}

NetworkUsageInfo::NetworkUsageInfo(const NetworkUsageInfo& usageInfo) {
    *this = usageInfo;
}

NetworkUsageInfo::~NetworkUsageInfo() {

}

void NetworkUsageInfo::setSendSize(const int sendSize) {
    this->sendSize = sendSize;
}

void NetworkUsageInfo::setRecvSize(const int recvSize) {
    this->recvSize = recvSize;
}

void NetworkUsageInfo::setSendPacket(const int sendPacket) {
    this->sendPacket = sendPacket;
}

void NetworkUsageInfo::setRecvPacket(const int recvPacket) {
    this->recvPacket = recvPacket;
}

void NetworkUsageInfo::setMaximumSendSize(const int sendSize) {
    this->maximumSendSize = sendSize;
}

void NetworkUsageInfo::setMaximumRecvSize(const int recvSize) {
    this->maximumRecvSize = recvSize;
}

void NetworkUsageInfo::setMaximumSendPacket(const int sendPacket) {
    this->maximumSendPacket = sendPacket;
}

void NetworkUsageInfo::setMaximumRecvPacket(const int recvPacket) {
    this->maximumRecvPacket = recvPacket;
}

int NetworkUsageInfo::getSendSize() const {
    return this->sendSize;
}

int NetworkUsageInfo::getRecvSize() const {
    return this->recvSize;
}

int NetworkUsageInfo::getTotalSize() const {
    return this->sendSize + this->recvSize;
}

int NetworkUsageInfo::getSendPacket() const {
    return this->sendPacket;
}

int NetworkUsageInfo::getRecvPacket() const {
    return this->recvPacket;
}

int NetworkUsageInfo::getTotalPacket() const {
    return this->sendPacket + this->recvPacket;
}

int NetworkUsageInfo::getMaximumSendSize() const {
    return this->maximumSendSize;
}

int NetworkUsageInfo::getMaximumRecvSize() const {
    return this->maximumRecvSize;
}

int NetworkUsageInfo::getMaximumTotalSize() const {
    return this->maximumSendSize + this->maximumRecvSize;
}

int NetworkUsageInfo::getMaximumSendPacket() const {
    return this->maximumSendPacket;
}

int NetworkUsageInfo::getMaximumRecvPacket() const {
    return this->maximumRecvPacket;
}

int NetworkUsageInfo::getMaximumTotalPacket() const {
    return this->maximumSendPacket + this->maximumRecvPacket;
}