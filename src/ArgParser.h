#ifndef ARG_PARSER_H
#define ARG_PARSER_H

namespace putih
{

    struct Argument
    {
        char* appName;
        char* host;
        char* port;
        bool isShowVersion;
        bool isShowHelp;
    };
    

    int ParseArg(int& argc, char* args[], Argument* argument);
}

#endif