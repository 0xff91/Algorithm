#include <stdio.h>

/**
 * 考场数量
 *
 * 考场人数
 * 考场考号 成绩
 * 考场考号 成绩
 * 考场考号 成绩
 * 考场考号 成绩
 *
 * 考场人数
 * 考场考号 成绩
 * 考场考号 成绩
 * 考场考号 成绩
 * 考场考号 成绩
 */

// 学生信息
typedef struct student_info {
    int s_id;
    int score;
    int room;   // 考场号码
} s_info, *ptr_s_info;

// 考场信息
typedef struct room_info {
    int r_id;   // 考场号
    int s_num;  // 考场学生数量
    ptr_s_info *students;   // 学生信息
} r_info, *ptr_r_info;

int main(int argc, char* argv[])
{
    int total_rooms;
    int i = 0;

    return 0;
}
