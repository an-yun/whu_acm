//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 感觉这题的难点在大整数次幂吧
 * 这里我采用分治法计算，代码要简洁些
 *		当然也可以改成迭代的，那么就变成了算法导论中的反复平方法
 *		见算法导论数论算法，第31章第6节：modular-exponentiation
 */

unsigned a, b, c;//题意中a,b,c
unsigned recursive_a_power_b_mod_c(unsigned a, unsigned b, unsigned c);//递归计算a^b mod c

int main()
{
	for (;;)
	{
		scanf("%u %u %u", &a, &b, &c);
		if(c == 0)break;
		printf("%u\n", recursive_a_power_b_mod_c(a,b,c));
	}
	return 0;
}

unsigned recursive_a_power_b_mod_c(unsigned a, unsigned b, unsigned c)
{
	if (a == 0) return 0;
	if (b == 0) return 1;
	if (b == 1) return a %c;
	unsigned long long half_power = recursive_a_power_b_mod_c(a, b / 2, c);//计算一半次幂
	half_power = (half_power*half_power) % c;//平方
	if (b % 2)//如果是奇数次幂
		half_power = (half_power * a) % c;
	return static_cast<unsigned>(half_power);
}
#endif
