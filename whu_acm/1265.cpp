//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <set>
/*
 * 看了下，时间给的充足，空间也够，那就可以直接算
 *		用一个set维护是否重复
 */

using std::set;

unsigned sequence[500001];//待计算的序列
int index;//下标位置
void caculate_sequence();//计算序列

int main()
{
	caculate_sequence();
	for(;;)
	{
		scanf("%d", &index);
		if (index == -1)break;
		printf("%u\n", sequence[index]);
	}
	return 0;
}

inline void caculate_sequence()
{
	sequence[0] = 0;
	sequence[1] = 1;
	sequence[2] = 3;
	sequence[3] = 6;
	set<unsigned> has_repeat;//记录是否重复过
	has_repeat.insert(0);
	has_repeat.insert(1);
	has_repeat.insert(3);
	has_repeat.insert(6);
	for(unsigned i=4;i<500001;i++)
	{
		if(sequence[i-1] <= i || has_repeat.find(sequence[i - 1] - i)!= has_repeat.end())
			sequence[i] = sequence[i - 1] + i;
		else sequence[i] = sequence[i - 1] - i;
		has_repeat.insert(sequence[i]);
	}
}

#endif
