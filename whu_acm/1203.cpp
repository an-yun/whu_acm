//��������
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
* ע�⵽ֻ��һ�����Ĵ����������������ֵĴ�����
*	��¼�������������һ�μ�1��û�г��־ͼ�1�������0���������
*
*/

unsigned test_num;//���Թ�ģ
int temp_num, result_num, repeat_times;//������������� ���ս��

int main()
{
	while (scanf("%u", &test_num) == 1)
	{
		repeat_times = 0;
		for (unsigned i = 0; i < test_num; i++)
		{
			scanf("%d", &temp_num);
			if (repeat_times == 0)//���������
			{
				repeat_times = 1;
				result_num = temp_num;
			}
			else
			{
				if (result_num == temp_num) repeat_times++;
				else repeat_times--;
			}
		}
		printf("%d\n", result_num);
	}
	return 0;
}
#endif