#include <stdio.h> 
#include <string.h>
/*
*可用单源最短路径来解
*	kingkong 不连通
*	mathdog  权重1
*	road 权重0
*
*	具体算法是:Dijkstra算法
*
*	Magicpig到Amaze最短距离，如果小于2，输出Yes,否则No
* 核心点：
*	1.构造一个有向图，用邻接表
*		(细节点：V = n*n ,连接边的时候判断四个方向是否是kingkong或边缘，是的话不连通，否则连通加上相应的权重)
*	2.构造一个MinIndexPQ，带索引的优先队列
*		(用于找最当前还未加入的距离最小的点，快速更新这个点相连的点)
*
*	zuo 2016-12-26
*	
*	2016-12-28：果然自己写数据结构容易错啊，还是没注意细节，弄得wa好久
*		因为MinIndexPQ的sink_pq方法写的不对所以wa了很久
*/

//用于调试
//#define MY_DEBUG_1041


class MinIndexPQ//带索引的优先队列
{
public:
	static const int max_size = 900;//最大存储的元素数目
	static const unsigned U_C_MAX = static_cast<unsigned>(-1);
	void resize(unsigned new_size);
	void decreaseKey(unsigned index, unsigned value);//减小编号为index的元素的优先级
	unsigned get_priority(unsigned index);//减小编号为index的点的优先级
	unsigned min_index();//优先级最小的元素编号
	unsigned min_priority();//最小的优先级
	unsigned del_min();//删除优先级最小的元素,并返回其优先级
	bool empty();//是否为空
private:
	//0号元素不使用
	unsigned priorities[max_size + 1];//优先级
	unsigned pq[max_size + 1];//优先队列
	unsigned pq_index[max_size + 1];//优先队列元素编号
	unsigned size;

	void swap_pq(unsigned index1, unsigned index2);
	void swim_pq(unsigned index);
	void sink_pq(unsigned index);
};


MinIndexPQ min_index_pq;

unsigned test_case_size, forest_size;//测试用例数t 森林规模n
unsigned m_start, a_end;//起始点Magicpig 终止点Amaze

char forest[36][36];
char forest_diagraph[901][4];//存储图结构的邻接表，-1:不链接 0:权重0  1:权重1  (4分别表示四个方向：左右上下)
bool shortest_path_less_2();//最短路径是否小于2
void connect_four_directions(unsigned i, unsigned j);//连接左右上下四个方向的点


#ifdef MY_DEBUG_1041
void test_min_index_pq();
#endif

int main1041()
{
#ifdef MY_DEBUG_1041
	test_min_index_pq();
#else
	scanf("%u", &test_case_size);
	for (unsigned test_case_no = 0; test_case_no < test_case_size; test_case_no++)
	{
		scanf("%u", &forest_size);

		for (unsigned line_no = 0; line_no < forest_size; line_no++)
			scanf("%s", forest[line_no]);
		//注意边缘case
		if (forest_size == 1)
		{
			if (forest[0][0] == 'a')printf("Yes\n");
			else printf("No\n");
		}
		else if (shortest_path_less_2())
			printf("Yes\n");
		else
			printf("No\n");
	}
#endif
	return 0;
}



inline bool shortest_path_less_2()
{
	m_start = a_end = 0;
	//构造有向图
	for (unsigned i = 0; i < forest_size; i++)
	{
		for (unsigned j = 0; j < forest_size; j++)
		{
			if (forest[i][j] == 'k')//kingkong
				continue;
			if (forest[i][j] == 'a')//终止点Amaze
			{
				a_end = i*forest_size + j + 1;
				continue;
			}
			if (forest[i][j] == 'p')//起始点Magicpig
				m_start = i*forest_size + j + 1;
			connect_four_directions(i, j);
		}
	}
	if (m_start == 0 || a_end == 0)return false;
	//初始化
	min_index_pq.resize(forest_size * forest_size);
	min_index_pq.decreaseKey(m_start, 0);

	while (!min_index_pq.empty())
	{
		if (min_index_pq.min_priority() > 1)//当前最短路径都大于1，所以不能到达
			return false;
		unsigned vector_index = min_index_pq.min_index();
		if (vector_index == a_end)//最近点是终点，可以做出判断了
			return min_index_pq.min_priority() < 2;
		//访问四个相邻的店
		unsigned current_shortest_path = min_index_pq.del_min();
		unsigned i = (vector_index - 1) / forest_size, j = (vector_index - 1) % forest_size;
		//上
		if (forest_diagraph[vector_index][0] != -1)
			min_index_pq.decreaseKey((i - 1)*forest_size + j + 1, current_shortest_path + forest_diagraph[vector_index][0]);
		//左
		if (forest_diagraph[vector_index][1] != -1)
			min_index_pq.decreaseKey(i*forest_size + j, current_shortest_path + forest_diagraph[vector_index][1]);
		//下
		if (forest_diagraph[vector_index][2] != -1)
			min_index_pq.decreaseKey((i + 1)*forest_size + j + 1, current_shortest_path + forest_diagraph[vector_index][2]);
		//右
		if (forest_diagraph[vector_index][3] != -1)
			min_index_pq.decreaseKey(i*forest_size + j + 2, current_shortest_path + forest_diagraph[vector_index][3]);

	}
	return false;
}

