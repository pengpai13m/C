#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows)
{
	int len = strlen(s);
	int x ;
	if(numRows %2 == 0)
	{
		x = (strlen(s) / ((numRows + (numRows - 2))/(numRows - 1))) - 1;
	}
	else
	{
		x = (strlen(s) / ((numRows + (numRows - 2))/(numRows - 1)));
	}
	char buf[x][numRows];
	
	char back[len + 1];
	back[len] = '\0';
	int count = 0;
	memset(buf,' ',sizeof(buf));
//	printf("x = %d y = %d\r\n",x,numRows);
	for(int i = 0;i < x; i ++)
	{
		for(int j = 0; j < numRows;j ++ )
		{
			int number = i % (numRows - 1);
			if(number != 0)
			{
				buf[i][numRows - (number + 1)] = *s ++;
				j =  numRows;
			}
			else if(number == 0)
			{
				buf[i][j] = *s ++;
			}
		}
	}
	
	for(int i = 0;i < numRows; i ++)
	{
		for(int j = 0; j < x;j ++ )
		{
//			printf("%c",buf[j][i]);
			if(buf[j][i] != ' ')
			{
				if(count < len)
				{
					back[count ++] = buf[j][i];
				}
			}
		}
//		printf("\r\n");
	}
//	printf("%s\r\n",back);
	char * r_back;
    r_back = (char *)malloc(count); 
    strcpy(r_back,back);
    return r_back;
	
}

int main(int argc,char* argv[])
{
	char buf[1024];
	scanf("%s",buf);
	char * back;
	back = convert(&buf[0],3);
	printf("%s\r\n",back);
	free(back);
	return 0;
}