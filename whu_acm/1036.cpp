#include <stdio.h> 
#include <map>
#include <bitset>

using std::map;
using std::bitset;

int main()
{
	const int appear_times = 1;//特定的出现次数
	unsigned n, temp_num;//数字个数 临时数字

	//方案1 map 计数 最后找出计数为1的数字即可
	map<int, char> nums_count;//用于计数的map
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp_num);
		nums_count[temp_num]++;
	}
	for (map<int, char>::iterator b = nums_count.begin(), e = nums_count.end(); b != e; b++)
		if ((*b).second == appear_times)	printf("%d ", (*b).first);
	printf("\n");

	//时间复杂度o(n log n) :14-18行时间 n log n, 19-20行时间 n log n,总耗时o(n log n)
	//空间复杂度o(n) :map里面最多存n/2 + 2个数
	//优点：可扩展性好，可以出现任意次数的数字，只要改下appear_times就可以了
	//缺点：时间复杂度略高，不是最优的o(n)

	//方案2 bitset 标记某个数是否已经出现过一次

	bitset<(1LL<<32)> nums_has_appear;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp_num);
		nums_has_appear[temp_num] = !nums_has_appear[temp_num];//取反标记是否已经出现
	}

	//时间复杂度o(n) :34-38行时间 n
	//空间复杂度512MB :UINTMAX_MAX B = 2 ^ 32 bit = 2 ^ 29 B = 512MB
	//优点：时间复杂度低
	//缺点：内存较多，即使数字比较少，也要512MB
}