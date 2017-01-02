//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * 标准的进制转换
 *	数据范围不是很大，用unsigned就够了
 */

char convert_result[12],temp_char;//转换后的结果 用于临时交换的char
unsigned row_num, column_num;//行数和列数
unsigned start_index;//转换位置记录

void convert_column_num();//转换列数数字

int main()
{
	for (;;)
	{
		while (getchar() != 'R');
		scanf("%uC%u", &row_num, &column_num);
		if(row_num == 0) break;
		convert_column_num();
		printf("%s%d\n", convert_result, row_num);
	}
	return 0;
}

inline void convert_column_num()
{
	start_index = 0;
	while (column_num > 0)
	{
		column_num--;
		convert_result[start_index++] = (column_num % 26) + 'A';
		column_num /= 26;
	}
	//反转一下
	for(unsigned i=0;i<start_index/2;i++)
	{
		temp_char = convert_result[i];
		convert_result[i] = convert_result[start_index - i - 1];
		convert_result[start_index - i - 1] = temp_char;
	}
	convert_result[start_index] = '\0';
}

#endif
