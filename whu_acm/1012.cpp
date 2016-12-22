#include <stdio.h>
#include <string.h>

char one_line[2004];//ÿһ������
long one_line_sign[2004];//��¼ÿһ�еĳ��ֵİ�ɫ������Ŀ
long left_up_sum[2004];//��ǰ���γɾ��ε����ϽǶ�����ܵ�ѡ����Ŀ  
int  min_white; //����������ɫ������к�
long long result;//���ս��

long row_size, column_size;//���� ����


int main1012()
{
	while(scanf("%ld %ld\n",&row_size,&column_size) == 2)
	{
		result = 0;//�������
		memset(one_line_sign, 0, sizeof(long)*(column_size + 1));//ÿһ�еĳ��ֵİ�ɫ������Ŀ����
		for (int line_num = 1; line_num <= row_size; ++line_num)
		{
			fgets(one_line, 2004, stdin);//��ȡÿһ��
			for(int column_num =0;column_num<column_size;++column_num)
			{
				//��¼��column_num+1���������ֵİ�ɫ������Ŀ
				if (one_line[column_num] == 'w')//����ǰ�ɫ�ģ���ԭ��������Ŀ�Ļ����ϼ�1
					one_line_sign[column_num + 1]++;
				else one_line_sign[column_num + 1] = 0;//��������
			}

			//��ʼ������line_num�� ��column_num�д��ķ���Ϊ���½ǵĶ���ľ�����Ŀ
			for (int column_num = 1; column_num<=column_size; ++column_num)
			{
				if (one_line_sign[column_num] >= one_line_sign[column_num - 1])
					//�����ǰһ�е������׷���ֱ࣬�Ӽ���ǰһ�к͵�ǰ�����ϽǶ�����ܵ�ѡ����Ŀ
					left_up_sum[column_num] = left_up_sum[column_num - 1] + one_line_sign[column_num];
				else
				{
					//�����ǰһ�е������׷����٣�����Ҫ�ҵ���ǰ�м�֮ǰС�ڵ�ǰ��������ɫ�������һ��
					min_white = column_num;

					for (int temp_min = column_num - 1; temp_min > 0 ; --temp_min)
					{
						//�ҵ���ǰ�м�֮ǰС�ڵ�ǰ��������ɫ�������һ��
						if (one_line_sign[temp_min] < one_line_sign[min_white])
						{
							min_white = temp_min;
							break;
						}
					}
					if(min_white == column_num)//��ǰ��column_num��С
						left_up_sum[column_num] = column_num *one_line_sign[column_num];
					else//min_white��С�ڵ�ǰ��column_num
						left_up_sum[column_num] = (column_num -min_white)*one_line_sign[column_num] + left_up_sum[min_white];

				}
				//����line_num�� ��column_num�д��ķ���Ϊ���½ǵĶ��㣬�����γɾ��ε����ϽǶ�����ܵ�ѡ����Ŀ�����뵽���ս��
				result += left_up_sum[column_num];
			}
		}
		printf("%lld\n", result);
	}

	return 0;
}