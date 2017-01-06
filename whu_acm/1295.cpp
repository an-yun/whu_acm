//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 用以一个栈处理就可以了：
 *	一个括号里面不能有其他括号
 */

char input[102];//输入
char stack[102];//栈

unsigned test_case_num, stack_top,char_index;//测试用例数 栈顶 输入指针

bool is_legal();//判断是否合法

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=1;test_case_no <= test_case_num;test_case_no++)
	{
		scanf("%s", input);
		if (is_legal())
			printf("Case %u: Legal\n", test_case_no);
		else printf("Case %u: Illegal\n", test_case_no);
	}
	return 0;
}


bool is_legal()
{
	char_index = stack_top = 0;
	for (;input[char_index] != '\0';char_index++)
	{
		switch (input[char_index])//前面三种情况入栈，后面三种出栈
		{
		case '(':
			stack[stack_top++] = '(';
			break;
		case '[':
			stack[stack_top++] = '[';
			break;
		case '{':
			stack[stack_top++] = '{';
			break;
		case ')':
			if (stack_top == 0 || stack[stack_top - 1] != '(')
				return false;
			stack_top--;
			break;
		case ']':
			if (stack_top == 0 || stack[stack_top - 1] != '[')
				return false;
			stack_top--;
			break;
		case '}':
			if (stack_top == 0 || stack[stack_top - 1] != '{')
				return false;
			stack_top--;
			break;
		default:
			break;
		}
	}
	return stack_top == 0;
}

#endif
