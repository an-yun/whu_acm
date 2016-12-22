#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>

/*
 *������Բ���bitset��ʡ�ռ�
 *#include<bitset>
 */
using std::set;
using std::queue;

//���͵Ĺ�����ȱ���

set<int> diagraph[200000];	//�����ڽӱ�洢
int visited[200000];//�������ʼ��ľ��� -1��ʾ��û�з��ʹ�
int vector_size, edge_size;//������������

//���start �� end�����·��
int get_shortest_path(int start, int end);

int main1005()
{
	scanf("%d %d\n", &vector_size, &edge_size);

	int start_vector, end_vector;
	for(int i=0;i<edge_size;i++)
	{
		//����ÿ����
		scanf("%d %d", &start_vector, &end_vector);
		if(start_vector == end_vector) continue;
		//ע��������ͼ��Ҫ��������ߣ���һ�ξ������wa
		diagraph[start_vector].insert(end_vector);
		diagraph[end_vector].insert(start_vector);
	}

	int query_number;
	scanf("%d", &query_number);
	for(int i=0;i<query_number;i++)
	{
		//ִ��ÿһ�β�ѯ
		scanf("%d %d", &start_vector, &end_vector);
		printf("%d\n", get_shortest_path(start_vector,end_vector));
	}
	return 0;
}

int get_shortest_path(int start, int end)
{
	if (start == end) return 0;//�����յ���ͬһ����
	memset(visited, -1, sizeof(int) * vector_size);//���ʱ������
	queue<int> rest_vectors;//���ڴ洢�����ʽڵ�Ķ���

	//��ʼ�ڵ�
	rest_vectors.push(start);
	visited[start] = 0;

	//���й�����ȱ���
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
			if (the_vector == end)//����������յ�
				return visited[top_vector];
			if(visited[the_vector] < 0)//�����ǰ�㻹û�з��ʹ�
			{
				visited[the_vector] = visited[top_vector] + 1;//�������
				rest_vectors.push(the_vector);//������
			}
		}

	}
	//start �� end ������
	return -1;
}
