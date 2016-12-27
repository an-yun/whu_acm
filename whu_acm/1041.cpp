#include <stdio.h> 
#include <string.h>
#include <vector>
/*
*可用单源最短路径来解
*	kingkong 不连通
*	matdog  权重1
*	road 权重0
*
*	Magicpig到Amaze最短距离，如果小于2，输出Yes,否则No
* 核心点：
*	1.构造一个有向图，用邻接表
*		(细节点：V = n*n ,连接边的时候判断四个方向是否是kingkong或边缘，是的话不连通，否则连通加上相应的权重)
*	2.构造一个MinIndexPQ，带索引的优先队列
*		(用于找最当前还未加入的距离最小的点，快速更新这个点相连的点)
*
*	zuo 2016-12-26
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
	unsigned elements_size();
private:
	//0号元素不使用
	unsigned priorities[max_size + 1];//优先级
	unsigned pq[max_size + 1];//优先队列
	unsigned pq_index[max_size + 1];//元素序号
	unsigned size;

	void swap_pq(unsigned index1, unsigned index2);
	void swim_pq(unsigned index);
	void sink_pq(unsigned index);
};

using std::vector;

MinIndexPQ min_index_pq;

unsigned test_case_size, forest_size;//测试用例数t 森林规模n
unsigned start, end;//起始点Magicpig 终止点Amaze

char forest[32][32];
unsigned forest_diagraph[901][4];//存储图结构的邻接表，0表示不链接
unsigned get_shortest_path();


#ifdef MY_DEBUG_1041
void test_min_index_pq();
#endif

int main()
{
#ifdef MY_DEBUG_1041
	test_min_index_pq();
#else
	scanf("%d\n", &test_case_size);
	for(unsigned test_case_no=0; test_case_no<test_case_size; test_case_no++)
	{
		scanf("%d\n", &forest_size);
		for (unsigned line_no = 0; line_no < forest_size; line_no++)
			fgets(forest[line_no], 32, stdin);
		if (get_shortest_path() < 2)
			printf("Yes\n");
		else
			printf("No\n");
	}
#endif
	return 0;
}



unsigned get_shortest_path()
{
	//构造有向图
	return 0;
}




void MinIndexPQ::resize(unsigned new_size)
{
	size = new_size;
	memset(priorities + 1, U_C_MAX, size * sizeof(unsigned));
	for (unsigned i = 1; i <= size; i++)
		pq[i] = pq_index[i] = i;
}


void MinIndexPQ::decreaseKey(unsigned index, unsigned value)
{
	priorities[index] = value;//减小优先级
	swim_pq(pq_index[index]);//上行
}


void MinIndexPQ::swap_pq(unsigned index1, unsigned index2)
{
	//swap element
	unsigned temp = pq[index1];
	pq[index1] = pq[index2];
	pq[index2] = temp;
	//set place
	pq_index[pq[index1]] = index1;
	pq_index[pq[index2]] = index2;
}


void MinIndexPQ::swim_pq(unsigned index)//将pq中位于index位置上行
{
	for (; index > 1 && (priorities[pq[index]] < priorities[pq[index / 2]]); index /= 2)
		swap_pq(index, index / 2);
}

void MinIndexPQ::sink_pq(unsigned index)//将pq中位于index位置下行
{
	while (index*2 <= size)
	{
		unsigned &left_priority = priorities[pq[index*2]];
		if(index*2+1 > size)//没有右孩子
		{
			swap_pq(index, index * 2);
			return;
		}
		unsigned &right_priority = priorities[pq[index * 2+1]];
		unsigned swap_index = right_priority < left_priority ? index * 2 + 1 : index * 2;
		swap_pq(index, swap_index);
		index = swap_index;
	}
}

unsigned MinIndexPQ::get_priority(unsigned index)
{
	return priorities[index];
}

unsigned MinIndexPQ::min_index()
{
	return pq[1];
}

unsigned MinIndexPQ::min_priority()
{
	return priorities[pq[1]];
}

unsigned MinIndexPQ::del_min()
{
	swap_pq(1, size);
	size--;
	sink_pq(1);
	return priorities[pq[size+1]];
}

bool MinIndexPQ::empty()
{
	return size == 0;
}

unsigned MinIndexPQ::elements_size()
{
	return size;
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
