#include "ArgParser.h"
#include <iostream>
#include "Type.h"

namespace putih
{
    int ParseArg(int& argc, char* args[], Argument* argument)
    {
        if (argc < 3) 
        {
            return -1;
        }

        argument->appName = args[0];
        argument->host = args[1];
        argument->port = args[2];

        return 0;
    }
}