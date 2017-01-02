//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

//最少每日的收入 一个机器的收入 销售数目
unsigned least_dollar, per_machine_dollar, sell_amount;

int main()
{
	for(;;)
	{
		scanf("%u %u %u", &least_dollar, &per_machine_dollar, &sell_amount);
		if(least_dollar == 0) break;
		per_machine_dollar *= sell_amount;
		//与底薪比较
		if (per_machine_dollar < least_dollar)
			printf("%u\n", least_dollar);
		else printf("%u\n", per_machine_dollar);
	}
	return 0;
}
#endif
