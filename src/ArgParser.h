#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include "Type.h"

namespace argparser
{
    int ParseArg(int argc, char* args[], types::ListString* list);
}

#endif