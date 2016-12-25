//用于调试
//#define MY_DEBUG_1027

#include <stdio.h>
#include <algorithm>
#ifdef MY_DEBUG_1027

#include <iostream>
using std::cout;
using std::endl;
#endif

/*
 * 这题很有意思，核心点有三个：
 * 1.蚂蚁相遇之后，由于速度一样，可以看作直接穿过了对面的蚂蚁
 * 2.任何时刻蚂蚁的相对位置不变：
 *		假设任意三个相邻的蚂蚁，初始时刻，按顺时针方向依次是A(i-1),A(i),A(i+1)
 *		那么在以后的任意时刻都保持这种相对的位置关系
 * 3.结合1、2：
 *		由于蚂蚁看作直接穿过对面的蚂蚁，可以计算蚂蚁"A(i)"任意时刻之后的位置：(P(i) + t) mod  L.(可能由于相遇，计算的位置并不是A(i)的位置,但一定是某一个蚂蚁的位置，所以加了引号)
 *		相对位置不变，只要确定某一个蚂蚁的位置，其他按照相对位置关系就可以算出来。
 *		最核心的是：确定某一个蚂蚁的位置:
 *			不妨确定A(0)的位置(假设A(0)顺时针移动)，设某一个逆时针移动蚂蚁为A(j)
 *			若 P(j) - P(0) < 2 * t ,那么(P(0) + t) mod  L 就是A(1)t时刻的位置(如果这样的A(j)有n个，那么就是A(n)的位置)
 *
 *总结：最后用了半天想明白上面的三点，用了半天写代码框架，用半天调试
 *   zuo 2016-12-25
 */

using std::sort;
using std::lower_bound;
using std::upper_bound;

struct AntsInfor
{
	int index;
	int position;
	bool is_clockwise;
};

AntsInfor ants_infor[1000004];//蚂蚁序号，蚂蚁初始位置，是否顺时针
AntsInfor *clockwise_ants[1000004];//顺时针蚂蚁指针
AntsInfor *counter_clockwise_ants[1000004];//逆时针蚂蚁指针
int ants_t_position[1000004];//t 时刻蚂蚁的位置
//测试用例数 分区数 蚂蚁数 时刻 序号偏移 顺时针蚂蚁指针数  逆时针蚂蚁指针数
int test_case_num, parts_num, ants_num, t, offset, clockwise_ants_num, counter_clockwise_ants_num;
int temp_position, temp_direction;//临时位置 临时方向
int true_i, ant_no, ant_t_position;

//蚂蚁位置比较器
bool ants_comparator(const AntsInfor &ants1, const AntsInfor &ants2)
{
	return ants1.position < ants2.position;
}

//返回第一个大于等于search_key_position的蚂蚁位置
int binary_search(AntsInfor **ants_start, int n, int search_key_position);
//查询位置在[low_position,high_position)中间的蚂蚁数
int count_range(AntsInfor **ants_start, int n, int start_position, int range);
void solve_one_case();
#ifdef MY_DEBUG_1027
void test_binary_search();
void test_count_range();
#endif
int main1027()
{


#ifdef MY_DEBUG_1027
	parts_num = 21;
	ants_num = 20;
	clockwise_ants_num = counter_clockwise_ants_num = 0;
	for (int i = 0; i < ants_num; i++)
	{
		AntsInfor &one_ants_infor = ants_infor[i];
		one_ants_infor.index = i;
		one_ants_infor.position = i + 1;
		one_ants_infor.is_clockwise = true;
		if (i % 2)
			counter_clockwise_ants[counter_clockwise_ants_num++] = ants_infor + i;
		else
			clockwise_ants[clockwise_ants_num++] = ants_infor + i;
	}
	test_binary_search();
	cout << endl;
	test_count_range();

#else
	scanf("%d", &test_case_num);
	for (int test_case_no = 1; test_case_no < test_case_num; ++test_case_no)
	{
		printf("Case %d:\n", test_case_no);
		solve_one_case();
		printf("\n");
		printf("\n");
	}
	//处理最后一个Case
	printf("Case %d:\n", test_case_num);
	solve_one_case();
#endif
	return 0;
}


