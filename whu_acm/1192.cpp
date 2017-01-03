//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 
/*
 * 用位操作就好
 */
unsigned matrix_size;//矩阵大小 
unsigned temp_num;//临时数字 

inline unsigned xor_8_bits(unsigned num)
{
	return (num ^ (num >> 1) ^ (num >> 2) ^ (num >> 3) ^ (num >> 4) ^ (num >> 5) ^ (num >> 6) ^ (num >> 7)) % 2;
}

int main()
{
	while (scanf("%u", &matrix_size) == 1)
	{
		for (unsigned i = 0; i < matrix_size; i++)
		{
			for (unsigned j = 1; j < matrix_size; j++)
			{
				scanf("%u", &temp_num);
				printf("%u ", xor_8_bits(temp_num));
			}
			//处理每行的最后一个
			scanf("%u", &temp_num);
			printf("%u\n", xor_8_bits(temp_num));
		}
	}
	return 0;
}
#endif
