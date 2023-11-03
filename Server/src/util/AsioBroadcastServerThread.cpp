#include "util/AsioBroadcastServerThread.hpp"

using boost::asio::ip::tcp;

AsioBroadcastServerThread::AsioBroadcastServerThread(int servicePort) {
    this->servicePort = servicePort;
    this->isIOContextRunning = false;
}

AsioBroadcastServerThread::~AsioBroadcastServerThread() {

}

void AsioBroadcastServerThread::run(Result* returnValue, Result* result) {
    if (!this->createAcceptor(result)) {
        return;
    }

    if (!this->serviceStart(result)) {
        return;
    }

    result->success();
}

void AsioBroadcastServerThread::broadcast(ByteBuffer& data, ResultList* resultList) {
    for (auto& iter : this->sessionList) {
        Result result;
        if (!iter->send(data, &result)) {
            resultList->push_back(result);
            {
                std::lock_guard lock(this->sessionListMutex);
                this->sessionList.removeSession(iter);
            }
        }
    }
}

bool AsioBroadcastServerThread::isRunning() {
    return this->isIOContextRunning;
}

void AsioBroadcastServerThread::stop() {
    this->ioContext.stop();
    this->isIOContextRunning = false;
}

void AsioBroadcastServerThread::asyncAcceptStart() {
    this->acceptor->async_accept(
        [&](boost::system::error_code errorCode, tcp::socket socket) {
            if (!errorCode) {
                {
                    std::lock_guard(this->sessionListMutex);
                    this->sessionList.push_back(std::make_shared<AsioSession>(std::move(socket)));
                }
            }
            this->asyncAcceptStart();
        }
        
    );
}

bool AsioBroadcastServerThread::createAcceptor(Result* result) {
    try {
        this->acceptor = std::make_shared<tcp::acceptor>(this->ioContext, tcp::endpoint(tcp::v4(), this->servicePort));
    } catch (std::bad_alloc& e) {
        return result->failed(-1, e.what());
    }

    this->asyncAcceptStart();

    return result->success();
}

bool AsioBroadcastServerThread::serviceStart(Result* result) {
    try {
        this->isIOContextRunning = true;
        this->ioContext.run();
    } catch (std::exception& e) {
        return result->failed(-1, e.what());
    }

    return result->success();
}