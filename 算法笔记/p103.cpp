#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 这是一道很直白的题目，就是写起来稍微麻烦些，没有什么算法
 * 
 * 输入：
 * 
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
 * 
 * 输出：
 * 
 * 考号 排名 考场号 考场内排名
 */

// 学生信息
typedef struct student_info
{
    int s_id;
    int score;
    int room;       // 考场号码
    int room_range; // 考场内排名
    int all_range;  // 总排名
} s_info, *ptr_s_info;

// 考场信息
typedef struct room_info
{
    int r_id;             // 考场号
    int s_num;            // 考场学生数量
    ptr_s_info *students; // 学生信息
} r_info, *ptr_r_info;

typedef struct students
{
    int total_students;       // 学生总人数
    int total_rooms;          // 教室总数量
    ptr_r_info *rooms;        // 教室信息数组
    ptr_s_info *all_students; // 所有学生
} Students;

// 排名函数
static int cmp(const void *s1, const void *s2)
{

    if ((*(ptr_s_info *)s1)->score != (*(ptr_s_info *)s2)->score)
    {
        if ((*(ptr_s_info *)s1)->score > (*(ptr_s_info *)s2)->score)
            return -1;
        else
            return 1;
    }
    else
    {
        if ((*(ptr_s_info *)s2)->s_id != (*(ptr_s_info *)s2)->s_id)
        {
            if ((*(ptr_s_info *)s2)->s_id > (*(ptr_s_info *)s2)->s_id)
                return 1;
            else
                return -1;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    Students students;
    students.total_students = 0;
    students.total_rooms = 0;
    students.rooms = 0;

    int room_stds; // 教室学生人数
    int i = 0;
    int j = 0;

    /** 输入数据 **/

    // 考场总数
    scanf("%d", &students.total_rooms);
    students.rooms = (ptr_r_info *)malloc(sizeof(ptr_r_info) * students.total_rooms);

    // 每个考场学生的id以及分数
    for (i = 0; i < students.total_rooms; i++)
    {
        students.rooms[i] = (ptr_r_info)malloc(sizeof(r_info));
        // 考场人数
        scanf("%d", &room_stds);
        students.total_students += room_stds;
        students.rooms[i]->s_num = room_stds;
        students.rooms[i]->r_id = i + 1;
        students.rooms[i]->students = (ptr_s_info *)malloc(sizeof(ptr_s_info) * room_stds);

        for (j = 0; j < room_stds; j++)
        {
            students.rooms[i]->students[j] = (ptr_s_info)malloc(sizeof(s_info));
            // 获取学生信息
            scanf("%d", &students.rooms[i]->students[j]->s_id);
            scanf("%d", &students.rooms[i]->students[j]->score);
            students.rooms[i]->students[j]->room = i;
        }
    }

    /** 排名 **/

    // 对每个教室的学生按照分数和学号进行排名
    for (i = 0; i < students.total_rooms; i++)
    {
        // 每个教室进行排名
        qsort(students.rooms[i]->students, students.rooms[i]->s_num, sizeof(ptr_s_info), cmp);
        for (j = 0; j < students.rooms[i]->s_num; j++) {
            students.rooms[i]->students[j]->room_range = j + 1;
        }
    }

    // 所有学生放一块
    students.all_students = (ptr_s_info *)malloc(sizeof(ptr_s_info) * students.total_students);

    // 所有学生放一块进行排名
    int t = 0;
    for (i = 0; i < students.total_rooms; i++)
    {
        for (j = 0; j < students.rooms[i]->s_num; j++)
        {
            students.all_students[t] = (ptr_s_info)malloc(sizeof(s_info));
            memcpy(students.all_students[t], students.rooms[i]->students[j], sizeof(s_info));
            t++;
        }
    }

    // 所有学生排序
    qsort(students.all_students, students.total_students, sizeof(ptr_s_info), cmp);

    for (i = 0; i < students.total_students; i++)
    {
        printf("%d %d %d %d\n", students.all_students[i]->s_id, i + 1, students.all_students[i]->room, students.all_students[i]->room_range);
    }
    return 0;
}
