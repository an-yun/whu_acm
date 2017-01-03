//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 经典的利用异或运算的题目：
 *	偶数个1异或就为0
 *	
 *	注意到可能有符号，就用int
 */

unsigned test_num;//测试规模
int temp_num, result_num;//用于输入的数字 最终结果

int main()
{
	result_num = 0;//结果置零
	scanf("%u", &test_num);
	test_num = test_num * 2 + 1;
	for(unsigned i=0;i<test_num;i++)
	{
		scanf("%d", &temp_num);
		result_num ^= temp_num;
	}
	printf("%d\n", result_num);
	return 0;
}
#endif