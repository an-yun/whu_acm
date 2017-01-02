//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <map>

using std::map;
unsigned test_case_num,max_count;//测试用例个数 最大的重复次数
unsigned num_size, temp_num;//输入数字的数目 临时存储的数字
map<unsigned,unsigned> nums_count;

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=0; test_case_no<test_case_num; test_case_no++)
	{
		max_count = 0;//最大计数置零
		nums_count.clear();//计数map清空
		scanf("%u", &num_size);
		for(unsigned i=0;i<num_size;i++)
		{
			scanf("%u", &temp_num);
			unsigned &num_count = nums_count[temp_num];
			num_count++;
			//一直记录最大的数
			if (num_count > max_count) max_count = num_count;
		}
		printf("%u\n", max_count);
	}
	return 0;
}


#endif