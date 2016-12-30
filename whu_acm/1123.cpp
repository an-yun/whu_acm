#include<stdio.h>

/*
 * 整个通项公式为2n-2，1的时候为1
 */

int main1123()
{
	// 因为(2^32-1)*2-2 > UNSIGNEN_MAX，所以用 unsigned long long
	unsigned long long checkerboard_size= 0;
	while (scanf("%llu",&checkerboard_size) == 1)
	{
		if(checkerboard_size == 1llu)
			//如果为1单独判断
			printf("1\n");
		else
			printf("%llu\n", checkerboard_size*2 - 2);
	}
}