//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 直接按照题意来做就行了
 */

unsigned input_num;//输入的数字


int main()
{
	for(;;)
	{
		scanf("%u", &input_num);
		if (input_num == 0) break;
		printf("%u\n", (input_num + 1) / 2);
		
	}
	return 0;
}
#endif
