#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <array>
#include <sstream>
#include "../../Drivers/Channel/channel.hpp"
#include "../../Drivers/Socket/socket.hpp"
#include <unistd.h> // For sleep function

class Time
{
private:
    int hour, minute, second;

public:
    Time(int a, int b, int c) : hour(a), minute(b), second(c) {}
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    Time &operator+=(int secondsToAdd);
    std::string generateTimeMessage(const Time& currentTime);
};

#endif