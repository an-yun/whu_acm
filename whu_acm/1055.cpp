//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

char cipher[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";//解密的字符串
char input[202];// 输入

void decode_input();//解码输入
unsigned char_index;//输入指针

int main()
{
	for (;;)
	{
		scanf("%s\n", input);
		if(input[0] == 'E')break;
		fgets(input,202,stdin);
		//对输入解密
		decode_input();
		//输出
		printf("%s", input);
		scanf("%s", input);
	}
	return 0;
}


inline void decode_input()
{
	for (char_index = 0; input[char_index] != '\n'; char_index++)
	{
		if (input[char_index] >= 'A' && input[char_index] <= 'Z')
			input[char_index] = cipher[input[char_index] - 'A'];
	}
}

#endif

