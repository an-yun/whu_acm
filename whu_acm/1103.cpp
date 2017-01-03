//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 记当前分数为i的状态下获胜的概率为P(i), -2<=i<=2
 *		显然P(2) = 1 ,P(-2) = 0
 *		对于i != 2,-2 : 
 *			当前局面获胜的概率 = 当前局面赢一分后获胜的概率 + 当前局面输一分后获胜的概率
 *			P(i) = p * P(i+1) + (1-p) * P(i-1)  
 *			
 *		解得P(0) = (p*p)/(1-2*p*(1-p))
 */

unsigned test_case_num;
unsigned p;//用整数表示概率，防止丢失精度

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned i =0;i<test_case_num;i++)
	{
		scanf("%u%%", &p);
		if (p == 0)printf("0.00%%\n");
		else if(p == 100)printf("100.00%%\n");
		else printf("%.2lf%%\n", (100.0 * p*p) / (10000.0 - 2 * p*(100 - p)));
	}
	return 0;
}
#endif
