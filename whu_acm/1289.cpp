//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

/*
 *找不匹配的个数就行
 */

char dna_1[52];//第一个dna
char dna_2[52];//第二个dna
unsigned diffences_num;

void caculate_differences();//计算不同的个数

int main()
{
	for (;;)
	{
		scanf("%s", dna_1);
		if(dna_1[0] == '#') break;
		scanf("%s", dna_2);
		caculate_differences();
		printf("%u\n", diffences_num);
	}
	return 0;
}

inline void caculate_differences()
{
	diffences_num = 0;
	for(unsigned index = 0;dna_1[index] != '\0';index++)
	{
		switch (dna_1[index])
		{
		case 'A':
			if (dna_2[index] != 'T') diffences_num++;
			break;
		case 'C':
			if (dna_2[index] != 'G') diffences_num++;
			break;
		case 'G':
			if (dna_2[index] != 'C') diffences_num++;
			break;
		case 'T':
			if (dna_2[index] != 'A') diffences_num++;
			break;
		default:
			break;
		}
	}
	
}
#endif
