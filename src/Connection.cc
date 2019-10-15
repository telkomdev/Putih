#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

namespace putih_conn
{
    int ConnectRedis(const char* host, const char* port)
    {
        addrinfo hints, *p;
        memset(&hints, 0, sizeof(hints));

        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        int address_info = getaddrinfo(host, port, &hints, &p);
        if (address_info != 0) 
        {
            std::cerr << "error : " << gai_strerror(address_info) << std::endl;
            return -1;
        }

        if (p == NULL) 
        {
            std::cerr << "no address found" << std::endl;
            return -1;
        }

        // create new socket
        int sock_FD = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock_FD == -1) 
        {
            std::cerr << "error creating socket" << std::endl;
            return -1;
        }

        std::cout << "socket " << sock_FD << std::endl;

        // estabilish new TCP connection
        int connect_R = connect(sock_FD, p->ai_addr, p->ai_addrlen);
        if (connect_R == -1) 
        {
            close(sock_FD);
            std::cerr << "error connecting socket" << std::endl;
            return -1;
        }

        const char* MSG = "AUTH devpass\n";

        int sent = send(sock_FD, MSG, strlen(MSG), 0);
        if (sent == -1) 
        {
            std::cerr << "error send message" << std::endl;
            return -1;
        }

        std::string reply(15, ' ');
        
        auto bytes_receive = recv(sock_FD, &reply.front(), reply.size(), 0);
        if (bytes_receive == -1) 
        {
            std::cerr << "error receiving message" << std::endl;
            return -1;
        }

        std::cout << "receiving : " << reply << std::endl;
        close(sock_FD);
        freeaddrinfo(p);

        return 0;
    }
}