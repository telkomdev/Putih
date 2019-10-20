#ifndef ARG_PARSER_H
#define ARG_PARSER_H

namespace putih
{

    #define VERSION "0.0.0";

    struct Argument
    {
        char* appName;
        char* host;
        char* port;
        bool isShowVersion;
        bool isShowHelp;
    };
    

    void ShowHelp(void);
    void ShowVersion(void);
    int ParseArg(int& argc, char* args[], Argument* argument);
}

#endif