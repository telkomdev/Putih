#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "Type.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

namespace putih
{
    namespace
    {
        template<size_t SM, size_t SR>
        int HandleCommand(int sock_FD, std::array<types::Byte, SM>& msg, std::array<types::Byte, SR>* reply)
        {
            // get message
            std::string msg_str;
            getline(std::cin, msg_str);

            // TODO
            // add CR and LF for line termination
            std::ostringstream ss;
            ss << msg_str << "\r\n";

            memcpy(msg.data(), ss.str().c_str(), msg.size());

            int sent = send(sock_FD, msg.data(), msg.size(), 0);
            if (sent == -1) 
            {
                std::cerr << "error send message" << std::endl;
                return -1;
            }
            
            auto bytes_receive = recv(sock_FD, reply->data(), reply->size(), 0);
            if (bytes_receive == -1) 
            {
                std::cerr << "error receiving message" << std::endl;
                return -1;
            }

            return 0;

        }
    }

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
            std::cerr << "error creating socket : " << gai_strerror(sock_FD) << std::endl;
            return -1;
        }

        // estabilish new TCP connection
        int connect_R = connect(sock_FD, p->ai_addr, p->ai_addrlen);
        if (connect_R == -1) 
        {
            close(sock_FD);
            std::cerr << "error connecting socket" << std::endl;
            return -1;
        }

        // TODO

        // carriage return and line feed
        //std::array<types::Byte, 2> CR_LF = {13, 10};

        std::array<types::Byte, 14> msg;
        std::array<types::Byte, 30> reply;

        int sent = HandleCommand(sock_FD, msg, &reply);
        if (sent == -1) 
        {
            std::cerr << "error sending command" << std::endl;
            return -1;
        }

        std::cout << "receiving : " << reply.data() << std::endl;
        close(sock_FD);
        freeaddrinfo(p);

        return 0;
    }

}