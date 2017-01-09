//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <string.h>
/*
 * 八个方向搜索字符串
 */

char matrix[51][53];//输入字符串

char query_str[53];//搜索位置的字符串

unsigned test_case_num,query_num;//测试用例数 查询用例数
unsigned row_size, column_size;//行 列

unsigned x, y,search_point;//搜索到的位置 搜索指针
unsigned query_str_len;//搜索字符串长度
void search_str();//向八个方向搜索字符串
void to_lower_case(char *start, unsigned len);//转换为小写
int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=0;test_case_no < test_case_num;test_case_no++)
	{
		scanf("%u %u", &row_size, &column_size);
		//输入矩阵
		for (unsigned row_no = 1; row_no <= row_size; row_no++)
		{
			scanf("%s", matrix[row_no] + 1);
			to_lower_case(matrix[row_no] + 1, column_size);//转换为小写
		}
			
		scanf("%u", &query_num);
		for(unsigned query_no=0;query_no < query_num; query_no++)
		{
			scanf("%s", query_str + 1);
			query_str_len = strlen(query_str + 1);
			to_lower_case(query_str + 1, query_str_len);//转换为小写
			search_str();//搜索
			printf("%u %u\n", x, y);//输出搜索结果
		}
	}
	return 0;
}


inline void search_str()
{
	for(unsigned row_no=1;row_no <= row_size;row_no++)
	{
		for(unsigned column_no=1;column_no<= column_size;column_no++)
		{
			if(matrix[row_no][column_no] == query_str[1])
			{
				//上
				if(query_str_len<= row_no)
				{
					//从第二个位置开始搜索起
					for(search_point = 1; search_point < query_str_len; search_point++)
					{
						if(query_str[search_point+1] != matrix[row_no- search_point][column_no]) break;
					}
					if(search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//右上
				if (query_str_len <= row_no && query_str_len+column_no <= column_size+1)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no - search_point][column_no + search_point]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//右
				if (query_str_len + column_no <= column_size + 1)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no][column_no + search_point]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//右下
				if (query_str_len + row_no <= row_size + 1 && query_str_len + column_no <= column_size + 1)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no+search_point][column_no + search_point]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//下
				if (query_str_len + row_no <= row_size + 1)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no + search_point][column_no]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//左下
				if (column_no >= query_str_len && query_str_len + row_no <= row_size + 1)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no + search_point][column_no-search_point]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//左
				if (column_no >= query_str_len)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no][column_no - search_point]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
				//左上
				if (column_no >= query_str_len && query_str_len <= row_no)
				{
					//从第二个位置开始搜索起
					for (search_point = 1; search_point < query_str_len; search_point++)
					{
						if (query_str[search_point + 1] != matrix[row_no -search_point][column_no - search_point]) break;
					}
					if (search_point == query_str_len)//找到了
					{
						x = row_no;
						y = column_no;
						continue;
					}
				}
			}
		}
	}
}

inline void to_lower_case(char * start, unsigned len)
{
	for(unsigned i=0;i<len;i++)
	{
		if (start[i] >= 'A' && start[i] <= 'Z')start[i] = 'a' + start[i] - 'A';
	}
}


#endif
