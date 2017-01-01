//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * 这个题目是个水题，核心点就一个:
 *		gcd(a,b) = min {d| d = ax+by,d>0且x,y都为整数} 参见算法导论（第三版）第31章：定理31.2
 *  所以gcd(a,b)能整除n则输出Possible，否则Impossible
 *  
 */

inline int gcd(int num1, int num2)
{
	if (num2 == 0) return num1;
	else return gcd(num2, num1%num2);
}

int main()
{
	int a, b, n,gcd_a_b;
	while ((scanf("%d %d %d",&a,&b,&n) == 3))
	{
		if(a == 0 && b == 0)//注意边缘case
		{
			if( n == 0)printf("Possible!\n");
			else printf("Impossible!\n");
		}
		else
		{
			gcd_a_b = gcd(a, b);
			if (n%gcd_a_b)//不能整除
				printf("Impossible!\n");
			else
				printf("Possible!\n");
		}

	}
	return 0;
}
#endif