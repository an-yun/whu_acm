//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 *  题目比较简单
 */
char password[52];
unsigned char password_index;
unsigned test_case_no;//测试序号

int main()
{
	test_case_no = 1;
	for(;;)
	{
		scanf("%s", password);
		if(password[0] == '#') break;
		password_index = 0;
		while (password[password_index] != '\0' && password[++password_index] != '\0')
		{
			password[password_index] = 'A' + password[password_index] - 'a';
			password_index++;
		}
		printf("Case %d: %s\n", test_case_no++, password);
	}
	return 0;
}
#endif
