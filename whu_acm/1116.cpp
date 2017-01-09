//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 *按照分治(动规)的思想,题目的分析是这样的：
 *		记题目给的范围是[1,m],要选的数是n个，可选的数列种类数是f(m,n)。
 *			这n个数组成的数列可以分成两类：
 *				1.一类是最后一个数是m的
 *				2.一类是最后一个数不是m的
 *			第一种情况：
 *				倒数第二个数应该小于等于m/2，种类数应该为f(m/2,n-1)
 *			第二种情况：
 *				 最后一个数不是m，那么最后一个数应该是小于等于m-1，种类数应该为f(m-1,n)
 *			综合两种情况是：
 *				f(m,n) = f(m/2,n-1) + f(m-1,n)
 *			
 *			结合边缘情况，最终递推公式是：
 *				f(m,n) =	0	当m < 2^n-1 (不够选n个数)
 *							m	当n = 1 (1到m随便选)
 *							f(m/2,n-1) + f(m-1,n) 其它
 *							
 *			实际写代码的时候还要做一下缓存,整数要用unsigned long long，否则长度不够
 *							
 */

unsigned long long f_cache[2001][9]={0};//函数f的缓存 
/*
 *因为 n=1的时候不用算，所以n所在的维数是9，注意计算n的时候减2
*/
unsigned test_case_num;//测试用例数
unsigned m, n;//题意中m,n
unsigned long long get_f(unsigned m, unsigned n);//计算f(m,n)

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=1;test_case_no <= test_case_num;test_case_no++)
	{
		scanf("%u %u", &n, &m);
		printf("Data set %u: %u %u %llu\n", test_case_no, n, m, get_f(m, n));
	}
	return 0;
}


unsigned long long get_f(unsigned m, unsigned n)
{
	/*
	 *按照公式：
	 *				f(m,n) =	0	当m < 2^n-1 (不够选n个数)
	 *							m	当n = 1 (1到m随便选)
	 *							f(m/2,n-1) + f(m-1,n) 其它
	 *计算
	 */
	if (m < (1llu << (n - 1))) return 0;
	if (n == 1) return m;
	if (f_cache[m][n - 2] != 0) return f_cache[m][n - 2];
	return f_cache[m][n - 2] = get_f(m/2,n-1) + get_f(m-1,n);
}

#endif
