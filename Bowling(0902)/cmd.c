
#include "profiles.h"

FUNCTION_DEF cmd_chenk(const char cmd_buf)
{
    char cmd = (char)cmd_buf;
    switch (cmd)
    {
        case 'b':
            return BOWLING;
        
        case 'q':
            return QUIT;

        default:
        
        break;    
    }
    return ERROR;
}


