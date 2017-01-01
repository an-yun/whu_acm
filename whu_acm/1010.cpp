//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include<stdio.h>

/*
 * 计算的结果就是 max_num * 2^(n-1) % 2006
 */

int max_num;//最大数
int set_size;//数据规模
int temp_num;//临时数据

int main()
{
	for (;;)
	{
		scanf("%d", &set_size);
		if(set_size == 0) break;
		//初始化max_num
		scanf("%d", &temp_num);
		max_num = temp_num;
		//输入后面的num_size-1个数
		for(int i=1;i<set_size;i++)
		{
			scanf("%d", &temp_num);
			if (temp_num > max_num) max_num = temp_num;
		}
		//处理max_num
		max_num = (max_num % 2006 + 2006) % 2006;
		//小心计算2 ^ (n-1)
		if (set_size >1)
		{
			set_size--;
			while (set_size >= 11)//大于2的11次幂 2048
			{
				max_num = (max_num * 42) % 2006;
				set_size -= 11;
			}
			max_num = (max_num *(1 << set_size))%2006;
		}
		printf("%d\n", max_num);
	}
	return 0;
}
#endif