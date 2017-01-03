//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * 选取最小的买就可以了
 */

unsigned total_money, flowers_num;//总额 花的种类
unsigned min_price,temp_price;//最便宜的价格 临时价格

int main()
{
	while (scanf("%u %u",&flowers_num,&total_money) == 2)
	{
		min_price = total_money + 1;
		for(unsigned i=0;i< flowers_num;i++)
		{
			scanf("%u", &temp_price);
			if (temp_price < min_price) min_price = temp_price;
		}
		printf("%u\n", total_money / min_price);
	}
	return 0;
}
#endif
