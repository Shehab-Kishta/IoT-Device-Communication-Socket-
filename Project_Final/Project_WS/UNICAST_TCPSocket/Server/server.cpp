#include "server.hpp"

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

Time &Time::operator+=(int secondsToAdd)
{
    this->second += secondsToAdd;
    this->minute += this->second / 60;
    this->hour += this->minute / 60;

    this->second %= 60;
    this->minute %= 60;
    this->hour %= 24;

    return *this;
}

std::string Time::generateTimeMessage(const Time& currentTime) {
    return std::to_string(currentTime.getHour()) + "h:" + std::to_string(currentTime.getMinute()) + "m:" + std::to_string(currentTime.getSecond()) + "s";
}
