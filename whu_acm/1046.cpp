//��������
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 * ������������Ȼ��������Ϳ�����
 */

unsigned test_case_num, nums_size;//���������� ���ݹ�ģ
unsigned nums[3002];//���������

unsigned reverse_num;//������

void caculate_reverse_num();//����������


int main()
{
	scanf("%u", &test_case_num);
	for (unsigned test_no = 1; test_no <= test_case_num; test_no++)
	{
		scanf("%u", &nums_size);
		for (unsigned i = 0; i<nums_size; i++)
			scanf("%d", nums + i);
		caculate_reverse_num();
		//���
		printf("%u\n", reverse_num);
	}
	return 0;
}

void caculate_reverse_num()
{
	reverse_num = 0;
	for(unsigned i=0;i<nums_size-1;i++)
	{
		for(unsigned j=i+1;j<nums_size;j++)
		{
			if (nums[j] < nums[i]) reverse_num++;
		}
	}
}

#endif
