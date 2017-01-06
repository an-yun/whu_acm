//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <algorithm>

using std::abs;
using std::max;
/*
 * 显然垂直方向和竖直方向是对称的，而且两个方向的距离之差不能为奇数
 * 因为两个方向的移动都是偶数，所以一个取移动距离长的用就可以了
 */
unsigned test_case_num, chessboard_size;//测试用例数 棋盘大小
int position[3][2];//坐标


int main()
{
	scanf("%u", &test_case_num);
	for (unsigned test_no = 1; test_no <= test_case_num; test_no++)
	{
		scanf("%u", &chessboard_size);
		scanf("%d%d%d%d", position[0], position[0] + 1, position[1], position[1] + 1);
		//计算距离差
		position[2][0] = abs(position[0][0] - position[1][0]);
		position[2][1] = abs(position[0][1] - position[1][1]);
		//输出
		printf("Case %u:\n", test_no);
		if (abs(position[2][0] - position[2][1])%2)printf("-1\n\n");//距离差是奇数
		else printf("%d\n\n", max(position[2][0], position[2][1]));
	}
	return 0;
}
#endif
