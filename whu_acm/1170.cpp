#include <stdio.h>
#include <set>
/*
 * 总感觉有坑，但是用set统计一下，然后就过了
 *		好吧，水题一个
 */
using std::set;

int main1170()
{
	set<unsigned> all_nums;
	unsigned temp_num;
	while (scanf("%u", &temp_num) && temp_num)
		all_nums.insert(temp_num);
	//输出结果
	for (set<unsigned>::iterator b = all_nums.begin(), e = all_nums.end(); b != e; b++)
		printf("%u ", (*b));
	return 0;
}