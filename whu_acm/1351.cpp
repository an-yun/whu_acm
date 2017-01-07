//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * 计算两个日期之间的天数
 */
unsigned test_case_num;//测试用例数
unsigned month, day, interval_days;//月，日，间隔的天数

void caculate_interval_days();//计算天数

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned i=0;i<test_case_num;i++)
	{
		scanf("%u %u", &month, &day);
		caculate_interval_days();
		printf("%u\n", interval_days);
	}
	return 0;
}

inline void caculate_interval_days()
{
	interval_days = 0;
	for(unsigned i=month;i<8;i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
			interval_days += 31;
			break;
		case 2:
			interval_days += 29;
			break;
		case 4:
		case 6:
			interval_days += 30;
			break;
		default:
			break;
		}
	}
	interval_days -= day - 8;
}

#endif
