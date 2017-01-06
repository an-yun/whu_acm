//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <algorithm>
/*
 * 计算相邻序列，然后排序就完了
 */

using std::sort;

unsigned test_case_num,nums_size;//测试用例数 数据规模
int nums[1002];//输入的数字

void caculate_sequece_and_sort();//计算相邻序列并排序

int main()
{
	scanf("%u", &test_case_num);
	for (unsigned test_no = 1; test_no <= test_case_num; test_no++)
	{
		scanf("%u", &nums_size);
		for(unsigned i=0;i<nums_size;i++)
			scanf("%d", nums+i);
		caculate_sequece_and_sort();
		//输出
		printf("Case %u:\n", test_no);
		for (unsigned i = 0; i < nums_size - 1; i++)
			printf("%d ", nums[i]);
		printf("%d\n\n", nums[nums_size - 1]);
	}
	return 0;
}

void caculate_sequece_and_sort()
{
	for (unsigned i = nums_size - 1; i > 0; i--)
		nums[i] -= nums[i - 1];
	sort(nums, nums + nums_size);
}

#endif
