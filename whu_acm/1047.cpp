//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include<stdio.h>
#include<string.h>

/*
 * 最长公共子串
 */
char lcs_str1[2004];//字符串1
char lcs_str2[2004];//字符串2
unsigned short lcs_table[20004],lsc_left_up_value,lcs_swap_temp;//用于计算的表 左上角的值 临时交换用的值
unsigned short lcs_str1_length, lcs_str2_length,max_common_length;//字符串1长度 字符串2长度 最长公共子串的长度

void get_longest_common_substr();

int main()
{
	unsigned short test_case_num;
	scanf("%u\n", &test_case_num);
	for (unsigned short i = 0; i < test_case_num; i++)
	{
		scanf("%s", lcs_str1);
		scanf("%s", lcs_str2);
		lcs_str1_length = strlen(lcs_str1);
		lcs_str2_length = strlen(lcs_str2);
		get_longest_common_substr();
		printf("%u\n", max_common_length);
	}
	return 0;
}

void get_longest_common_substr()
{
	max_common_length = 0;
	//计算第一行
	for (unsigned short i = 0; i < lcs_str2_length; i++)
	{
		if (lcs_str1[0] == lcs_str2[i]) max_common_length = lcs_table[i] = 1;
		else lcs_table[i] = 0;
	}
	for(unsigned short line_no =1;line_no < lcs_str1_length;line_no++)
	{
		//第一个元素特别处理
		lsc_left_up_value = lcs_table[0];
		lcs_table[0] = (lcs_str1[line_no] == lcs_str2[0]);
		if (lcs_table[0] > max_common_length) max_common_length = lcs_table[0];

		for(unsigned short i =1;i<lcs_str2_length;i++)
		{
			lcs_swap_temp = lcs_table[i];
			if (lcs_str1[line_no] == lcs_str2[i])
			{
				lcs_table[i] = ++ lsc_left_up_value ;
				//更新最大值
				if (lsc_left_up_value > max_common_length) max_common_length = lsc_left_up_value;
			}
			else lcs_table[i] = 0;
			lsc_left_up_value = lcs_swap_temp;
		}
	}
	
}
#endif