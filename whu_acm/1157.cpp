//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

unsigned left_ones;//左边1的个数
unsigned total_collisions;//总的碰撞次数
int num_size,temp_num;//数据量 临时数字
unsigned test_case_no;//测试序号
int main()
{
	test_case_no = 1;
	for(;;)
	{
		scanf("%d", &num_size);
		if(num_size == -1) break;
		total_collisions = left_ones = 0;//置零
		for(int i=0;i<num_size;i++)
		{
			scanf("%d", &temp_num);
			//记录左边1的个数
			if (temp_num == 1) left_ones++;
			else total_collisions += left_ones;
		}
		printf("Case %u: %u\n", test_case_no++, total_collisions);
	}
	return 0;
}
#endif
