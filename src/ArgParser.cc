#include "ArgParser.h"
#include <iostream>
#include "Type.h"

namespace putih
{
    int ParseArg(int& argc, char* args[], types::ListString* list)
    {
        if (argc < 3) 
        {
            return -1;
        }

        for (int i = 0; i < argc; i++) 
        {
            list->push_back(args[i]);
        }

        return 0;
    }
}