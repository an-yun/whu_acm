//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h>
#include <string.h>

char one_line[2004];//每一行内容
long one_line_sign[2004];//记录每一列的出现的白色方格数目
long left_up_sum[2004];//当前列形成矩形的左上角顶点可能的选择数目  
int  min_white; //最少连续白色方格的列号
long long result;//最终结果

long row_size, column_size;//行数 列数


int main()
{
	while(scanf("%ld %ld\n",&row_size,&column_size) == 2)
	{
		result = 0;//结果置零
		memset(one_line_sign, 0, sizeof(long)*(column_size + 1));//每一列的出现的白色方格数目置零
		for (int line_num = 1; line_num <= row_size; ++line_num)
		{
			fgets(one_line, 2004, stdin);//读取每一行
			for(int column_num =0;column_num<column_size;++column_num)
			{
				//记录第column_num+1列连续出现的白色方块数目
				if (one_line[column_num] == 'w')//如果是白色的，在原来连续数目的基础上加1
					one_line_sign[column_num + 1]++;
				else one_line_sign[column_num + 1] = 0;//否则置零
			}

			//开始计算以line_num行 ，column_num列处的方格为右下角的顶点的矩形数目
			for (int column_num = 1; column_num<=column_size; ++column_num)
			{
				if (one_line_sign[column_num] >= one_line_sign[column_num - 1])
					//如果比前一列的连续白方格多，直接加入前一列和当前列左上角顶点可能的选择数目
					left_up_sum[column_num] = left_up_sum[column_num - 1] + one_line_sign[column_num];
				else
				{
					//如果比前一列的连续白方格少，则需要找到当前列及之前小于当前列连续白色方格的那一列
					min_white = column_num;

					for (int temp_min = column_num - 1; temp_min > 0 ; --temp_min)
					{
						//找到当前列及之前小于当前列连续白色方格的那一列
						if (one_line_sign[temp_min] < one_line_sign[min_white])
						{
							min_white = temp_min;
							break;
						}
					}
					if(min_white == column_num)//当前列column_num最小
						left_up_sum[column_num] = column_num *one_line_sign[column_num];
					else//min_white列小于当前列column_num
						left_up_sum[column_num] = (column_num -min_white)*one_line_sign[column_num] + left_up_sum[min_white];

				}
				//将以line_num行 ，column_num列处的方格为右下角的顶点，乘上形成矩形的左上角顶点可能的选择数目，加入到最终结果
				result += left_up_sum[column_num];
			}
		}
		printf("%lld\n", result);
	}

	return 0;
}
#endif