#include <iostream>
#include <string>
#include "ArgParser.h"
#include "Type.h"
#include "Connection.h"

int main(int argc, char* argv[])
{
    putih::Argument args;
    int res = putih::ParseArg(argc, argv, &args);
    if (res != 0) 
    {
        return -1;
    }

    // std::string input;

    // while (input != "exit")
    // {
    //     std::cin >> input;
    //     std::cout << input << std::endl;
    // }

    const char* p_host = args.host;
    const char* p_port = args.port;

    int conn_res = putih::ConnectRedis(p_host, p_port);
    if (conn_res < 0) 
    {
        return -1;
    }

    return 0;
}