//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h>
#include <complex>

/*
 * 核心点是垂足三角形
 */

using std::sqrt;

struct Point
{
	double x;
	double y;
};

Point all_points[6];//所有的点

//计算 all_points[point_index] 到线all_points[line_start_index],all_points[line_start_index]的垂足，存在all_points[save_index]
void caculate_pedal(int point_index, int line_start_index, int line_end_index, int save_index);

//计算垂足三角形的周长 三个顶点在all_points[3]，all_points[4]，all_points[5]
double get_perimeter();

int main()
{
	int test_case_num;	//	测试用例个数
	scanf("%d", &test_case_num);
	for (int i = 0; i < test_case_num; ++i)
	{
		//输入三个顶点
		scanf("%lf %lf ", &(all_points[0].x), &(all_points[0].y));
		scanf("%lf %lf ", &(all_points[1].x), &(all_points[1].y));
		scanf("%lf %lf", &(all_points[2].x), &(all_points[2].y));
		//计算三个垂足
		caculate_pedal(0, 1, 2, 3);
		caculate_pedal(1, 0, 2, 4);
		caculate_pedal(2, 0, 1, 5);
		//输出周长
		printf("%.3f\n", get_perimeter());
	}
	return 0;
}

inline void caculate_pedal(int point_index, int line_start_index, int line_end_index, int save_index)
{
	Point &p1 = all_points[line_start_index];
	Point &p2 = all_points[line_end_index];
	Point &p3 = all_points[point_index];
	double x21 = p2.x - p1.x;
	double y21 = p2.y - p1.y;
	double x31 = p3.x - p1.x;
	double y31 = p3.y - p1.y;
	double x21_square = x21*x21;
	double y21_square = y21*y21;
	double x21_y21_square = x21_square + y21_square;
	double x21_y21 = x21*y21;

	all_points[save_index].x = (x21_y21*y31 + x21_square*p3.x + y21_square*p1.x) / x21_y21_square;
	all_points[save_index].y = (x21_y21*x31 + x21_square*p1.y + y21_square*p3.y) / x21_y21_square;
}

inline double get_perimeter()
{
	Point &p4 = all_points[3];
	Point &p5 = all_points[4];
	Point &p6 = all_points[5];
	double x54 = p5.x - p4.x;
	double y54 = p5.y - p4.y;
	double x64 = p6.x - p4.x;
	double y64 = p6.y - p4.y;
	double x65 = p6.x - p5.x;
	double y65 = p6.y - p5.y;
	x54 = x54*x54;
	y54 = y54*y54;
	x64 = x64*x64;
	y64 = y64*y64;
	x65 = x65*x65;
	y65 = y65*y65;

	double perimeter = sqrt(x54 + y54);
	perimeter += sqrt(x64 + y64);
	perimeter += sqrt(x65 + y65);
	return perimeter;
}
#endif