#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <array>
#include <sstream>
#include "../Socket/socket.hpp"

/*
- Responsibilities:
Handle socket interactions through its Socket member (which can be TCP or UDP).
*/
class Channel
{
protected:
    Socket *channelSocket; // A pointer to a Socket object (either TCPSocket or UDPSocket).

public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void send(const std::string &message) = 0;
    virtual void receive() = 0;
};

class serverChannel : public Channel
{
public:
    explicit serverChannel(Socket *socket)
    {
        this->channelSocket = socket; // Set the base class pointer
    }

    void start() override;
    void stop() override;
    void send(const std::string &message) override;
    void receive() override;
};

class clientChannel : public Channel
{
private:
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket socket{io_context}; // Declared and initialized properly
    std::array<char, 1024> buffer;
    int sockfd;
    struct sockaddr_in servaddr;
    struct ip_mreq mreq;

public:
    clientChannel() : socket(io_context) {} // Initialize socket with io_context
    void start() override;
    void stop() override;
    void send(const std::string &message) override;
    void receive() override;
};

#endif