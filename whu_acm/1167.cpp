//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
* 做一个bfs进行统计就好
*/

unsigned row_num, column_num, total_point;//行数 列数 最终结果 
char graph[100][102];//用于存储的图
unsigned bfs_queue[102], queue_front, queue_back;//bfs 队列

void cacultae_total_point();//计算有多少个石油点
void bfs(unsigned i, unsigned j);//bfs遍历

int main()
{
	for (;;)
	{
		scanf("%u %u", &row_num, &column_num);
		if (row_num == 0) break;
		for (unsigned i = 0; i < row_num; i++)
			scanf("%s", graph[i]);
		cacultae_total_point();
		printf("%u\n", total_point);
	}
	return 0;
}

inline void cacultae_total_point()
{
	total_point = 0;
	for (unsigned i = 0; i < row_num; i++)
	{
		for (unsigned j = 0; j < column_num; j++)
		{
			if (graph[i][j] == 'O')
			{
				total_point++;
				bfs(i, j);
			}
		}
	}
}

inline void bfs(unsigned i, unsigned j)
{
	queue_front = 0;
	queue_back = 1;
	graph[i][j] = 'X';//标记为已经访问过
	bfs_queue[0] = i*column_num + j;
	while (queue_front != queue_back)
	{
		unsigned queue_head = bfs_queue[queue_front++];
		i = queue_head / column_num, j = queue_head % column_num;
		//上
		if (i > 0 && graph[i - 1][j] == 'O')
		{
			graph[i - 1][j] = 'X';
			bfs_queue[queue_back++] = (i - 1)*column_num + j;
		}
		//右上
		if (i > 0 && j < column_num - 1 && graph[i - 1][j + 1] == 'O')
		{
			graph[i - 1][j + 1] = 'X';
			bfs_queue[queue_back++] = (i - 1)*column_num + j + 1;
		}
		//右
		if (j < column_num - 1 && graph[i][j + 1] == 'O')
		{
			graph[i][j + 1] = 'X';
			bfs_queue[queue_back++] = i*column_num + j + 1;
		}
		//右下
		if (i < row_num - 1 && j < column_num - 1 && graph[i + 1][j + 1] == 'O')
		{
			graph[i + 1][j + 1] = 'X';
			bfs_queue[queue_back++] = (i + 1)*column_num + j + 1;
		}
		//下
		if (i < row_num - 1 && graph[i + 1][j] == 'O')
		{
			graph[i + 1][j] = 'X';
			bfs_queue[queue_back++] = (i + 1)*column_num + j;
		}
		//左下
		if (i < row_num - 1 && j > 0 && graph[i + 1][j - 1] == 'O')
		{
			graph[i + 1][j - 1] = 'X';
			bfs_queue[queue_back++] = (i + 1)*column_num + j - 1;
		}
		//左
		if (j > 0 && graph[i][j - 1] == 'O')
		{
			graph[i][j - 1] = 'X';
			bfs_queue[queue_back++] = i *column_num + j - 1;
		}
		//左上
		if (i > 0 && j > 0 && graph[i - 1][j - 1] == 'O')
		{
			graph[i - 1][j - 1] = 'X';
			bfs_queue[queue_back++] = (i - 1)*column_num + j - 1;
		}
	}
}


#endif

