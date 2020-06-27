#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "Data_management_menu.h"
#include "Data_analysis.h"
#include "Data_inquiry.h"
#include "System_about.h"

void mainwindow_show() //主菜单显示函数
{
    printf("********************************************************");
    printf("\n*                 操作菜单                             *\n");
    printf("*                                                      *\n");
    printf("*               1.学生资料管理                         *\n");
    printf("*               2.学生成绩统计管理                     *\n");
    printf("*               3.学生查询管理                         *\n");
    printf("*               4.关于系统                             *\n");
    printf("*               0.退出系统                             *\n");
    printf("*                                                      *\n");
    printf("*               按Enter继续                            *\n");
    printf("*******************************************************\n");
    printf("*                                                      *\n");
    printf("********************************************************");

    while (1) //按回车键继续
    {
        if (getch() == 13)
            break;
    }
}
void mainwindow_operator() //主菜单操作选择
{
    while (1)
    {
        int choice;
        printf("\n请输入操作对应的序号：");
        scanf("%d", &choice);
        if (choice == 1)
        {
            Data_management(); //学生资料管理
            break;
        }

        if (choice == 2)
        {
            if (flag == 0) //判断是否已录入数据
            {
                printf("暂未录入数据！\n");
                char ss;
                while (1)
                {
                    printf("是否返回上一级(y/n)：");
                    scanf(" %c", &ss);
                    if (ss == 'y')
                    {
                        system("cls");
                        return;
                    }
                }
            }
            Data_analysis(); //学生成绩统计管理
            break;
        }

        if (choice == 3)
        {
            Data_inquiry(); //学生查询管理
            break;
        }

        if (choice == 4)
        {
            System_about(); //关于系统
            break;
        }

        if (choice == 0)
            exit(0); //退出系统

        else
            printf("请输入正确的序号!");
    }
}