
#include <stdio.h>
#include <string.h>
#include "profiles.h"

static char bowling_buf[DEFAULT_INPUT_MAX_LEN] = {};


void clear_bowling_buf(void)
{
    for(int clear_count = 0; clear_count < DEFAULT_INPUT_MAX_LEN; clear_count ++)
    {
        bowling_buf[clear_count] = '\0';
    }
}

int main(int argc,char* argv[])
{
    while(1)
    {
        int points = 0;
        while(1)
        {
            char cmd_buf = ' ';
            FUNCTION_DEF  function_def;
            printf("Please enter your cmd 'b' or 'q'\r\n");
            scanf("%c",&cmd_buf);
            getchar();
            function_def = cmd_chenk((const char )cmd_buf);
            cmd_buf = ' ';
            if(function_def == BOWLING)
            {
                break;
            }
            else if(function_def == QUIT)
            {
                return 0;
            }                
        }
        int input_cont;
        printf("Please enter the data in the format\r\n");
        while(bowling_buf[input_cont - 1] != '\n') 
        {

            bowling_buf[input_cont] = getchar();
            input_cont ++;
        }
        bowling_buf[input_cont - 1] = '\0';
        input_cont = 0;
	
        points = data_extraction((const char *)bowling_buf);
        if(points == ERROR)
        {
            printf("%s  =  -1\r\n",bowling_buf);
            clear_bowling_buf();
        }
        else
        {
            printf("%s  =  %d\r\n",bowling_buf,points);
            clear_bowling_buf();
        }
    }
    return 0;
}
