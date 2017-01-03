//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
* 注意到只有一个数的次数大于其他数出现的次数：
*	记录下这个数，出现一次加1，没有出现就减1，如果到0更新这个数
*
*/

unsigned test_num;//测试规模
int temp_num, result_num, repeat_times;//用于输入的数字 最终结果

int main()
{
	while (scanf("%u", &test_num) == 1)
	{
		repeat_times = 0;
		for (unsigned i = 0; i < test_num; i++)
		{
			scanf("%d", &temp_num);
			if (repeat_times == 0)//更新这个数
			{
				repeat_times = 1;
				result_num = temp_num;
			}
			else
			{
				if (result_num == temp_num) repeat_times++;
				else repeat_times--;
			}
		}
		printf("%d\n", result_num);
	}
	return 0;
}
#endif