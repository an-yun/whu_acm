//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 做一个缓存，然后计算
 */
unsigned cache[10000001] = { 0 };//缓存

unsigned get_length(unsigned index);//计算index的链长
unsigned start, end, temp_length, max_length;//起点 终点 最长长度 临时长度

int main()
{
	cache[1] = 1;
	for (;;)
	{
		scanf("%u %u", &start, &end);
		if (start == 0)break;
		max_length = 0;
		for (unsigned i = start; i <= end; i++)
		{
			temp_length = get_length(i);
			if (temp_length > max_length) max_length = temp_length;
		}
		printf("%u\n", max_length);
	}
	return 0;
}


unsigned get_length(unsigned index)
{
	if (index > 10000000)
	{
		if (index % 2)//奇数
			return get_length(3 * index + 1) + 1;
		return get_length(index / 2) + 1;
	}

	if (cache[index] != 0) return cache[index];
	if (index % 2)//奇数
		return cache[index] = get_length(3 * index + 1) + 1;
	return cache[index] = get_length(index / 2) + 1;

}

#endif
