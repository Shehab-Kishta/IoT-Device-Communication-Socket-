cmake_minimum_required(VERSION 3.10)

project(udp-server VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Include directories
include_directories(
    include
    Drivers/Channel/
    Drivers/Socket/
)

# Add the executable
add_executable(udp-server 
    src/server.cpp 
    src/main.cpp 
    Drivers/Socket/udpsocket.cpp 
    Drivers/Channel/channel.cpp
)

# Install rules
install(TARGETS udp-server DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)

