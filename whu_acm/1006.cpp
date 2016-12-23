#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>

/*
 *这里可以采用bitset节省空间
 *#include<bitset>
 */
using std::set;
using std::queue;

//典型的广度优先遍历

set<int> diagraph[200000];	//采用邻接表存储
int visited[200000];//标记与起始点的距离 -1表示还没有访问过
int vector_size, edge_size;//定点数，边数

//求点start 到 end的最短路径
int get_shortest_path(int start, int end);

int main1006()
{
	scanf("%d %d\n", &vector_size, &edge_size);

	int start_vector, end_vector;
	for(int i=0;i<edge_size;i++)
	{
		//输入每条边
		scanf("%d %d", &start_vector, &end_vector);
		if(start_vector == end_vector) continue;
		//注意是无向图，要添加两个边，第一次就是这儿wa
		diagraph[start_vector].insert(end_vector);
		diagraph[end_vector].insert(start_vector);
	}

	int query_number;
	scanf("%d", &query_number);
	for(int i=0;i<query_number;i++)
	{
		//执行每一次查询
		scanf("%d %d", &start_vector, &end_vector);
		printf("%d\n", get_shortest_path(start_vector,end_vector));
	}
	return 0;
}

int get_shortest_path(int start, int end)
{
	if (start == end) return 0;//起点和终点是同一个点
	memset(visited, -1, sizeof(int) * vector_size);//访问标记置零
	queue<int> rest_vectors;//用于存储带访问节点的队列

	//起始节点
	rest_vectors.push(start);
	visited[start] = 0;

	//进行广度优先遍历
	int top_vector;
	while(!rest_vectors.empty())
	{
		top_vector = rest_vectors.front();
		rest_vectors.pop();

		if(top_vector == end)
			break;
		set<int> &top_vector_edges = diagraph[top_vector];
		for(set<int>::iterator edge_b = top_vector_edges.begin(), edge_e = top_vector_edges.end();edge_b != edge_e;edge_b++)
		{
			int the_vector = *edge_b;
			if (the_vector == end)//如果遇到了终点
				return visited[top_vector];
			if(visited[the_vector] < 0)//如果当前点还没有访问过
			{
				visited[the_vector] = visited[top_vector] + 1;//计算距离
				rest_vectors.push(the_vector);//进队列
			}
		}

	}
	//start 和 end 不相连
	return -1;
}
