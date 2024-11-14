SUMMARY = "UDP server application"
LICENSE = "CLOSED"
SRC_URI = "file://CMakeLists.txt \
           file://src/server.cpp \
           file://src/main.cpp \
           file://include/server.hpp \
           file://Drivers/Socket/socket.hpp \
           file://Drivers/Socket/udpsocket.cpp \
           file://Drivers/Channel/channel.hpp \
           file://Drivers/Channel/channel.cpp"

S = "${WORKDIR}"

# Dependencies
DEPENDS = "cmake boost"

inherit cmake

