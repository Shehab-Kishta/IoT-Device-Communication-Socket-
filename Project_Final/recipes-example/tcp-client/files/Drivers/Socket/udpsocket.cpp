#include "socket.hpp"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MULTICAST_GROUP "239.0.0.1"

/*
- Function to initialize the socket with TCP
- DOMAIN: AF_INET for IPv4
- TYPE: SOCK_STREAM for TCP - SOCK_DGRAM for UDP
- PROTOCOL: set to 0 -> lets the system choose the appropriate protocol (TCP or UDP)
*/
void UDPSocket::connect()
{
    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Socket creation failed" << std::endl;
        return;
    }

    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse)) < 0)
    {
        std::cerr << "Setting SO_REUSEADDR failed" << std::endl;
        shutdown();
        return;
    }

    // Set TTL (Time to Live) for the multicast packet
    unsigned char ttl = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl)) < 0)
    {
        std::cerr << "Failed to set TTL" << std::endl;
        shutdown();
        return;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(MULTICAST_GROUP);
    servaddr.sin_port = htons(PORT);
}

// Send a message to a specified address and port
void UDPSocket::send(const std::string &message)
{
    // Send a message to the multicast group in a loop
    sendto(sockfd, message.data(), message.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Message sent: " << message << std::endl;
}

// Receive a message from any sender
void UDPSocket::receive()
{
    std::cout << "S" << std::endl;
}

// Close the socket
void UDPSocket::shutdown()
{
    close(sockfd);
    std::cout << "Server disconnected from " << MULTICAST_GROUP << std::endl;
}
