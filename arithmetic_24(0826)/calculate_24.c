/*
8月26日题目：24 点游戏
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
​
示例 1:
输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:
输入: [1, 2, 1, 2]
输出: False
​
注意:
除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
*/
#include <stdio.h>
#include <math.h>

const int TARGET = 24;
const double EPSILON = 1e-6;
const int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;
char calculate_buf[4];
int calculate_count = 0;

int calculate_24(double *value_buf,int len)
{
	if(len == 0)
	{
		return 0;
	}
	if(len == 1)
	{
		if(fabs(value_buf[0] - TARGET) < EPSILON)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	for (int i = 0; i < len; i ++)
	{
		for(int j = i + 1; j < len; j ++)
		{
			double calculate_24_value[20];
			int calculate_24_len = 0;
			for (int k = 0; k < len; k++) /*把未计算的数据存起来*/
			{
				if (k != i && k != j) 
				{
					calculate_24_value[calculate_24_len++] = value_buf[k];
				}
            }
			for(int k = 0; k < 4 ; k ++)/*轮流加减乘除*/
			{
				if(k == ADD)
				{
					calculate_24_value[calculate_24_len++] = value_buf[i] + value_buf[j];
				}
				if(k == SUBTRACT)
				{
					calculate_24_value[calculate_24_len++] = value_buf[i] - value_buf[j];
				}
				if(k == MULTIPLY)
				{
					calculate_24_value[calculate_24_len++] = value_buf[i] * value_buf[j];
				}
				if(k == DIVIDE)
				{
					if(fabs(value_buf[j]) != 0)
					{
						calculate_24_value[calculate_24_len++] = value_buf[i] / value_buf[j];
					}
					else
					{
						calculate_24_value[calculate_24_len++] = value_buf[j] / value_buf[i];
					}
				}
				if(calculate_24(calculate_24_value,calculate_24_len) == 1 )
				{
/*					if(k == ADD)
					{
						calculate_buf[calculate_count ++] = '+';
					}
					if(k == SUBTRACT)
					{
						calculate_buf[calculate_count ++] = '-';
					}
					if(k == MULTIPLY)
					{
						calculate_buf[calculate_count ++] = '*';
					}
					if(k == DIVIDE)
					{
						if(fabs(value_buf[j]) != 0)
						{
							calculate_buf[calculate_count ++] = '/';
						}
						else
						{
							calculate_buf[calculate_count ++] = '0';
						}
					}
*/
					return 1;
				}
				calculate_24_len --;
			}
		}
	}
	return 0;	
}

int main(int argc,char *argv[])
{
	int nubmer;
	printf("input number:");
	scanf("%d",&nubmer);
	printf("runing\r\n");
	if(nubmer > 9999 || nubmer < 1000)
	{
		printf("ERROR\r\n");
		return 0;
	}
	double temp[4];
	temp[0] = nubmer / 1000;
	temp[1] = (nubmer % 1000)/100;
	temp[2] = (nubmer % 100)/10;
	temp[3] = nubmer % 10;
	
	if(calculate_24(temp,4))
	{
//		printf("(%d%c%d)%c(%d%c%d) = 24",(int)temp[0],calculate_buf[2],(int)temp[1],calculate_buf[0],(int)temp[2],calculate_buf[1],(int)temp[3]);
		printf("\r\nSOUCEE\r\n");
	}
	else
	{
		printf("\r\nERROR\r\n");
	}
	
	return 0;
}

