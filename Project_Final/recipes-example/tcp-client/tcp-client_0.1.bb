SUMMARY = "TCP client application"
LICENSE = "CLOSED"
SRC_URI = "file://CMakeLists.txt \
           file://src/client.cpp \
           file://src/main.cpp \
           file://include/client.hpp \
           file://Drivers/Channel/channel.cpp \
           file://Drivers/Channel/channel.hpp \
           file://Drivers/Socket/tcpsocket.cpp \
           file://Drivers/Socket/socket.hpp"
           
S = "${WORKDIR}"

# Dependencies
DEPENDS = "cmake boost"

inherit cmake
