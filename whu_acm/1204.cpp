//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <algorithm>

/*
 * 第一个坑 读完题目，简单一想，直接用map计数，最简单最快，水题，5分速来
 *		实际的情况是 内存限定的比较死 估计5分的难度就在这儿
 * 第二个坑 题目的输入没有说是多组数据，我就按一组数据写代码，结果wa了
 * 
 * 最后用了排序,再来找,应该有更快的算法
 * 总的来说，除了那个多组数据没有说清楚之外，这个题目还是不错的
 */


using std::sort;
int nums_count[500000];

unsigned n,i;

int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (n < 3)
		{
			for (i = 0; i < n; i++)
				scanf("%d", nums_count + i);
			printf("%d\n", nums_count[0]);
			continue;
		}
		if (n % 2)//如果是奇数
		{
			nums_count[0] = 0;//做计数器
			for (unsigned i = 0; i < n; i++)
			{
				scanf("%d", nums_count+1);
				if (nums_count[0] == 0)//更新这个数
				{
					nums_count[0] = 1;
					nums_count[2] = nums_count[1];
				}
				else
				{
					if (nums_count[2] == nums_count[1]) nums_count[0]++;
					else nums_count[0]--;
				}
			}
			printf("%d\n", nums_count[2]);
			continue;
		}
		else//如果是偶数
		{
			for (i = 0; i < n; i++)
				scanf("%d", nums_count + i);
			sort(nums_count, nums_count + n);
			if (nums_count[0] == nums_count[(n / 2) - 1])
				printf("%d\n", nums_count[0]);
			else
				printf("%d\n", nums_count[n / 2]);
			continue;
		}
	}
	return 0;
}
#endif