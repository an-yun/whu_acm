//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <vector>

using std::vector;
/*
 * 按照题目意思来写？有坑？
 *		果然有坑，重复计算太多，用vector做缓存试试
 *		过了
 */

int W(int a, int b, int c);//题目中的函数
unsigned test_case_num;//测试数目
int a, b, c;//输入的abc

vector<vector<vector<int> > > cache(21,vector<vector<int> >(21,vector<int>(21,-1)));//缓存


int main()
{
	scanf("%u", &test_case_num);
	for (unsigned i = 0; i < test_case_num; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		printf("W(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}
	return 0;
}

int W(int a, int b, int c)
{
	
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20)
	{	
		if (cache[20][20][20] != -1) return cache[20][20][20];//缓存记录
		return cache[20][20][20] = W(20, 20, 20);
	}
	if (a < b && b < c)
	{
		if (cache[a][b][c] != -1) return cache[a][b][c];//缓存记录
		return cache[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);//缓存记录
	}
	if (cache[a][b][c] != -1) return cache[a][b][c];//缓存记录
	return cache[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);//缓存记录
}

#endif
