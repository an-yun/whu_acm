#include <stdio.h>
#include <string.h>
#include <algorithm>

/*
 * 非常直接的最长公共子序列
 *   1.-_- 没有注意到数字大小，是10001
 *   2.-_- 超内存了
 */

using std::max;
char str1[10008], str2[10008];//两个待计算字符串
short lcs_table[10008],up_value,temp_save;//因为每一行的计算只与上面一行和前面一个计算的值有关
short str1_length, str2_length;

inline short get_lcs_length()
{
	//填表计算最长公共子序列的长度
	//计算第一行
	short i = 0;
	for (; i < str2_length && str2[i] != str1[0]; i++)
		lcs_table[i] = 0;
	for(;i<str2_length;i++)lcs_table[i] = 1;
	for (short line_no = 1; line_no < str1_length; line_no++)
	{
		up_value = lcs_table[0];
		if (str1[line_no] == str2[0])lcs_table[0] = 1;
		for (int j = 1; j < str2_length; j++)
		{
			temp_save = lcs_table[j];
			if (str1[line_no] == str2[j]) lcs_table[j] = up_value + 1;
			else lcs_table[j] = max(lcs_table[j], lcs_table[j - 1]);
			up_value = temp_save;
		}
		
	}
	return lcs_table[str2_length - 1];
}



int main1210()
{
	while (scanf("%s %s",str1,str2) == 2)
	{
		str1_length = strlen(str1);
		str2_length = strlen(str2);
		printf("%d\n", get_lcs_length());
	}
	return 0;
}