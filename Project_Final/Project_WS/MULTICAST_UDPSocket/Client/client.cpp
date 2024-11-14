#include "client.hpp"

/*
- Function to initialize the socket with TCP
- DOMAIN: AF_INET for IPv4
- TYPE: SOCK_STREAM for TCP - SOCK_DGRAM for UDP
- PROTOCOL: set to 0 -> lets the system choose the appropriate protocol (TCP or UDP)
*/
void clientChannel::start()
{
    // Create a UDP socket
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
        stop();
        return;
    }

    // Bind to the local address and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        std::cerr << "Bind failed" << std::endl;
        stop();
        return;
    }

    // Join the multicast group
    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr(MULTICAST_GROUP);
    mreq.imr_interface.s_addr = inet_addr("192.168.7.1"); // Interface IP (tap0 address)
    if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0)
    {
        std::cerr << "Failed to join multicast group" << std::endl;
        stop();
        return;
    }

    std::cout << "Joined multicast group: " << MULTICAST_GROUP << std::endl;
}


void clientChannel::receive()
{
    // Receive messages from the multicast group
    while (true)
    {
        buffer.fill(0);
        int len = recvfrom(sockfd, buffer.data(), buffer.size(), 0, nullptr, nullptr);
        if (len < 0)
        {
            std::cerr << "Receive failed" << std::endl;
            break;
        }
        std::cout << "Received message: " << buffer.data() << std::endl;
    }
}

void clientChannel::send(const std::string &message)
{
    std::cout << " " << std::endl;
}

void clientChannel::stop()
{
    // Leave the multicast group and close the socket
    setsockopt(sockfd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
    close(sockfd);
    std::cout << "Client disconnected from " << MULTICAST_GROUP << std::endl;
}
