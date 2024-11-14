cmake_minimum_required(VERSION 3.10)

project(tcp-client VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    include
    Drivers/Channel
    Drivers/Socket
)

# Add the executable target
add_executable(tcp-client 
    src/client.cpp 
    src/main.cpp 
    Drivers/Channel/channel.cpp
    Drivers/Socket/tcpsocket.cpp
)

# Install rules
install(TARGETS tcp-client DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)

