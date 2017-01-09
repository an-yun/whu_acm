//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * 成比例计算就行
 *		好吧要注意精度
 */

unsigned test_case_num;//测试用例数
unsigned distanceA, distanceB, height;//题意中的两个距离和蜡烛高度
double image_height;//像高
int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no =0;test_case_no <test_case_num;test_case_no++)
	{
		scanf("%u %u %u", &distanceA, &distanceB, &height);
		image_height = 1.0*distanceB / distanceA * height ;
		printf("%.2lf\n", image_height);
	}
	return 0;
}
#endif
