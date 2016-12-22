#include <stdio.h> 
#include <map>

using std::map;
using std::pair;


int weight[100];//权重
int value[100];//分数
int sovle_0_1_pack(int animal_size, int total_c);

int main1005()
{
	int animal_size;	//	动物个数
	while (scanf("%d", &animal_size) == 1)
	{
		//输入动物信息
		for (int i = 0; i < animal_size; i++)
			scanf("%d %d", &weight[i], &value[i]);
		int total_c;	// 总容量
		scanf("%d", &total_c);

		//this is my first temp
		printf("%d\n", sovle_0_1_pack(animal_size, total_c));
	}
	return 0;
}

int sovle_0_1_pack(int animal_size, int total_c)
{
	map<int, int> optimal_value;
	optimal_value[0] = 0;

	for (int row = 0; row < animal_size; row++)
	{
		int current_anmal_weight = weight[row], current_anmal_point = value[row];
		if (current_anmal_weight > total_c) continue;
		map<int, int> add_optimal_value;
		for (map<int, int>::iterator b = optimal_value.begin(), e = optimal_value.end(); b != e; b++)
		{
			int num_1_c = (*b).first, num_1_p = (*b).second;
			int new_c = num_1_c + current_anmal_weight;//新容量
			int new_p = num_1_p + current_anmal_point;//新分数
			if (new_c <= total_c)
			{
				map<int, int>::iterator lower_solution = --optimal_value.upper_bound(new_c);
				if ((*lower_solution).second < new_p)
					add_optimal_value[new_c] = new_p;
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
