#include "client.hpp"

using boost::asio::ip::tcp;

void clientChannel::start()
{
    if (!socket.is_open()) // Check if already connected
    {
        try
        {
            // Resolve server address
            boost::asio::ip::tcp::resolver resolver(io_context);
            tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "8080");
            boost::asio::connect(socket, endpoints);
            std::cout << "Connected to server!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Connection error: " << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "Already connected" << std::endl;
    }
}

void clientChannel::send(const std::string &message)
{
    try
    {
        if (socket.is_open())
        {
            boost::asio::write(socket, boost::asio::buffer(message));
            std::cout << "Sending message to server: " << message << std::endl;
        }
        else
        {
            std::cerr << "Socket is not open!" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in send: " << e.what() << std::endl;
    }
}

void clientChannel::receive()
{
    while (true)
    {
        try
        {
            boost::system::error_code error;
            std::fill(buffer.begin(), buffer.end(), 0); // Clear buffer

            size_t length = socket.read_some(boost::asio::buffer(buffer), error);

            if (!error)
            {
                std::cout << "Message from server: " << std::string(buffer.data(), length) << std::endl;
            }
            else
            {
                // Handle connection lost or error during reception
                if (error == boost::asio::error::eof)
                {
                    std::cout << "Server disconnected." << std::endl;
                    break;
                }
                else
                {
                    std::cerr << "Error receiving message: " << error.message() << std::endl;
                    break;
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error in receive: " << e.what() << std::endl;
            break;
        }
    }
}

void clientChannel::stop()
{
    if (socket.is_open())
    {
        boost::system::error_code error;

        // Attempt to shutdown the socket
        socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, error);
        if (error && error != boost::asio::error::not_connected)
        {
            std::cerr << "Error during shutdown: " << error.message() << std::endl;
        }

        // Attempt to close the socket
        socket.close(error);
        if (error)
        {
            std::cerr << "Error closing socket: " << error.message() << std::endl;
        }
    }
}
