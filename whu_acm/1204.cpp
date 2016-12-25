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

int main1024()
{
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
			scanf("%d", nums_count + i);
		if (n < 3)
		{
			printf("%d\n", nums_count[0]);
			continue;
		}
		sort(nums_count, nums_count + n);
		if (n % 2)
			printf("%d\n", nums_count[n / 2]);
		else//如果是偶数
		{
			if (nums_count[0] == nums_count[(n / 2) - 1])
				printf("%d\n", nums_count[0]);
			else
				printf("%d\n", nums_count[n / 2]);
		}
	}
	return 0;
}