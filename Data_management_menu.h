#include "Data_management_operator.h"

void Data_management_show()
{
    printf("  *************************************\n");
    printf("  *          学生资料管理             *\n");
    printf("  *                                   *\n");
    printf("  *         1.录入学生资料            *\n");
    printf("  *         2.删除学生资料            *\n");
    printf("  *         3.添加学生资料            *\n");
    printf("  *         4.修改学生资料            *\n");
    printf("  *         5.读取学生资料            *\n");
    printf("  *         0.返回                    *\n");
    printf("  *                                   *\n");
    printf("  *         按Enter继续               *\n");
    printf("  *************************************");
}


void Data_management()
{
    system("cls");          //清屏
    Data_management_show(); //学生资料管理界面显示
    while (1)               //按回车键继续
    {
        if (getch() == 13)
            break;
    }
    while (1)
    {
        int choice;
        printf("\n请输入操作对应的序号：");
        scanf(" %d", &choice);
        if (choice == 1)
            Data_keyin(); //录入学生资料

        else if (choice == 2)
        {
            long long number;
            printf("请输入要删除的学生学号：");
            scanf(" %lld", &number);
            Data_delete(number); //删除学生资料
        }

        else if (choice == 3)
        {
            long long number;
            printf("请问要添加在哪位学生之后？（若无该生将自动添加在最后）\n");
            printf("当输入学号0时返回上一级！\n");
            printf("请输入该生的学号：");
            scanf(" %lld", &number);
            Data_add(number); //添加学生资料
        }

        else if (choice == 4)
        {
            long long number;
            printf("当输入学号0时返回上一级！\n");
            printf("请输入要修改的学生学号：");
            scanf(" %lld", &number);
            Data_change(number); //修改学生资料
        }

        else if (choice == 5)
            Data_read(); //读取学生资料

        else if (choice == 0) //返回
        {
            system("cls");
            return;
        }

        else
            printf("请输入正确的序号!");
    }
}