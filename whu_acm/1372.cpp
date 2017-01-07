//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <algorithm>

using std::sort;

/*
 * 排序，每间隔m个输出即可
 */
unsigned nums[100002];//输入的数字
unsigned nums_size,step,index;//数据规模 步长 数字位置

int main()
{
	for (;;)
	{
		scanf("%u %u", &nums_size, &step);
		if(nums_size == 0) break;
		//输入
		for (unsigned i = 0; i < nums_size; i++)
			scanf("%u", nums + i);
		sort(nums, nums + nums_size);
		//输出
		nums_size -= step;
		for (index = 0; index < nums_size; index += step)
			printf("%u ", nums[index]);
		//输出最后一个
		printf("%u\n", nums[index]);
	}
	return 0;
}
#endif
