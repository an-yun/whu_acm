#include <stdio.h> 
#include <string.h>
#include <numeric>

using std::accumulate;

int number_of_animals;//动物数量
int animals_times[10002];//喂养时间
int temp_time;//临时时间
long long total_time;


int main1007()
{
	while (scanf("%d", &number_of_animals) == 1)//输入动物数量
	{
		memset(animals_times, 10000, sizeof(int)*number_of_animals);
		for (int row = 0; row < 8; row++)
		{
			//读取每一行
			for (int index = 0; index < number_of_animals; index++)
			{
				scanf("%d", &temp_time);
				if (temp_time < animals_times[index])//如果比较小就更新喂养时间
					animals_times[index] = temp_time;
			}
		}
		total_time = accumulate(animals_times, animals_times+ number_of_animals, 0LL);
		printf("%lld\n", total_time);
	}
}