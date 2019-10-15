#include <iostream>
#include <string>
#include "ArgParser.h"
#include "Type.h"

int main(int argc, char* argv[])
{
    types::ListString list;
    int res = argparser::ParseArg(argc, argv, &list);
    if (res < 0) 
    {
        std::cout << "required 2 arguments" << std::endl;
        return -1;
    }

    for (std::string arg : list)
    {
        std::cout << " " << arg << std::endl;
    }

    return 0;
}