void solve_one_case()
{
	scanf("%d %d %d", &parts_num, &ants_num, &t);

	//输入蚂蚁信息，按位置排序
	for (int ants_index = 0; ants_index < ants_num; ++ants_index)
	{
		scanf("%d %d", &temp_position, &temp_direction);
		AntsInfor &one_ants_infor = ants_infor[ants_index];
		one_ants_infor.index = ants_index;
		one_ants_infor.position = temp_position;
		one_ants_infor.is_clockwise = temp_direction == 1;
	}
	sort(ants_infor, ants_infor + ants_num, ants_comparator);
	//对顺时针和逆时针蚂蚁分区
	clockwise_ants_num = counter_clockwise_ants_num = 0;
	for (int ants_index = 0; ants_index < ants_num; ++ants_index)
	{
		AntsInfor &one_ants_infor = ants_infor[ants_index];
		if (one_ants_infor.is_clockwise)
			clockwise_ants[clockwise_ants_num++] = ants_infor + ants_index;
		else
			counter_clockwise_ants[counter_clockwise_ants_num++] = ants_infor + ants_index;
	}

	int length = t * 2;
	int round = length / parts_num;
	t = t % parts_num;
	for (int i = 0; i < ants_num; i++)
	{
		//计算t时刻之后，序号偏移
		AntsInfor &current_ants_infor = ants_infor[i];//当前蚂蚁
		//A(i)相对的移动距离，和圈数
		int lower_length = length % parts_num;
		if (current_ants_infor.is_clockwise)//如果顺时针移动
		{
			//计算相遇的逆时针移动的蚂蚁数目
			if (lower_length != 0)//计算不足一圈相遇数目
				lower_length = count_range(counter_clockwise_ants, counter_clockwise_ants_num, current_ants_infor.position, lower_length);
			//计算相遇次数
			offset = (lower_length + round * counter_clockwise_ants_num) % ants_num;
			true_i = (i + offset) % ants_num;//真实位置
			ant_no = ants_infor[true_i].index;//序号
			ant_t_position = (parts_num + current_ants_infor.position + t) % parts_num;
			ants_t_position[ant_no] = ant_t_position;
		}
		else//如果逆时针移动
		{
			if (lower_length != 0)//计算不足一圈相遇数目
				lower_length = count_range(clockwise_ants, clockwise_ants_num, current_ants_infor.position, -lower_length);
			//计算相遇次数
			offset = (lower_length + round * clockwise_ants_num) % ants_num;
			offset = ants_num - offset;
			true_i = (i + offset) % ants_num;//真实位置
			ant_no = ants_infor[true_i].index;//序号
			ant_t_position = (parts_num + current_ants_infor.position - t) % parts_num;
			ants_t_position[ant_no] = ant_t_position;
		}

	}

	//输出结果
	for (int i = 0; i < ants_num-1; i++)
		printf("%d ", ants_t_position[i]);
	printf("%d", ants_t_position[ants_num - 1]);
}


int binary_search(AntsInfor ** ants_start, int n, int search_key_position)
{
	int low = 0, high = n - 1, mid = low + (high - low) / 2;
	while (low <= high)
	{
		AntsInfor &current_ant = **(ants_start + mid);
		if (current_ant.position > search_key_position)
			high = mid - 1;
		else if (current_ant.position == search_key_position)
			return mid;
		else
			low = mid + 1;
		mid = low + (high - low) / 2;
	}
	return low;
}


int count_range(AntsInfor **ants_start, int n, int start_position, int range)
{
	if (range > 0)//正向范围
	{
		if(start_position + range > parts_num)//如果过了零点
		{
			//计算反向范围然后求((start_position + range)%parts_num , start_position)的补集数
			int high_index = binary_search(ants_start, n, start_position);
			int low_position = (start_position + range) % parts_num;
			int low_index = binary_search(ants_start, n, low_position);
			if (low_index!= n && (**(ants_start + low_index)).position == low_position)//多算了起点
				low_index++;
			return n-(high_index - low_index);
		}
		else if(start_position + range == parts_num)//恰好在零点
		{
			int result =  n - binary_search(ants_start, n, start_position);
			if ((**ants_start).position == 0) result++;//零点处有一个
			return result;
		}
			
		else//如果没过零点
		{
			int high_index = binary_search(ants_start, n, start_position + range);
			if (high_index != n && (**(ants_start + high_index)).position == start_position + range)//没有算结尾点
				high_index++;
			int low_index =  binary_search(ants_start, n, start_position);
			return high_index - low_index;
		}
	}
	else//反向范围
	{
		if (start_position + range < 0)//如果过了零点
		{
			//计算反向范围然后求(start_position，(start_position + range + parts_num)%parts_num )的补集数
			int high_position = (start_position + range + parts_num) % parts_num;
			int high_index = binary_search(ants_start, n, high_position);
			int low_index = binary_search(ants_start, n, start_position);
			return n - (high_index - low_index);
		}
		else if (start_position + range == 0)//恰好在零点
			return binary_search(ants_start, n, start_position);
		else//如果没过零点
		{
			int high_index = binary_search(ants_start, n, start_position);
			int low_index = binary_search(ants_start, n, start_position + range);
			return high_index - low_index;
		}
	}
}


#ifdef MY_DEBUG_1027
void test_binary_search()
{
	cout << binary_search(clockwise_ants, clockwise_ants_num, 0) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 1) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 2) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 3) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 6) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 18) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 19) << endl;
	cout << binary_search(clockwise_ants, clockwise_ants_num, 20) << endl;

	cout << endl;

	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 0) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 1) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 2) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 3) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 6) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 19) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 20) << endl;
	cout << binary_search(counter_clockwise_ants, counter_clockwise_ants_num, 21) << endl;
}
void test_count_range()
{

	cout << count_range(clockwise_ants, clockwise_ants_num, 0, 3) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 0, -3) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 2, -5) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 2, -4) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 6, 4) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 18, 7) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 18, -7) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 20, -8) << endl;
	cout << count_range(clockwise_ants, clockwise_ants_num, 20, 8) << endl;

	cout << endl;

	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 1, 3) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 1, -3) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 3, -5) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 3, -4) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 5, 4) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 17, 7) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 17, -7) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 19, -8) << endl;
	cout << count_range(counter_clockwise_ants, counter_clockwise_ants_num, 19, 8) << endl;
}
#endif