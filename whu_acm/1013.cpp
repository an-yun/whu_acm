//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <algorithm>
/*
 *后缀数组排序即可
 */

using std::sort;

char input[102];//输入
unsigned char suffix_array[102],input_length;//后缀数组 输入字符串的长度

void caculate_suffix_array();//计算后缀数组
bool str_compare(unsigned char i, unsigned char j);//字符串比较器

int main()
{
	while (scanf("%s",input) == 1)
	{
		caculate_suffix_array();
		//输出最小的字符串
		unsigned char least_str = suffix_array[0];
		for (unsigned char index = 0; index < input_length; index++)
			printf("%c", input[(least_str + index) % input_length]);
		printf("\n");
	}
	return 0;
}

inline void caculate_suffix_array()
{
	input_length = 0;
	while (input[input_length] != '\0')//初始化后缀数组
	{
		suffix_array[input_length] = input_length;
		input_length++;
	}
	sort(suffix_array, suffix_array + input_length, str_compare);//排序
}

bool str_compare(unsigned char i, unsigned char j)
{
	for(unsigned char index=0;index < input_length;index++)
	{
		char ch_1 = input[(i + index) % input_length];
		char ch_2 = input[(j + index) % input_length];
		if (ch_1 != ch_2) return ch_1 < ch_2;
	}
	return false;
}

#endif
