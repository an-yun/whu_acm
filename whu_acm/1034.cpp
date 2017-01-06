//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 通项公式是 f(n) = (n^3 + 5n + 6)/6
 * 注意到n最大是100000，数据大小用unsigned long long 
 */
int main()
{
	unsigned num;//输入的数字
	unsigned long long result;//运算的结果
	while (scanf("%u",&num) == 1)
	{
		result = num;//转换为long long
		result = (result * result * result + 5 * result + 6) / 6;
		printf("%llu\n", result);
	}
			
	return 0;
}
#endif
