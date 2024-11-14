#include "client.hpp"

int main()
{
    clientChannel c;

    c.start();
    c.send("Hello, Server!");

    // Continuously receive messages from the server

    c.receive(); // Wait for and process messages from the server

    c.stop();

    return 0;
}
