//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 


/*
 * 就是计算逆序数：
 *		1.用map记录前面小于等于这个数的数目
 *			很遗憾，思路是对，可惜超时，因为时间复杂度是n^2*log n
 *		2.用稳定排序算法排序后，计算有多少个数排到前面去了
 *			很遗憾，这个思路是错的
 *		3.只能有归并排序统计了，时间复杂度是nlogn,而且只有手写归并
 *
 *
 *		这个题目很好,时间卡的很好
 */



unsigned nums_size;//数据规模
int all_nums[10000];//所有数字
int aux_nums[10000];//辅助数组 后面的归并排序可以利用辅助数组减少复制
unsigned inversion_num;//最终结果

void caculate_inversion();//计算逆序数
void merge_sort(int *nums, int *aux, unsigned start, unsigned end);//对aux的[start,end]归并排序，结果存在nums中
void merge(int *nums, int *aux, unsigned start, unsigned mid, unsigned end);//对[start,mid] ,(mid,end]合并

int main()
{
	for (;;)
	{
		scanf("%u", &nums_size);
		if (nums_size == 0)break;
		//输入数字并复制到辅助数组中
		for (unsigned i = 0; i < nums_size; i++)
		{
			scanf("%d", all_nums + i);
			aux_nums[i] = all_nums[i];
		}
		caculate_inversion();
		printf("%u\n", inversion_num);
	}
	return 0;
}

inline void caculate_inversion()
{
	inversion_num = 0;//置零
	merge_sort(all_nums, aux_nums, 0, nums_size - 1);
}

void merge_sort(int *nums, int *aux, unsigned start, unsigned end)
{
	if (start >= end)return;
	unsigned mid = (start + end) / 2;
	merge_sort(aux, nums, start, mid);
	merge_sort(aux, nums, mid + 1, end);
	if (mid + 1 > end || aux[mid] <= aux[mid + 1]) return;
	merge(nums, aux, start, mid, end);
}

inline void merge(int *nums, int *aux, unsigned start, unsigned mid, unsigned end)//将aux中的排序结果归并到nums中去
{
	unsigned i = start, j = mid + 1, k = start;//左边指针 右边指针 合并指针
	while (k <= end)
	{
		if (i > mid) nums[k++] = aux[j++];
		else if (j > end)nums[k++] = aux[i++];
		else if (aux[j] < aux[i])
		{
			nums[k++] = aux[j++];
			//注意这里计算的逆序数
			inversion_num += mid - i + 1;//当前右边数的都排在了所有数还未合并左边数的前面
		}
		else nums[k++] = aux[i++];
	}
}

#endif
