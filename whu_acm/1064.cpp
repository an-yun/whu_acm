//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <set>
/*
 * set统计一下去重就行了
 */

using std::set;

unsigned nums_size;//数字规模
unsigned temp_num;//临时输入

int main()
{
	while (scanf("%u",&nums_size) == 1)
	{
		set<unsigned> no_repeat_nums;
		for(unsigned i=0;i<nums_size;i++)
		{
			scanf("%u", &temp_num);
			no_repeat_nums.insert(temp_num);
		}
		//输出 注意输出格式
		set<unsigned>::iterator b = no_repeat_nums.begin() , e = no_repeat_nums.end();
		for (e--; b != e; b++)
			printf("%u ", *b);
		printf("%u\n",*e);
	}
	return 0;
}
#endif
