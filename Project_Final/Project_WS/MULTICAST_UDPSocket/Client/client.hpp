#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../Drivers/Channel/channel.hpp"

#define PORT 8080
#define MULTICAST_GROUP "239.0.0.1"

#endif