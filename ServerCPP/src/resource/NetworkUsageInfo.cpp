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

void NetworkUsageInfo::setMaximumSendSize(int sendSize) {
    this->maximumSendSize = sendSize;
}

void NetworkUsageInfo::setMaximumRecvSize(int recvSize) {
    this->maximumRecvSize = recvSize;
}

void NetworkUsageInfo::setMaximumSendPacket(int sendPacket) {
    this->maximumSendPacket = sendPacket;
}

void NetworkUsageInfo::setMaximumRecvPacket(int recvPacket) {
    this->maximumRecvPacket = recvPacket;
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

int NetworkUsageInfo::getMaximumSendSize() {
    return this->maximumSendSize;
}

int NetworkUsageInfo::getMaximumRecvSize() {
    return this->maximumRecvSize;
}

int NetworkUsageInfo::getMaximumTotalSize() {
    return this->maximumSendSize + this->maximumRecvSize;
}

int NetworkUsageInfo::getMaximumSendPacket() {
    return this->maximumSendPacket;
}

int NetworkUsageInfo::getMaximumRecvPacket() {
    return this->maximumRecvPacket;
}

int NetworkUsageInfo::getMaximumTotalPacket() {
    return this->maximumSendPacket + this->maximumRecvPacket;
}