#include <stdio.h> 
#include <map>

using std::map;
using std::pair;


int nums[100];//所有数字
int num_size, total_c,max_c;	//	数字个数 可加入的总容量 最大容量
int sovle_0_1_pack();

int main1187()
{

	while (scanf("%d", &num_size) == 1)
	{
		max_c = 0;//最大容量置零
		//输入数字
		for (int i = 0; i < num_size; i++)
		{
			scanf("%d", &nums[i]);
			max_c += nums[i];
		}
		//总和的一半
		total_c = max_c / 2;
		//最大容量
		printf("%d\n", max_c - sovle_0_1_pack()*2);
	}
	return 0;
}

int sovle_0_1_pack()
{
	map<int, int> optimal_value;
	optimal_value[0] = 0;

	for (int row = 0; row < num_size; row++)
	{
		int current_anmal_weight = nums[row];
		if (current_anmal_weight > total_c) continue;
		map<int, int> add_optimal_value;
		for (map<int, int>::iterator b = optimal_value.begin(), e = optimal_value.end(); b != e; b++)
		{
			int num_1_c = (*b).first, num_1_p = (*b).second;
			int new_c = num_1_c + current_anmal_weight;//新容量
			if (new_c <= total_c)
			{
				map<int, int>::iterator lower_solution = --optimal_value.upper_bound(new_c);
				if ((*lower_solution).second < new_c)
					add_optimal_value[new_c] = new_c;
			}
			else break;
		}
		//合并跳跃点
		map<int, int> new_optimal_value = optimal_value;
		for (map<int, int>::iterator b = add_optimal_value.begin(), e = add_optimal_value.end(); b != e; b++)
			new_optimal_value[(*b).first] = (*b).second;
		//去掉控制点
		optimal_value.clear();
		map<int, int>::iterator last_b = new_optimal_value.begin();
		int last_c = (*last_b).first, last_p = (*last_b).second;
		optimal_value[last_c] = last_p;
		for (map<int, int>::iterator b = ++new_optimal_value.begin(), e = new_optimal_value.end(); b != e; b++)
		{
			int current_c = (*b).first, current_p = (*b).second;
			if (current_p <= last_p)
				continue;
			optimal_value[current_c] = current_p;
			last_c = current_c;
			last_p = current_p;
		}

	}

	map<int, int>::iterator lower_solution = --optimal_value.upper_bound(total_c);
	return (*lower_solution).second;
}
