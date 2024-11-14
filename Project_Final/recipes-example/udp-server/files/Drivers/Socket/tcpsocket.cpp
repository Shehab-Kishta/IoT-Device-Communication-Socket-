#include "socket.hpp"

void TCPSocket::connect()
{
    try
    {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context); // Create socket here

        // Step 1: Create an acceptor to listen for incoming connections
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));

        std::cout << "Server is listening on port 8080..." << std::endl;

        // Step 2: Accept a connection from a client
        acceptor.accept(socket); // Use the socket created above

        std::cout << "Client connected!" << std::endl;

        // Store socket if needed for further communication
        this->socket = std::move(socket); // Save socket instance in class member
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in connect: " << e.what() << std::endl;
    }
}

void TCPSocket::receive()
{
    try
    {
        boost::system::error_code error;
        boost::asio::io_context io_context;

        std::fill(buffer.begin(), buffer.end(), 0); // Clear buffer

        size_t length = socket.read_some(boost::asio::buffer(buffer), error);

        if (!error)
        {
            std::cout << "Recieving message from client: " << std::string(buffer.data(), length) << std::endl;
        }
        else
        {
            std::cerr << "Error reading message: " << error.message() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in receive: " << e.what() << std::endl;
    }
}

void TCPSocket::send(const std::string &message)
{
    std::fill(buffer.begin(), buffer.end(), 0); // Clear buffer

    // Check if the socket is still open before trying to send data
    if (socket.is_open())
    {
        boost::system::error_code error;

        // Try sending the message
        boost::asio::write(socket, boost::asio::buffer(message), error);

        if (error)
        {
            // If the error is caused by the client disconnecting (EOF), handle it
            if (error == boost::asio::error::eof)
            {
                std::cout << "Client disconnected during send." << std::endl;
                shutdown(); // Close the socket
                return;
            }
            else
            {
                std::cerr << "Error sending message: " << error.message() << std::endl;
                shutdown(); // Close the socket
                return;
            }
        }
        else
        {
            std::cout << "Sending acknowledgment: " << message << std::endl;
        }
    }
    // else
    // {
    //     std::cerr << "Socket is not open, cannot send message." << std::endl;
    // }
}

void TCPSocket::shutdown()
{
    socket.close();
    std::cout << "Socket closed." << std::endl;
}
