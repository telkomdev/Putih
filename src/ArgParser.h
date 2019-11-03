#ifndef ARG_PARSER_H
#define ARG_PARSER_H

namespace putih
{

    #define VERSION "0.0.0";

    class Argument
    {
        private:
            char* appName;
            char* host;
            char* port;
            bool isShowVersion;
            bool isShowHelp;
        public:
            int ParseArg(const int& argc, char* args[]);
            char* GetAppName() const {return appName;}
            char* GetHost() const {return host;}
            char* GetPort() const {return port;}
            static void ShowHelp(void);
            static void ShowVersion(void);
    };
    
}

#endif