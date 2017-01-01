//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdlib.h>
#include <stdio.h>

//计算三阶行列式的值,被绝对值坑了好久
char a[3][3];
int result;

int main()
{
	while (scanf("%d %d %d",a[0],a[0]+1,a[0]+2) == 3)
	{
		scanf("%d %d %d", a[1], a[1] + 1, a[1] + 2);
		scanf("%d %d %d", a[2], a[2] + 1, a[2] + 2);
		result = a[0][0] * a[1][1] * a[2][2];
		result += a[0][1] * a[1][2] * a[2][0];
		result += a[0][2] * a[1][0] * a[2][1];
		result -= a[0][2] * a[1][1] * a[2][0];
		result -= a[0][1] * a[1][0] * a[2][2];
		result -= a[0][0] * a[1][2] * a[2][1];
		printf("%d.00\n", abs(result));
	}
	return 0;
}
#endif