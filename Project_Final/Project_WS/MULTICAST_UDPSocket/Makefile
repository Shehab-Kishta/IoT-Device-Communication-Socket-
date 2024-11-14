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
CLIENT_1_DIR = Client_1
CLIENT_2_DIR = Client_2

# Source files
SERVER_SRC = $(SERVER_DIR)/main.cpp $(SERVER_DIR)/server.cpp $(CHANNEL_DIR)/channel.cpp $(SOCKET_DIR)/udpsocket.cpp
CLIENT_1_SRC = $(CLIENT_1_DIR)/main.cpp Client/client.cpp $(CHANNEL_DIR)/channel.cpp $(SOCKET_DIR)/udpsocket.cpp
CLIENT_2_SRC = $(CLIENT_2_DIR)/main.cpp Client/client.cpp $(CHANNEL_DIR)/channel.cpp $(SOCKET_DIR)/udpsocket.cpp

# Output executables
SERVER_EXE = $(OUT_DIR)/server
CLIENT_1_EXE = $(OUT_DIR)/client_1
CLIENT_2_EXE = $(OUT_DIR)/client_2

# Default target
all: $(SERVER_EXE) $(CLIENT_1_EXE) $(CLIENT_2_EXE)

# Rule to build the server
$(SERVER_EXE): $(SERVER_SRC)
	mkdir -p $(OUT_DIR)
	$(GCC) $(GCCFLAGS) -o $(SERVER_EXE) $(SERVER_SRC)

# Rule to build client 1
$(CLIENT_1_EXE): $(CLIENT_1_SRC)
	mkdir -p $(OUT_DIR)
	$(GCC) $(GCCFLAGS) -o $(CLIENT_1_EXE) $(CLIENT_1_SRC)

# Rule to build client 2
$(CLIENT_2_EXE): $(CLIENT_2_SRC)
	mkdir -p $(OUT_DIR)
	$(GCC) $(GCCFLAGS) -o $(CLIENT_2_EXE) $(CLIENT_2_SRC)

# Clean up generated files
clean:
	rm -f $(SERVER_EXE) $(CLIENT_1_EXE) $(CLIENT_2_EXE)
