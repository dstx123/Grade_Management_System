#include <string.h>
void Data_inquiry_show()
{
    printf("********************************************************");
    printf("\n*                 学生查询管理                         *\n");
    printf("*                                                      *\n");
    printf("*               1.按学号查询                           *\n");
    printf("*               2.按姓名查询                           *\n");
    printf("*               3.按所在班级查询                       *\n");
    printf("*               0.返回                                 *\n");
    printf("*                                                      *\n");
    printf("*               按Enter继续                            *\n");
    printf("*******************************************************");
    while (1) //按回车键继续
    {
        if (getch() == 13)
            break;
    }
}
void Searchbynum()
{
    if (flag == 0) //判断是否已录入数据
    {
        printf("暂未录入数据！");
        return;
    }
    long long number = 0;
    head = head_fixed;
    printf("请输入待查询学生学号：");
    scanf("%lld", &number);
    while (head->num != number)
    {
        if (head->next == NULL)
        {
            printf("该生不存在！\n");
            return;
        }
        head = head->next;
    }
    printf("学号：%lld\n", head->num);
    printf("姓名：%s\n", head->name);
    printf("班级：%s\n", head->class);
    printf("语文成绩：%.2f\n", head->chinese_mark);
    printf("数学成绩：%.2f\n", head->math_mark);
    printf("英语成绩：%.2f\n", head->english_mark);
}
void Searchbyname()
{
    if (flag == 0) //判断是否已录入数据
    {
        printf("暂未录入数据！");
        return;
    }
    char nam[20];
    head = head_fixed;
    printf("请输入待查询学生姓名：");
    fflush(stdin);
    gets(nam);
    while (strcmp(head->name, nam) != 0)
    {
        if (head->next == NULL)
        {
            printf("该生不存在！\n");
            return;
        }
        head = head->next;
    }
    printf("学号：%lld\n", head->num);
    printf("姓名：%s\n", head->name);
    printf("班级：%s\n", head->class);
    printf("语文成绩：%.2f\n", head->chinese_mark);
    printf("数学成绩：%.2f\n", head->math_mark);
    printf("英语成绩：%.2f\n", head->english_mark);
}
void Searchbyclass()
{
    if (flag == 0) //判断是否已录入数据
    {
        printf("暂未录入数据！");
        return;
    }
    char clas[10];
    head = head_fixed;
    printf("请输入待查询学生班级：");
    fflush(stdin);
    gets(clas);
    while (strcmp(head->class, clas) != 0)
    {
        if (head->next == NULL)
        {
            printf("该生不存在！\n");
            return;
        }
        head = head->next;
    }
    printf("学号：%lld\n", head->num);
    printf("姓名：%s\n", head->name);
    printf("班级：%s\n", head->class);
    printf("语文成绩：%.2f\n", head->chinese_mark);
    printf("数学成绩：%.2f\n", head->math_mark);
    printf("英语成绩：%.2f\n", head->english_mark);
}
void Data_inquiry()
{
    system("cls");
    Data_inquiry_show();
    while (1)
    {
        int choice;
        printf("\n请输入操作对应的序号：");
        scanf("%d", &choice);
        if (choice == 1)
        {
            Searchbynum(); //按学号查询
        }
        if (choice == 2)
        {
            Searchbyname(); //按姓名查询
        }
        if (choice == 3)
        {
            Searchbyclass(); //按所在班级查询
        }
        if (choice == 0)
        {
            system("cls");
            return; //返回
        }
    }
}