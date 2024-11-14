#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Socket
{
protected:
    std::array<char, 1024> buffer;

public:
    virtual ~Socket() = default;
    virtual void connect() = 0;
    virtual void send(const std::string &message) = 0;
    virtual void receive() = 0;
    virtual void shutdown() = 0;
};

class TCPSocket : public Socket
{
private:
    boost::asio::io_context io_context;  // io_context for asynchronous operations
    boost::asio::ip::tcp::socket socket; // TCP socket

public:
    // Constructor initializes socket with the io_context
    TCPSocket() : socket(io_context) {}
    void connect() override;
    void send(const std::string &message) override;
    void receive() override;
    void shutdown() override;
    virtual ~TCPSocket() = default;
};

class UDPSocket : public Socket
{
private:
    int sockfd;
    struct sockaddr_in servaddr;

public:
    void connect() override;
    void send(const std::string &message) override;
    void receive() override;
    void shutdown() override;
    virtual ~UDPSocket() = default;
};

#endif
