/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。
对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
*/
#include <stdio.h>

int findTargetSumWays(int* nums, int numsSize, int S)
{
	printf("numsSize = %d \r\n",numsSize);
	static int count = 0;
	static int countR = 0;
	if(numsSize == 1)
	{
		if((S - nums[0] == 0) || (S + nums[0] == 0))
		{
			printf("S = %d nums[0] = %d\r\n",S,nums[0]);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	printf("nums is:");
	for(int i = 0;i < numsSize; i ++)
	{  
		printf("%d",nums[i]);
	}
	printf("\r\n");

	for(int j = 0 ;j < 2; j ++)
	{
		if(j == 0)
		{
			S -= nums[0];
			count += findTargetSumWays(&nums[1],numsSize-1,S);
		}
		else if(j == 1)
		{
			S += nums[0];
			count += findTargetSumWays(&nums[1],numsSize-1,S);
		}
		countR ++;
	}
	if(numsSize == 5)
	{
		return count;
	}
	return 0;
}

int main(int argc,char *argv[])
{
	int goals[20]={1,1,1,1,1};
	
	printf("goals_and = %d\r\n",findTargetSumWays(goals,5,3));
	return 0;
}