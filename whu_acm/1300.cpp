//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 简单算了下以7为周期，0-1 Dzs赢，2-6Sproblvem赢
 *		数学原理还没弄明白
 */
unsigned test_case_num;//测试用例数
unsigned stones;//石头数

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned i=0;i<test_case_num;i++)
	{
		scanf("%u", &stones);
		if (stones % 7 < 2)//0-1 Dzs赢
			printf("Dzs\n");
		else printf("Sproblvem\n");//2-6Sproblvem赢
	}
	return 0;
}
#endif
