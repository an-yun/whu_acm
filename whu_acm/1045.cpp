//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 按照题意更改大小写就行了
 */
char input[10002];//输入
unsigned test_case_num, index;//测试用例规模 字符指针
bool is_first;//是否是第一个字符


int main()
{
	scanf("%u\n", &test_case_num);
	for (unsigned i = 0; i < test_case_num; i++)
	{
		fgets(input, 10002, stdin);
		//纠正句首字符
		if ('a' <= input[0] && input[0] <= 'z')input[0] = 'A' + input[0] - 'a';
		//纠正单词字符
		is_first = false;
		index = 1;
		while (input[index] != '\0')
		{
			if ('A' <= input[index] && input[index] <= 'Z')
			{
				//如果不是第一个字母，而且大写了，就纠正为小写
				if (!is_first)
					input[index] = 'a' + input[index] - 'A';
				is_first = false;
			}
			else if('a' <= input[index] && input[index] <= 'z') is_first = false;
			else is_first = true;//不是字母，把第一个的标记置为true
			index++;
		}
		printf("%s", input);
	}
	return 0;
}
#endif
