# Compiler
GCC = g++

# Compiler flags
GCCFLAGS = -Wall -std=c++11

# Directories
OUT_DIR = out
DRIVERS_DIR = ../Drivers
CHANNEL_DIR = $(DRIVERS_DIR)/Channel
SOCKET_DIR = $(DRIVERS_DIR)/Socket
SERVER_DIR = Server
CLIENT_DIR = Client

# Source files
SERVER_SRC = $(SERVER_DIR)/main.cpp $(SERVER_DIR)/server.cpp $(CHANNEL_DIR)/channel.cpp $(SOCKET_DIR)/tcpsocket.cpp
CLIENT_SRC = $(CLIENT_DIR)/main.cpp $(CLIENT_DIR)/client.cpp $(CHANNEL_DIR)/channel.cpp $(SOCKET_DIR)/tcpsocket.cpp

# Output executables
SERVER_EXE = $(OUT_DIR)/server
CLIENT_EXE = $(OUT_DIR)/client

# Default target
all: $(SERVER_EXE) $(CLIENT_EXE) $(CLIENT_2_EXE)

# Rule to build the server
$(SERVER_EXE): $(SERVER_SRC)
	mkdir -p $(OUT_DIR)
	$(GCC) $(GCCFLAGS) -o $(SERVER_EXE) $(SERVER_SRC)

# Rule to build client 1
$(CLIENT_EXE): $(CLIENT_SRC)
	mkdir -p $(OUT_DIR)
	$(GCC) $(GCCFLAGS) -o $(CLIENT_EXE) $(CLIENT_SRC)

# Rule to build client 2
$(CLIENT_2_EXE): $(CLIENT_2_SRC)
	mkdir -p $(OUT_DIR)
	$(GCC) $(GCCFLAGS) -o $(CLIENT_2_EXE) $(CLIENT_2_SRC)

# Clean up generated files
clean:
	rm -f $(SERVER_EXE) $(CLIENT_EXE) $(CLIENT_2_EXE)
