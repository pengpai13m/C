

int main(void)
{
	int test_buf[20] = {10,11,12,13,14,15,16,17,18,19,20,10,11,12,13,14,15,16,17,18};
	int i;
	static int max_step,min_step;
	int max,min,max_2 = 0,min_2 = 0;
	int intput;
	while(1)
	{
		printf("input number:");
		scanf("%d",&intput);
		max = min = intput;
		max_step = min_step = 0;
		for(i = 19; i>0; i--)    
		{
			test_buf[i] = test_buf[i-1];

			if(test_buf[i] > max)  
			{
				max = test_buf[i];
				max_step = i;
			}
			if(test_buf[i] < min)  
			{
				min = test_buf[i];
				min_step = i;
			}
		}	

		test_buf[0] = intput;
		for(i= 0; i < 20; i++)  
		{
			if((test_buf[i] > max_2 && max_step != i) || (max_2 == 0 && max_step != i))  
			{
				max_2 = test_buf[i];
			}
			if((test_buf[i] < min_2 && min_step != i) || (min_2 == 0 && min_step != i))  
			{
				min_2 = test_buf[i];
			}
		}	
		printf("test_buf:");
		for(i = 0; i < 20; i++)
		{
			printf(" %d ",(int)test_buf[i]);
		}

		printf("\r\nmax = %d,min = %d,max_2 = %d,min_2 = %d\r\n",max,min,max_2,min_2);
	}
	return 0;
}