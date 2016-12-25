#include <stdio.h> 
#include <map>
#include <bitset>

using std::map;
using std::bitset;

int main()
{
	const int appear_times = 1;//�ض��ĳ��ִ���
	unsigned n, temp_num;//���ָ��� ��ʱ����

	//����1 map ���� ����ҳ�����Ϊ1�����ּ���
	map<int, char> nums_count;//���ڼ�����map
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp_num);
		nums_count[temp_num]++;
	}
	for (map<int, char>::iterator b = nums_count.begin(), e = nums_count.end(); b != e; b++)
		if ((*b).second == appear_times)	printf("%d ", (*b).first);
	printf("\n");

	//ʱ�临�Ӷ�o(n log n) :14-18��ʱ�� n log n, 19-20��ʱ�� n log n,�ܺ�ʱo(n log n)
	//�ռ临�Ӷ�o(n) :map��������n/2 + 2����
	//�ŵ㣺����չ�Ժã����Գ���������������֣�ֻҪ����appear_times�Ϳ�����
	//ȱ�㣺ʱ�临�Ӷ��Ըߣ��������ŵ�o(n)

	//����2 bitset ���ĳ�����Ƿ��Ѿ����ֹ�һ��

	bitset<(1LL<<32)> nums_has_appear;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp_num);
		nums_has_appear[temp_num] = !nums_has_appear[temp_num];//ȡ������Ƿ��Ѿ�����
	}

	//ʱ�临�Ӷ�o(n) :34-38��ʱ�� n
	//�ռ临�Ӷ�512MB :UINTMAX_MAX B = 2 ^ 32 bit = 2 ^ 29 B = 512MB
	//�ŵ㣺ʱ�临�Ӷȵ�
	//ȱ�㣺�ڴ�϶࣬��ʹ���ֱȽ��٣�ҲҪ512MB
}