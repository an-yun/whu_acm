//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/*
 * 典型的最小生成树：
 *		用Kruskal算法，结合并查集的数据结构实现
 *		一气呵成，没有调试一下，nice!!!
 */

class UnionFind
{
private:
	unsigned elements_size;//元素数目
	unsigned connect_count;//连通量数
	vector<unsigned> parent;//父亲节点
	vector<unsigned> tress_size;//集合中元素数目
public:
	UnionFind(unsigned size);
	void resize(unsigned new_size);//重新调整大小，减少内存分配，new_size 应该小于size
	unsigned find(unsigned index);//寻找包含这个节点的代表节点
	void connect(unsigned i, unsigned j);//连接i,j
	bool connected(unsigned i, unsigned j) { return find(i) == find(j); }//i, j 是否连通数
	unsigned count() const { return connect_count; }//查询连通量数目
	unsigned size() const { return elements_size; }//查询元素数目
};

struct Edge//边
{
	unsigned from;
	unsigned to;
	unsigned cost;
};
//Edge的比较器
bool edge_comparator(const Edge &edge1, const Edge &edge2)
{
	return edge1.cost < edge2.cost;
}

Edge all_edges[4950];//所有的边
unsigned test_case_num, edge_size,edge_point;//测试用例数 边的数目 边指针
unsigned temp_num, N,min_cost;//临时输入 矩阵大小 最小花费
UnionFind union_find(100);//并查集
void caculate_min_cost();//计算最小花费

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=0; test_case_no<test_case_num; test_case_no++)
	{
		edge_size = 0;
		scanf("%u", &N);
		//输入边
		for(unsigned i=0;i<N;i++)
		{
			for(unsigned j=0;j<N;j++)
			{
				scanf("%u", &temp_num);
				if(j>i)
				{
					Edge &edge = all_edges[edge_size];
					edge.from = i;
					edge.to = j;
					edge.cost = temp_num;
					edge_size++;
				}
			}
		}
		caculate_min_cost();
		printf("%u\n", min_cost);
	}
	return 0;
}


inline void caculate_min_cost()
{
	//使用Kruskal算法求最小生成树
	min_cost = 0;
	//按花费排序
	sort(all_edges, all_edges + edge_size, edge_comparator);
	
	union_find.resize(N);
	edge_point = 0;
	while (union_find.count() > 1)
	{
		//如果已经连通，则跳过
		while (union_find.connected(all_edges[edge_point].from, all_edges[edge_point].to))
			edge_point++;
		//加入到生成树中
		union_find.connect(all_edges[edge_point].from, all_edges[edge_point].to);
		min_cost += all_edges[edge_point].cost;
	}
}


UnionFind::UnionFind(unsigned size)
	:elements_size(size),connect_count(size),parent(size),tress_size(size,1)
{
	for (unsigned i = 0; i < size; i++)parent[i] = i;
}

void UnionFind::resize(unsigned new_size)
{
	elements_size = connect_count = new_size;
	for(unsigned i=0;i<elements_size;i++)
	{
		parent[i] = i;
		tress_size[i] = 1;
	}
}

unsigned UnionFind::find(unsigned index)
{
	if (parent[index] != parent[parent[index]]) parent[index] = find(parent[index]);//路径压缩
	return parent[index];
}

void UnionFind::connect(unsigned i, unsigned j)
{
	unsigned root_i = find(i), root_j = find(j);
	if(root_i == root_j) return;//已连通
	//按秩合并
	unsigned size_i = tress_size[root_i], size_j = tress_size[j];
	if(size_i < size_j)//小树连接到大树上
	{
		parent[root_i] = root_j;
		tress_size[root_j] += tress_size[root_i];
	}
	else
	{
		parent[root_j] = root_i;
		tress_size[root_i] += tress_size[root_j];
	}
	connect_count--;
}
#endif
