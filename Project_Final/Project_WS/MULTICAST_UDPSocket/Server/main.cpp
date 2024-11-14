#include "server.hpp"

int main()
{
    try
    {
        // Create a TCPSocket instance
        UDPSocket udpSocket;

        // Pass it to the serverChannel instance
        serverChannel server(&udpSocket);

        // Start the server channel (begin listening)
        server.start();

        std::cout << "Multicast server sending to group " << MULTICAST_GROUP << std::endl;

        Time currentTime(00, 00, 00);

        while (true)
        {
            // Increment time by 1 second
            currentTime += 1;

            // Call generateTimeMessage() on the currentTime object
            std::string timeMessage = currentTime.generateTimeMessage(currentTime);

            try
            {
                // Send the current time to the client
                server.send(timeMessage);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error during send: " << e.what() << std::endl;
                break; // Exit the loop if an error occurs (client disconnected)
            }

            // Wait for 1 second before sending the next time
            sleep(2);
        }

        // Properly stop the server and close the connection
        server.stop();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }

    return 0;
}
