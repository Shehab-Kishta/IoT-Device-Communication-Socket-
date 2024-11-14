#include "../Client/client.hpp"

int main()
{
    clientChannel c2;
    c2.start();
    c2.receive();
    c2.stop();

    return 0;
}
