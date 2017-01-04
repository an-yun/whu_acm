//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 此题的规模不大，直接计算填表就完了
 */

int table[10][10];//要填的表
int M, N;//起始的数字 三角形的宽度

void fill_table();//填表
void print_table();//打印表

int main()
{
	for(;;)
	{
		scanf("%d %d", &M, &N);
		if(N == 0) break;
		fill_table();
		print_table();
	}
	return 0;
}


void fill_table()
{
	unsigned column_no = 0;
	for (unsigned i = 1; i <= N; i++)//按对角线长度填表
	{
		column_no = 0;
		for (unsigned row_no = N - i; row_no < N; row_no++)
		{
			//一行一行的输入
			table[row_no][column_no++] = M++;
		}
	}
}

void print_table()
{
	for (unsigned i = 0; i<N; i++)
	{
		//一行一行的输出
		for (unsigned j = 0; j <= i; j++)
			printf("%2d ", table[i][j]);
		printf("\n");
	}
	printf("\n");
}


#endif
