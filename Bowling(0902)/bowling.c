
/******************************************************************************
* @file		 bowling.c
* @brief	 this file Bowling scoring function realization
* @author	 pengpai
* @date		 2020/6/30
* @history
* @note
* detailed description:
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include "profiles.h"

int bureau(char bowling_buf)
{
	switch (bowling_buf)
	{
		case DEFAULT_STRIKE:
			return 10;
		
		case DEFAULT_SPARE:
			return 10;
		
		case DEFAULT_MISS:
			return  0;

		case DEFAULT_NUMBER_9:
			return 9;

		case DEFAULT_NUMBER_8:	
			return 8;
		
		case DEFAULT_NUMBER_7:
			return 7;

		case DEFAULT_NUMBER_6:
			return 6;

		case DEFAULT_NUMBER_5:				
			return 5;

		case DEFAULT_NUMBER_4:	
			return 4;
		
		case DEFAULT_NUMBER_3:
			return 3;

		case DEFAULT_NUMBER_2:
			return 2;
			
		case DEFAULT_NUMBER_1:
			return 1;

		default :
			return -1;
	}
	return 0;
}


/*********************************************************************
 * @fn      score_calculation
 *
 * @brief   Input data checksum processing.
 *
 * @param   bowling_buf : character string data.
 *
 * @return  Analyze the total bowling score.
 */
int score_calculation(char *bowling_buf,int bureau_count)
{
	static int score = 0;
//	bureau_count ++;
	while(1)
	{
		switch (bowling_buf[0])
		{
			case DEFAULT_STRIKE:
			{
				score += 10;
				score += bureau(bowling_buf[1]);
				score += bureau(bowling_buf[2]);
				*bowling_buf ++;
			}
			break;
		
			case DEFAULT_MISS:
			case DEFAULT_NUMBER_9:
			case DEFAULT_NUMBER_8:
			case DEFAULT_NUMBER_7:
			case DEFAULT_NUMBER_6:
			case DEFAULT_NUMBER_5:
			case DEFAULT_NUMBER_4:
			case DEFAULT_NUMBER_3:
			case DEFAULT_NUMBER_2:
			case DEFAULT_NUMBER_1:
			{
				int old_score;
				old_score += bureau(bowling_buf[0]);
				score += bureau(bowling_buf[1]);
				if(bowling_buf[1]  == DEFAULT_SPARE)
				{
					score += bureau(bowling_buf[2]);
				}
				else
				{
					score += old_score;
				}
				*bowling_buf += 2;
			}
			break;

			default :
				return ERROR;
			break;
		}
		if(bureau_count == 10)
		{
			break;
		}
	}
	return score;// + score_calculation(bowling_buf,bureau_count);
}

/*********************************************************************
 * @fn      data_extraction
 *
 * @brief   Input data checksum processing.
 *
 * @param   bowling_buf : character string data.
 *
 * @return  Analyze the total bowling score.
 */
int data_extraction(const char *bowling_buf)
{
    char *extraction = (char *)bowling_buf;
    int extraction_len = 0;
	int i,j;
    
	for(i=j=0;extraction[i]!='\0';i++)/*Delete the blank space*/
    {
		if(extraction[i]!=' ')
        {
			extraction[j++]=extraction[i];
		}
	}
	
	extraction[j]='\0';
    extraction_len = strlen(extraction);
    
    if(extraction_len > (DEFAULT_INPUT_MAX_LEN - 8) || extraction_len < DEFAULT_INPUT_MIN_LEN)
    {
        return ERROR;
    }
	
    for(int extraction_count = 0;extraction_count < extraction_len;extraction_count ++)
    {
        if(!INPUT_CHENK(extraction[extraction_count]))
        {
            return ERROR;
        }
    }
	return score_calculation(extraction,1);
}


