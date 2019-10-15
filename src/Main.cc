#include <iostream>
#include <string>
#include "ArgParser.h"
#include "Type.h"
#include "Connection.h"

int main(int argc, char* argv[])
{
    types::ListString args;
    int res = putih::ParseArg(argc, argv, &args);
    if (res < 0) 
    {
        std::cerr << "required 2 arguments" << std::endl;
        return -1;
    }

    // std::string input;

    // while (input != "exit")
    // {
    //     std::cin >> input;
    //     std::cout << input << std::endl;
    // }

    std::string host = args.at(1);
    std::string port = args.at(2);

    const char* p_host = host.c_str();
    const char* p_port = port.c_str();

    int conn_res = putih::ConnectRedis(p_host, p_port);
    if (conn_res < 0) 
    {
        return -1;
    }

    return 0;
}