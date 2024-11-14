#include "channel.hpp"

void serverChannel::start()
{
    if (channelSocket)
        channelSocket->connect();
}

void serverChannel::stop()
{
    if (channelSocket)
        channelSocket->shutdown();
}

void serverChannel::send(const std::string &message)
{
    if (channelSocket)
        channelSocket->send(message);
}

void serverChannel::receive()
{
    if (channelSocket)
        channelSocket->receive();
}

