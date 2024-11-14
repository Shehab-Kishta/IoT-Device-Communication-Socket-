#include "../Client/client.hpp"

int main()
{
    clientChannel c1;
    c1.start();
    c1.receive();
    c1.stop();
    
    return 0;
}
