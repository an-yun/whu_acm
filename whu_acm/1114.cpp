//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h> 

//计算平方距离
#define CACULATE_SQUARE_DISTANCE(p) (p[0]*p[0] + p[1]*p[1])

double position[2][3][2];//两个打靶的位置
unsigned score1, score2;//两个人的分数

unsigned caculate_score(double  square_distance);

int main()
{
	for (;;)
	{
		//输入第一个人的击中的位置
		scanf("%lf %lf %lf %lf %lf %lf", position[0][0], position[0][0] + 1, position[0][1], position[0][1] + 1, position[0][2], position[0][2] + 1);
		if (position[0][0][0] == -100)break;
		//输入第二个人的击中的位置
		scanf("%lf %lf %lf %lf %lf %lf", position[1][0], position[1][0] + 1, position[1][1], position[1][1] + 1, position[1][2], position[1][2] + 1);
		score1 = caculate_score(CACULATE_SQUARE_DISTANCE(position[0][0])) + caculate_score(CACULATE_SQUARE_DISTANCE(position[0][1])) + caculate_score(CACULATE_SQUARE_DISTANCE(position[0][2]));
		score2 = caculate_score(CACULATE_SQUARE_DISTANCE(position[1][0])) + caculate_score(CACULATE_SQUARE_DISTANCE(position[1][1])) + caculate_score(CACULATE_SQUARE_DISTANCE(position[1][2]));
		if (score1 > score2)
			printf("SCORE: %u to %u, PLAYER 1 WINS.\n", score1, score2);
		else if(score1 == score2)
			printf("SCORE: %u to %u, TIE.\n", score1, score2);
		else
			printf("SCORE: %u to %u, PLAYER 2 WINS.\n", score1, score2);
	}
	return 0;
}


inline unsigned caculate_score(double square_distance)
{
	if (square_distance <= 9) return 100;
	if (square_distance <= 36) return 80;
	if (square_distance <= 81) return 60;
	if (square_distance <= 144) return 40;
	if (square_distance <= 225) return 20;
	return 0;
}
#endif