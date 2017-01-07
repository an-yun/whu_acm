//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 


/*
* 找连续最多出现的单词,写个查找算法就行吧
*/

const char *name1 = "dongfangxu";
const char *name2 = "zap";


char input[100002];//输入
unsigned test_case_num, i, j;//测试用例数 输入字符指针 匹配字符时的状态
unsigned length1, length2;

unsigned get_max_sequent_repeat(const char *start, unsigned len);//计算连续出现的最长长度

int main()
{
	scanf("%u", &test_case_num);
	for (unsigned test_case_no = 0; test_case_no < test_case_num; test_case_no++)
	{
		scanf("%s", input);
		length1 = get_max_sequent_repeat(name1, 10);
		length2 = get_max_sequent_repeat(name2, 3);
		if (length2 > length1) printf("zap!\n");
		else printf("dongfangxu!\n");
	}
	return 0;
}


inline unsigned get_max_sequent_repeat(const char * start, unsigned len)
{
	unsigned repeat_times = 0, temp_repeat = 0;
	for (i = j = 0; input[i] != '\0'; i++)//初始化指针和状态
	{
		if (start[j%len] == input[i]) j++;//取模，用来重复自串
		else
		{
			if (j != 0)//注意这个0的状态，字符串指针应该前进
			{
				temp_repeat = j / len;//计算连续重复出现的次数
				if (temp_repeat > repeat_times) repeat_times = temp_repeat;//大于更新一下
				j = 0;
				i--;
			}
		}
	}
	//处理最后一个
	temp_repeat = j / len;//计算连续重复出现的次数
	if (temp_repeat > repeat_times) repeat_times = temp_repeat;//大于更新一下
	return repeat_times;
}

#endif

