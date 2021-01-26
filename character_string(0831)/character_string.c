#include <string.h>
#include <stdio.h>

typedef struct{
	char str[127];
	int length;
}string_t;

int my_memcmp(const char *str_s,char str_c,int len)
{
	int count = 0;
	while(str_s[count] != str_c)
	{
		count ++;
		if(count >= len)
		{
			return 1;
		}
	}
	return 0;
}

int lengthOfLongestSubstring(char *s)
{
	string_t string = {};
	while(s[string.length] != '\0')
	{
		if(my_memcmp(&string.str[0],s[string.length],string.length) == 0)
		{
			int  len = lengthOfLongestSubstring(&s[1]);
			if(string.length < len)
			{
				return len;
			}
			else
			{
				return string.length;
			}
		}
		string.str[string.length] = s[string.length];
		string.length ++;
		
	}
	return string.length;
}

int main(int argc,char* argv[])
{
	char buf[1024];
	
	scanf("%s",buf);
	printf("lengthOfLongestSubstring = %d\r\n",lengthOfLongestSubstring(&buf[0]));
	return 0;
}