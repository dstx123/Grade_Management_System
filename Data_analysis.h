void Data_analysis_show()
{
    printf("********************************************************");
    printf("\n*                 学生成绩统计管理                     *\n");
    printf("*                                                      *\n");
    printf("*               1.成绩平均值                           *\n");
    printf("*               2.数据排序                             *\n");
    printf("*               3.学生平均成绩分布图                   *\n");
    printf("*               0.返回                                 *\n");
    printf("*                                                      *\n");
    printf("*               按Enter继续                            *\n");
    printf("*******************************************************");
}

#include <string.h>

void exchange(struct Student *p1, struct Student *p2) //交换链表中两节点的数据部分
{
    //临时变量
    long long stud_num;      //学号
    char stud_class[10];     //班级
    char stud_name[20];      //姓名
    float stud_chinese_mark; //语文成绩
    float stud_math_mark;    //数学成绩
    float stud_english_mark; //英语成绩
    float stud_average;      //平均成绩
    //开始交换数据
    stud_num = p2->num;
    strcpy(stud_class, p2->class);
    strcpy(stud_name, p2->name);
    stud_chinese_mark = p2->chinese_mark;
    stud_math_mark = p2->math_mark;
    stud_english_mark = p2->english_mark;
    stud_average = p2->average;

    p2->num = p1->num;
    strcpy(p2->class, p1->class);
    strcpy(p2->name, p1->name);
    p2->chinese_mark = p1->chinese_mark;
    p2->math_mark = p1->math_mark;
    p2->english_mark = p1->english_mark;
    p2->average = p1->average;

    p1->num = stud_num;
    strcpy(p1->class, stud_class);
    strcpy(p1->name, stud_name);
    p1->chinese_mark = stud_chinese_mark;
    p1->math_mark = stud_math_mark;
    p1->english_mark = stud_english_mark;
    p1->average = stud_average;
}

struct Student *head_sort; //计算平均值并排名后新的链表头指针

int flag_s = 0; //事先已求平均值则为1,若head_sort被改变则为0

void mark_average() //求出平均值及排名
{
    flag_s = 1;
    head = head_fixed;
    while (head != NULL) //求平均值
    {
        head->average = (head->chinese_mark + head->math_mark + head->english_mark) / 3.0;
        head = head->next;
    }
    //排序
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //平均值最小的
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->average) > (head->average)) //沉底排序
            {                                          //只交换链表中的数据不改变链表结构
                exchange(stud_min, head);
            }
            head = head->next;
        }
        if (i == 0)
            head_sort = stud_min;
        stud_min = stud_min->next;
        head = stud_min->next;
    }
    stud_min->next = NULL;
    //排名标号
    i = 0;
    head = head_sort;
    while (head != NULL)
    {
        i++;
        head->ranking = i;
        head = head->next;
    }
}

void mark_sort_output()
{
    head = head_sort;
    printf("%-5s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "排名", "学号", "姓名", "班级", "语文成绩", "数学成绩", "英语成绩", "平均成绩"); //输出
    while (head != NULL)
    {
        printf("%-5d%-10lld%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f\n",
               head->ranking, head->num, head->name, head->class, head->chinese_mark, head->math_mark, head->english_mark, head->average);
        head = head->next;
    }

    printf("共%d名学生\n", sum);
}

#include "Data_analysis_sort.h"

void Data_analysis()
{
    system("cls");
    Data_analysis_show();
    while (1) //按回车键继续
    {
        if (getch() == 13)
            break;
    }
    mark_average(); //求出平均值及排名
    while (1)
    {
        int choice;
        printf("\n请输入操作对应的序号：");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            if (flag_s = 0) //head_sort被其他操作改变过
                mark_average();
            mark_sort_output(); //查看成绩平均值
        }
        if (choice == 2)
        {
            sort_menu(); //数据排序
        }
        if (choice == 3)
        {
            printf("Python运行极其缓慢，请耐心等待！(摊手)\n");  //使用前在此处修改文件路径！！！！！
            system("Visualization\\students_scores_avg.exe"); //学生平均成绩分布图
        }
        if (choice == 0)
        {
            system("cls");
            return; //返回
        }
    }
}