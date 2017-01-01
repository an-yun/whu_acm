//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <string.h>
#include <limits.h>
#include <map>
#include <queue>

using std::map;
using std::queue;

//典型的最大网络流问题

int max_feed;//一个人最大喂养的数量


//因为不超过100，所以数据采用int一位存储
struct  FlowEdge//流网络中的边
{
	int from;//起点
	int to;//起点
	bool is_person_edge;//是否连接人的边，用来获取容量，通用的应该是int capacity;
	int flow;//正向流

	//返回当前边的另一个顶点
	int other_vector(int v) { return v == from ? to : from; }
	//返回到达顶点v可增加的流
	int residual_flow_to(int v) { return v == from ? flow : (is_person_edge ? max_feed : 1) - flow; }
	//增加顶点v出发的流
	void add_residual_flow_to(int v, int add_value) { v == from ? flow -= add_value : flow += add_value; }

};

FlowEdge all_flow_edges[10204];//流网络中的所有边
int flow_edges_size;//边的数目
map<int, int> diagraph[204];//网络图 key是对应边的索引

bool has_visited[204];//用于在广度优先搜索中标记是否访问过
int linked_edge[204];//标记当前节点的出边

bool has_augmenting_path(int source, int destination);//是否还有增广路径 返回增加的流量
int get_max_flow(int source, int destination);//求最大网络流


int main()
{
	int person_numbers, animal_numbers, edge_mark;
	while (scanf("%d %d", &person_numbers, &animal_numbers) == 2)
	{
		flow_edges_size = 0;//边的数目置零
		/*
		 *0 是源点
		 *1 ~ person_numbers 是人所在的顶点
		 *person_numbers+1 ~ person_numbers+animal_numbers 是动物所在的顶点
		 *person_numbers+animal_numbers + 1 是汇点
		 */
		int source = 0;
		int animal_end = person_numbers + animal_numbers;
		int destination = animal_end + 1;

		//清除所有点的出边
		for (int vector_num = 0; vector_num <= destination; vector_num++)
			diagraph[vector_num].clear();

		map<int, int> &source_out_edges = diagraph[0];//源点出边
		for (int person = 1; person <= person_numbers; ++person)
		{
			map<int, int> &person_out_edges = diagraph[person];//人的出边
			//连接源点和人
			FlowEdge &person_edge = all_flow_edges[flow_edges_size];
			person_edge.from = 0;
			person_edge.to = person;
			person_edge.is_person_edge = true;
			person_edge.flow = 0;
			
			source_out_edges[person] = flow_edges_size;
			person_out_edges[0] = flow_edges_size;
			flow_edges_size++;
			//读取每一行
			for (int animal = person_numbers + 1; animal <= animal_end; animal++)
			{
				scanf("%d", &edge_mark);
				if (edge_mark == 1)//如果person 和animal有一条边
				{
					map<int, int> &animal_out_edges = diagraph[animal];//动物的出边
					//连接人和动物
					FlowEdge &animal_edge = all_flow_edges[flow_edges_size];
					animal_edge.from = person;
					animal_edge.to = animal;
					animal_edge.is_person_edge = false;
					animal_edge.flow = 0;
					
					animal_out_edges[person] = flow_edges_size;
					person_out_edges[animal] = flow_edges_size;
					flow_edges_size++;
				}
			}
		}
		//链接动物和汇点
		map<int, int> &destination_out_edges = diagraph[destination];//汇点出边
		for (int animal = person_numbers + 1; animal <= animal_end; animal++)
		{
			map<int, int> &animal_out_edges = diagraph[animal];//动物的出边

			FlowEdge &animal_edge = all_flow_edges[flow_edges_size];
			animal_edge.from = animal;
			animal_edge.to = destination;
			animal_edge.is_person_edge = false;
			animal_edge.flow = 0;
			//连接动物和汇点
			animal_out_edges[destination] = flow_edges_size;
			destination_out_edges[animal] = flow_edges_size;
			flow_edges_size++;
		}
		scanf("%d", &max_feed);
		if(get_max_flow(source, destination) == animal_numbers)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

bool has_augmenting_path(int source, int destination)
{
	if (source == destination) return false;
	memset(has_visited, 0, (destination - source + 1) * sizeof(bool));
	queue<int> rest_vectors;//用于存储带访问节点的队列
	//起始节点
	rest_vectors.push(source);
	has_visited[source] = true;

	while (!rest_vectors.empty() && !has_visited[destination])
	{
		int top_vector = rest_vectors.front();
		rest_vectors.pop();

		map<int, int> &top_vector_edges = diagraph[top_vector];
		for (map<int, int>::iterator edge_b = top_vector_edges.begin(), edge_e = top_vector_edges.end(); edge_b != edge_e; edge_b++)
		{
			int reach_vector = (*edge_b).first;
			if (!has_visited[reach_vector])//如果当前点还没有访问过
			{
				int flow_edge_index = (*edge_b).second;
				FlowEdge &flow_edge = all_flow_edges[flow_edge_index];
				if (flow_edge.residual_flow_to(reach_vector) > 0)//如果还有残存容量
				{
					linked_edge[reach_vector] = flow_edge_index;//注意反向标记
					has_visited[reach_vector] = true;
					if (reach_vector == destination)
						return true;
					rest_vectors.push(reach_vector);
				}
			}
		}

	}
	//source 和 destination 不相连
	return false;
}

int get_max_flow(int source, int destination)
{
	int max_flow = 0;

	int current_flow, curent_vector;
	while (has_augmenting_path(source, destination))//如果还有增广路径
	{
		//计算增广路经的流量
		current_flow = INT_MAX;
		curent_vector = destination;
		while (curent_vector != source)
		{
			FlowEdge &flow_edge = all_flow_edges[linked_edge[curent_vector]];
			current_flow = std::min(current_flow, flow_edge.residual_flow_to(curent_vector));
			curent_vector = flow_edge.other_vector(curent_vector);
		}
		//增加流量
		curent_vector = destination;
		while (curent_vector != source)
		{
			FlowEdge &flow_edge = all_flow_edges[linked_edge[curent_vector]];
			flow_edge.add_residual_flow_to(curent_vector, current_flow);
			curent_vector = flow_edge.other_vector(curent_vector);
		}
		max_flow += current_flow;
	}

	return max_flow;
}
#endif