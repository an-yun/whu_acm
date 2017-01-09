//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 


/*
 * 按照题意处理就行，判断是否有这个数的时候可以用map标记一下就行
 *		这里我就直接暴搜了
 */

unsigned test_case_num;//测试用例数
unsigned cards[100], cards_num;//所有的牌 牌数
unsigned cards_point,get_cards[2];//牌指针 两个人拥有的牌的数量

int main()
{
	scanf("%u", &test_case_num);
	for(unsigned test_case_no=0;test_case_no<test_case_num;test_case_no++)
	{
		scanf("%u", &cards_num);
		cards_point = get_cards[0] = get_cards[1] = 0;
		//开始游戏
		for(unsigned i=0;i<cards_num;i++)
		{
			scanf("%u", cards + cards_point);
			for(unsigned j =0;j<cards_point;j++)//找前面是否已经有出现过这个数
			{
				if (cards[j] == cards[cards_point])
				{
					get_cards[i % 2] += cards_point - j + 1;
					cards_point = j-1;//这里减1因为后面会加上1的
					break;
				}
			}
			cards_point++;
		}
		if (get_cards[0] > get_cards[1])printf("xay\n");
		else printf("amr\n");
	}
	return 0;
}
#endif
