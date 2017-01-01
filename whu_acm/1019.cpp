//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include<stdio.h>

const char *sperater_line =
"+-----+-----------+-----------+-----------+-----------+-----------+\n";
const char *weekday =
"|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |\n";
const char *morning =
"|                          Morning                                |\n";
const char *afternoon =
"|                         Afternoon                               |\n";

char all_class[35][12];
char one_line_class[] =
"|  1  |%s|%s|%s|%s|%s|\n";

char input_line[36];

void set_all_blank();
void set_course(int day_num, int time_num,int course_name_length);
void print_schedule_table();

int main()
{
	int course_num,course_name_length,day_num,time_num;
	while (scanf("%d\n",&course_num) == 1)
	{
		set_all_blank();
		for(int courser_no =0;courser_no < course_num;courser_no++)
		{
			fgets(input_line,36,stdin);
			course_name_length = 0;
			while (input_line[course_name_length] != ':')
				course_name_length++;
			//判断星期几
			if (input_line[course_name_length + 2] == 'M')
				day_num = 0;
			else if (input_line[course_name_length + 2] == 'W')
				day_num = 2;
			else if (input_line[course_name_length + 2] == 'F')
				day_num = 4;
			else if (input_line[course_name_length + 3] == 'U')
				day_num = 1;
			else day_num = 3;
			//判断第几节课
			if (input_line[course_name_length + 6] == 'M')//上午
				time_num = input_line[course_name_length + 14] - '1';
			else//下午
				time_num = input_line[course_name_length + 16] - '1' + 4;

			set_course(day_num, time_num, course_name_length);
		}
		print_schedule_table();
		printf("\n");
	}
	return 0;
}

inline void set_all_blank()
{
	for (int time_num = 0; time_num < 7; time_num++)
	{
		for (int day_num = 0; day_num < 5; day_num++)
		{
			char *the_line_class = all_class[time_num * 5 + day_num];
			for (int i = 0; i<11; i++)
				the_line_class[i] = ' ';
			the_line_class[11] = '\0';
		}
	}

}

inline void set_course(int day_num, int time_num, int course_name_length)
{
	char *the_line_class = all_class[time_num * 5 + day_num];
	int i = 0, name_start = (11 - course_name_length) / 2, name_end = name_start + course_name_length;
	for (; i<name_start; i++)
		the_line_class[i] = ' ';
	for(;i<name_end;i++)
		the_line_class[i] = input_line[i-name_start];
	for (;i<11;i++)
		the_line_class[i] = ' ';
	the_line_class[11] = '\0';
}

inline void print_schedule_table()
{
	//打印头部
	printf(sperater_line);
	printf(weekday);
	printf(sperater_line);
	//打印morining
	printf(morning);
	printf(sperater_line);
	//打印上午课程
	one_line_class[3] = '1';
	printf(one_line_class, all_class, all_class+1, all_class+2, all_class+3, all_class+4);
	printf(sperater_line);
	one_line_class[3] = '2';
	printf(one_line_class, all_class+5, all_class + 6, all_class + 7, all_class + 8, all_class + 9);
	printf(sperater_line);
	one_line_class[3] = '3';
	printf(one_line_class, all_class + 10, all_class + 11, all_class + 12, all_class + 13, all_class + 14);
	printf(sperater_line);
	one_line_class[3] = '4';
	printf(one_line_class, all_class + 15, all_class + 16, all_class + 17, all_class + 18, all_class + 19);
	printf(sperater_line);
	//打印afternoon
	printf(afternoon);
	printf(sperater_line);
	//打印下午午课程
	one_line_class[3] = '1';
	printf(one_line_class, all_class + 20, all_class + 21, all_class + 22, all_class + 23, all_class + 24);
	printf(sperater_line);
	one_line_class[3] = '2';
	printf(one_line_class, all_class + 25, all_class + 26, all_class + 27, all_class + 28, all_class + 29);
	printf(sperater_line);
	one_line_class[3] = '3';
	printf(one_line_class, all_class + 30, all_class + 31, all_class + 32, all_class + 33, all_class + 34);
	printf(sperater_line);
}
#endif