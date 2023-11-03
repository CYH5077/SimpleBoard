#include "util/AsioSession.hpp"
#include "util/AsioDefine.hpp"

AsioSession::AsioSession(boost::asio::ip::tcp::socket socket) 
: socket(std::move(socket)) {
    
}

AsioSession::~AsioSession() {

}

bool AsioSession::send(ByteBuffer& data, Result* result) {
    if (result == nullptr) {
        return false;
    }

    boost::system::error_code errorCode;
    boost::asio::write(this->socket, boost::asio::buffer(data), errorCode);
    if (errorCode) {
        return result->failed(errorCode.value(), errorCode.message());
    }

    return result->success();
}

bool AsioSession::recv(ByteBuffer* data, Result* result) {
    if (data   == nullptr ||
        result == nullptr) {
        return false;
    }

    boost::system::error_code errorCode;
    this->socket.read_some(boost::asio::buffer(*data), errorCode);
    if (errorCode) {
        return result->failed(errorCode.value(), errorCode.message());
    }

    return result->success();
}