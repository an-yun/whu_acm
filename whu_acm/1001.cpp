//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a + b);
	return 0;
}
#endif
