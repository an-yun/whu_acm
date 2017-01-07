//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <algorithm>

using std::max;

/*
 * 单源最长路径:
 *		因为每一个位置的最大值只与左边上面的元素相关，所以一行一行的计算就行
 *		当然还可以压缩内存，只存一行的数就可以
 */

unsigned all_golds[1000][1000];// 所有的路线
unsigned row_size, column_size,test_case_num;//行数 列数 测试用例数

void caculate_max_gold();//计算最大的数目

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=1;test_case_no <= test_case_num;test_case_no++)
	{
		scanf("%u %u", &row_size, &column_size);
		for (unsigned i = 0; i < row_size; i++)
			for (unsigned j = 0; j < column_size; j++)
				scanf("%u", all_golds[i] + j);
		caculate_max_gold();
		//输出
		printf("Case #%u: %u\n", test_case_no, all_golds[row_size - 1][column_size - 1]);
	}
	return 0;
}

inline void caculate_max_gold()
{
	//计算第一行
	for (unsigned j = 1; j < column_size; j++)
		all_golds[0][j] += all_golds[0][j - 1];//直接加左边的值
	//计算剩余的行
	for(unsigned i=1;i<row_size;i++)
	{
		//第一个元素特殊处理
		all_golds[i][0] += all_golds[i - 1][0];
		for (unsigned j = 1; j < column_size; j++)
			all_golds[i][j] += max(all_golds[i][j-1],all_golds[i-1][j]);
	}
}

#endif
