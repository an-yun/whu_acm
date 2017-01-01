//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h>

/*
 * 经典的表达式求值
 */
char expression[56];//表达式
char operator_stack[36];//操作符栈
int operand_stack[36];//操作数栈
int operator_stack_top, operand_stack_top;//操作符栈顶  操作数栈顶

int compare_priority(char op1, char op2);//比较优先级
void perform_caculate(char op);//执行计算

int  main()
{
	int test_case_num,expression_index;
	scanf("%d\n", &test_case_num);
	for (int test_case_no = 0; test_case_no < test_case_num; test_case_no++)
	{
		fgets(expression, 56, stdin);
		//使用算符优先文法
		operand_stack_top = 0;
		operator_stack_top = 1;
		operator_stack[0] = '\n';//表示结束符
		expression_index = 0;
		while (expression[expression_index]!= '\0')
		{
			char &top_char = expression[expression_index];
			switch (top_char)
			{
			case ' ':
				expression_index++;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				{
					//解析数字
					operand_stack[operand_stack_top] = top_char - '0';
					expression_index++;
					int &num = operand_stack[operand_stack_top];
					while ('0' <= expression[expression_index] && expression[expression_index] <= '9')
					{
						num = num * 10 + expression[expression_index] - '0';
						expression_index++;
					}
					operand_stack_top++;
					break;
				}

			default:
				//根据优先级比较结果，执行不同的操作
				int compare_result = compare_priority( operator_stack[operator_stack_top - 1], top_char);
				if (compare_result < 0)
				{
					//入栈
					operator_stack[operator_stack_top++] = top_char;
					expression_index++;
				}
				else if (compare_result == 0)
				{
					//出栈
					operator_stack_top--;
					expression_index++;
				}
				else perform_caculate(operator_stack[--operator_stack_top]); //计算
					
			}
		}
		printf("%d\n", operand_stack[0]);
	}
	return 0;
}

inline int compare_priority(char op1, char op2)
{
	switch (op1)
	{
		case '\n':
		{
			if (op2 == '\n') return 0;
			else return -1;
		}
		case '(':
		{
			if (op2 == ')') return 0;
			else return -1;
		}
		case '+':
		case '-':
		{
			if (op2 == '*' || op2 == '/' || op2 == '(') return -1;
			else return 1;
		}
		case '*':
		case '/':
		{
			if (op2 == '(') return -1;
			else return 1;
		}
		default:
			return 0;
	}
}

inline void perform_caculate(char op)
{
	switch (op)
	{
		case '+':
			operand_stack[operand_stack_top - 2] += operand_stack[operand_stack_top - 1];
			break;
		case '-':
			operand_stack[operand_stack_top - 2] -= operand_stack[operand_stack_top-1];
			break;
		case '*':
			operand_stack[operand_stack_top - 2] *= operand_stack[operand_stack_top - 1];
			break;
		case '/':
			operand_stack[operand_stack_top - 2] /= operand_stack[operand_stack_top - 1];
			break;
	}
	operand_stack_top--;
}
#endif