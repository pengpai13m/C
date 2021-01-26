

#ifndef __PROFILES_H_
#define __PROFILES_H_

#define DEFAULT_INPUT_MAX_LEN        30
#define DEFAULT_INPUT_MIN_LEN        12

#define DEFAULT_MAX_SCORE            10

#define DEFAULT_VALID_DATA_LINE      10
#define DEFAULT_VALID_DATA_ROW       3

#define DEFAULT_CARDINAL_NUBER      0x30



#define DEFAULT_STRIKE               'X'
#define DEFAULT_SPARE                '/'
#define DEFAULT_MISS                 '-'
#define DEFAULT_NUMBER_9             '9'
#define DEFAULT_NUMBER_8             '8'
#define DEFAULT_NUMBER_7             '7' 
#define DEFAULT_NUMBER_6             '6'
#define DEFAULT_NUMBER_5             '5' 
#define DEFAULT_NUMBER_4             '4'
#define DEFAULT_NUMBER_3             '3' 
#define DEFAULT_NUMBER_2             '2'
#define DEFAULT_NUMBER_1             '1' 

#define INPUT_CHENK(x)  (((x <= DEFAULT_NUMBER_9) &&    \
                        (x >= DEFAULT_NUMBER_1)) ||     \
                        (x == DEFAULT_STRIKE)   ||      \
                        (x == DEFAULT_SPARE)    ||      \
                        (x == DEFAULT_MISS))

typedef enum
{
  ERROR = 0xFF,
  SUCCEED,
  BOWLING,
  QUIT,
}FUNCTION_DEF;


FUNCTION_DEF cmd_chenk(const char cmd_buf);

int data_extraction(const char *bowling_buf);


#endif


