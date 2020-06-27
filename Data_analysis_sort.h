void sort_menu_show()
{
    printf("********************************************************");
    printf("\n*                 数据排序                             *\n");
    printf("*                                                      *\n");
    printf("*               1.按照学号                             *\n");
    printf("*               2.按照语文成绩                         *\n");
    printf("*               3.按照数学成绩                         *\n");
    printf("*               4.按照英语成绩                         *\n");
    printf("*               5.按照平均成绩                         *\n");
    printf("*               0.返回                                 *\n");
    printf("*                                                      *\n");
    printf("*               按Enter继续                            *\n");
    printf("*******************************************************");
}

void SortByNum()
{
    flag_s = 0; //head_sort在此函数中将被改变
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //平均值最小的
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->num) > (head->num)) //沉底排序
            {                                //只交换链表中的数据不改变链表结构
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
}

void SortByChinese()
{
    flag_s = 0; //head_sort在此函数中将被改变
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //平均值最小的
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->chinese_mark) > (head->chinese_mark)) //沉底排序
            {                                                  //只交换链表中的数据不改变链表结构
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
}

void SortByMath()
{
    flag_s = 0; //head_sort在此函数中将被改变
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //平均值最小的
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->math_mark) > (head->math_mark)) //沉底排序
            {                                            //只交换链表中的数据不改变链表结构
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
}

void SortByEnglish()
{
    flag_s = 0; //head_sort在此函数中将被改变
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //平均值最小的
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->english_mark) > (head->english_mark)) //沉底排序
            {                                                  //只交换链表中的数据不改变链表结构
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
}

void SortByAverage()
{
    flag_s = 0; //head_sort在此函数中将被改变
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //平均值最小的
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->average) > (head->average)) //沉底排序
            {                                        //只交换链表中的数据不改变链表结构
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
}

void sort_menu()
{
    system("cls");
    sort_menu_show();
    while (1) //按回车键继续
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
        {
            SortByNum();        //按照学号
            mark_sort_output(); //输出
        }
        if (choice == 2)
        {
            SortByChinese();    //按照语文成绩
            mark_sort_output(); //输出
        }
        if (choice == 3)
        {
            SortByMath();       //按照数学成绩
            mark_sort_output(); //输出
        }
        if (choice == 4)
        {
            SortByEnglish();    //按照英语成绩
            mark_sort_output(); //输出
        }
        if (choice == 5)
        {
            SortByAverage();    //按照平均成绩
            mark_sort_output(); //输出
        }
        if (choice == 0)
        {
            system("cls");
            Data_analysis_show();
            return; //返回
        }
    }
}