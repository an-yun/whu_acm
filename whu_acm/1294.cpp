//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 *  以半年为单位，递推公式是
 *		f(n) = f(n-1) + 2f(n-2)
 *	公式的意义依次是：
 *		 第n半年的小鼠 = 第n-1半年的小鼠 + 年龄大于等于1年的成年鼠生下的小鼠
 *	解得公式为
 *		f(n) + f(n-1) = 2 ^ n
 *		f(n) = (-1)^n * (  (-2)^0 + (-2)^1 + (-2)^2 + ... + (-2)^n  )
 *	这里可以不用第二个公式计算，可以用第一个计算，先计算出来然后打表即可(注意到n/2 <= 15，数据范围unsigned足够）
 *	
 */


unsigned f[31];//公式结果
unsigned test_case_num,year;//测试用例数 年份

void caculate_f();//通过递推公式计算

int main()
{
	caculate_f();
	scanf("%u", &test_case_num);
	for (unsigned i=0;i<test_case_num;i++)
	{
		scanf("%u", &year);
		printf("%u\n", f[2*year]);
	}
	return 0;
}

void caculate_f()
{
	f[0] = f[1] = 1;
	//按照 f(n) + f(n-1) = 2 ^ n 计算
	for (unsigned i = 2; i < 31; i++)
		f[i] = (1 << i) - f[i - 1];
}
#endif
