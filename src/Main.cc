#include <iostream>
#include <string>
#include "ArgParser.h"
#include "Type.h"

int main(int argc, char* argv[])
{
    types::ListString args;
    int res = argparser::ParseArg(argc, argv, &args);
    if (res < 0) 
    {
        std::cout << "required 2 arguments" << std::endl;
        return -1;
    }

    for (std::string arg : args)
    {
        std::cout << " " << arg << std::endl;
    }

    std::string input;

    while (input != "exit")
    {
        std::cin >> input;
        std::cout << input << std::endl;
    }

    return 0;
}