//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * 每次凑14就行，最后的取胜者取决于14整除n的结果是否为零：
 */

unsigned test_case_num;//测试用例个数
unsigned n;//输入的整数


int main()
{
	scanf("%u", &test_case_num);
	for (unsigned i = 0; i < test_case_num; i++)
	{
		scanf("%u", &n);
		if (n % 14)//不能整除
			printf("flymouse wins the game!\n");
		else  printf("snoopy wins the game!\n");
	}
	return 0;
}
#endif
