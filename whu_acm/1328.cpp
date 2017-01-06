//用于运行
#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
#include <string.h>
/*
 * 题目不难就是，就是译码有点长
 */

const char encode[43] =
"234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";//密文
const char decode[43] =
"1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";//原文

char decoder[128];
char input[256],*input_point;//输入

int main()
{
	memset(decoder, -1, 128 * sizeof(char));
	//计算译码器
	for(unsigned i=0;i<42;i++)
		decoder[encode[i]] = decode[i];
	while (fgets(input,256,stdin) != NULL)
	{
		input_point = input;
		while (*input_point!= '\0')
		{
			char &ch = *input_point;
			ch = decoder[ch] == -1 ? ch : decoder[ch];
			input_point++;
		}
		printf("%s", input);
	}
	return 0;
}
#endif
