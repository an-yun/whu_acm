//��������
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * ÿ�δ�14���У�����ȡʤ��ȡ����14����n�Ľ���Ƿ�Ϊ�㣺
 */

unsigned test_case_num;//������������
unsigned n;//���������


int main()
{
	scanf("%u", &test_case_num);
	for (unsigned i = 0; i < test_case_num; i++)
	{
		scanf("%u", &n);
		if (n % 14)//��������
			printf("flymouse wins the game!\n");
		else  printf("snoopy wins the game!\n");
	}
	return 0;
}
#endif
