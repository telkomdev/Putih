#include "ArgParser.h"
#include <iostream>
#include "Type.h"

namespace putih
{
    void Argument::ShowHelp(void)
    {
        std::cerr << "Usage: putih [options]\n"
                << "\t--help (show help)\n"
                << "\t--version (show version)"
                << std::endl;
    }

    void Argument::ShowVersion(void)
    {
        std::cout << "putih version " << VERSION;
        std::cout << std::endl;
    }

    int Argument::ParseArg(int& argc, char* args[])
    {
        if (argc == 1) 
        {
            ShowHelp();
            return 1;
        } else if (argc == 2)
        {
            if (strcmp(args[1], "--help") == 0)
            {
                ShowHelp();
                return 1;
            } else if (strcmp(args[1], "--version") == 0)
            {
                ShowVersion();
                return 1;
            } else {
                ShowHelp();
                return 1;
            }
        } else if (argc == 3)
        {
            this->appName = args[0];
            this->host = args[1];
            this->port = args[2];
            return 0;
        } else
        {
            ShowHelp();
            return 1;
        }
        

        return 0;
    }
}