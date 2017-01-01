//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h>

/*
 * 本来想直接sort或者优先队列，几行代码给过的，看到提示中的不要用stl那就自己实现一个吧
 */

unsigned the_priority_queue[5000002];//优先队列 0号元素不用
unsigned priority_queue_size,k_th,temp_swap;//优先队列大小 第k大的数 临时使用的交换值

typedef bool(*UnsignedComparator)(unsigned, unsigned);//比较器类型
UnsignedComparator comparator;//优先队列比较器
void build_heap();//建立一个堆
unsigned exact_head();//取出对最前面的元素
void sink(unsigned index);//将index处的元素下行
void swim(unsigned index);//将index处的元素上行
void swap_element(unsigned i, unsigned j);//交换i，j两个地方的元素
//两个比较器
bool unsigned_less(unsigned num1, unsigned num2) { return num1 < num2; }
bool unsigned_greater(unsigned num1, unsigned num2) { return num1 > num2; }

int main()
{
	while (scanf("%u %u",&priority_queue_size, &k_th) == 2)
	{
		for (unsigned i = 1; i <= priority_queue_size; i++)
			scanf("%u", the_priority_queue+i);
		if( k_th > priority_queue_size/2)
		{
			//如果是在后一半大的位置上，那么找第priority_queue_size - k_th + 1大的数
			comparator = unsigned_greater;
			k_th = priority_queue_size - k_th + 1;
		}
		else comparator = unsigned_less;
		build_heap();
		for (unsigned i = 1; i < k_th; i++)
			exact_head();
		printf("%u\n", exact_head());
	}
	return 0;
}

inline void build_heap()
{
	for (unsigned i = priority_queue_size / 2; i > 0; i--)
		sink(i);
}

inline unsigned exact_head()
{
	swap_element(1, priority_queue_size);
	priority_queue_size--;
	sink(1);
	return the_priority_queue[priority_queue_size+1];
}

void sink(unsigned index)
{
	while (index *2 <= priority_queue_size)
	{
		unsigned swap_index = comparator(the_priority_queue[index * 2], the_priority_queue[index]) ? index * 2 : index;
		if(index * 2 + 1 <= priority_queue_size)//有右孩子
			swap_index = comparator(the_priority_queue[index * 2+1], the_priority_queue[swap_index]) ? index * 2+1 : swap_index;
		if(swap_index == index)//已经比孩子的优先级高了
			return;
		swap_element(swap_index, index);
		index = swap_index;
	}
}

void swim(unsigned index)
{
	for (; index > 1 && comparator(the_priority_queue[index], the_priority_queue[index / 2]); index /= 2)
		swap_element(index / 2, index);
}

void swap_element(unsigned i, unsigned j)
{
	temp_swap = the_priority_queue[i];
	the_priority_queue[i] = the_priority_queue[j];
	the_priority_queue[j] = temp_swap;
}

#endif