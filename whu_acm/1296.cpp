//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 偶数无解 ， 奇数 n-1
 */
unsigned num;

int main()
{
	for(;;)
	{
		scanf("%u", &num);
		if(num == 0) break;
		else if (num % 2) printf("%u\n", num - 1);
		else printf("No Solution!\n");
	}
	return 0;
}
#endif