inline void connect_four_directions(unsigned i, unsigned j)
{
	unsigned vector_index = i*forest_size + j + 1;
	char weight = forest[i][j] == 'd' ? 1 : 0;
	//上
	if (i != 0 && forest[i - 1][j] != 'k')
		forest_diagraph[vector_index][0] = weight;
	else forest_diagraph[vector_index][0] = -1;
	//左
	if (j != 0 && forest[i][j - 1] != 'k')
		forest_diagraph[vector_index][1] = weight;
	else forest_diagraph[vector_index][1] = -1;
	//下
	if (i != forest_size - 1 && forest[i + 1][j] != 'k')
		forest_diagraph[vector_index][2] = weight;
	else forest_diagraph[vector_index][2] = -1;
	//右
	if (j != forest_size - 1 && forest[i][j + 1] != 'k')
		forest_diagraph[vector_index][3] = weight;
	else forest_diagraph[vector_index][3] = -1;
}




inline void MinIndexPQ::resize(unsigned new_size)
{
	size = new_size;
	memset(priorities + 1, U_C_MAX, size * sizeof(unsigned));
	for (unsigned i = 1; i <= size; i++)
		pq[i] = pq_index[i] = i;
}


inline void MinIndexPQ::decreaseKey(unsigned index, unsigned value)
{
	if (pq_index[index] > size || priorities[index] <= value) return;
	priorities[index] = value;//减小优先级
	swim_pq(pq_index[index]);//上行
}


inline void MinIndexPQ::swap_pq(unsigned index1, unsigned index2)
{
	//swap element
	unsigned temp = pq[index1];
	pq[index1] = pq[index2];
	pq[index2] = temp;
	//set place
	pq_index[pq[index1]] = index1;
	pq_index[pq[index2]] = index2;
}


inline void MinIndexPQ::swim_pq(unsigned index)//将pq中位于index位置上行
{
	for (; index > 1 && (priorities[pq[index]] < priorities[pq[index / 2]]); index /= 2)
		swap_pq(index, index / 2);
}

inline void MinIndexPQ::sink_pq(unsigned index)//将pq中位于index位置下行
{
	while (index * 2 <= size)
	{
		unsigned &current_priority = priorities[pq[index]];
		unsigned &left_priority = priorities[pq[index * 2]];
		unsigned swap_index = left_priority < current_priority ? index * 2 : index;
		if (index * 2 + 1 <= size)//有右孩子
		{
			unsigned &right_priority = priorities[pq[index * 2 + 1]];
			swap_index = right_priority < priorities[pq[swap_index]] ? index * 2 + 1 : swap_index;
		}
		if (swap_index == index) return;//已经比孩子的优先级小了
		swap_pq(index, swap_index);
		index = swap_index;
	}
}

inline unsigned MinIndexPQ::get_priority(unsigned index)
{
	return priorities[index];
}

inline unsigned MinIndexPQ::min_index()
{
	return pq[1];
}

inline unsigned MinIndexPQ::min_priority()
{
	return priorities[pq[1]];
}

inline unsigned MinIndexPQ::del_min()
{
	swap_pq(1, size);
	size--;
	sink_pq(1);
	return priorities[pq[size + 1]];
}

inline bool MinIndexPQ::empty()
{
	return size == 0;
}

#ifdef MY_DEBUG_1041
void test_min_index_pq()
{
	printf("将索引优先队列的大小调整为10\n");
	min_index_pq.resize(10);
	printf("将将编号为4的元素优先级调整为5\n");
	min_index_pq.decreaseKey(4, 5);
	printf("将将编号为2的元素优先级调整为6\n");
	min_index_pq.decreaseKey(2, 6);
	printf("将将编号为1的元素优先级调整为2\n");
	min_index_pq.decreaseKey(1, 2);
	printf("将将编号为6的元素优先级调整为5\n");
	min_index_pq.decreaseKey(6, 5);
	printf("将将编号为7的元素优先级调整为1\n");
	min_index_pq.decreaseKey(7, 1);
	printf("将将编号为2的元素优先级调整为1\n");
	min_index_pq.decreaseKey(2, 1);
	printf("将将编号为8的元素优先级调整为4\n");
	min_index_pq.decreaseKey(8, 4);
	printf("将将编号为3的元素优先级调整为4\n");
	min_index_pq.decreaseKey(3, 4);
	printf("删除优先级最小的元素，最小元素优先级：%u\n", min_index_pq.del_min());
	printf("删除优先级最小的元素，最小元素优先级：%u\n", min_index_pq.del_min());
	printf("最小元素优先级：%u\n", min_index_pq.min_priority());
	printf("优先级最小的元素编号：%u\n", min_index_pq.min_index());
	printf("将将编号为5的元素优先级调整为1\n");
	min_index_pq.decreaseKey(5, 1);
	printf("最小元素优先级：%u\n", min_index_pq.min_priority());
	printf("删除优先级最小的元素，最小元素优先级：%u\n", min_index_pq.del_min());
	printf("删除优先级最小的元素，最小元素优先级：%u\n", min_index_pq.del_min());
	printf("删除优先级最小的元素，最小元素优先级：%u\n", min_index_pq.del_min());
	printf("索引优先队列的大小：%u\n", min_index_pq.elements_size());
}
#endif
