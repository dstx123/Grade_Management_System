void sort_menu_show()
{
    printf("********************************************************");
    printf("\n*                 ��������                             *\n");
    printf("*                                                      *\n");
    printf("*               1.����ѧ��                             *\n");
    printf("*               2.�������ĳɼ�                         *\n");
    printf("*               3.������ѧ�ɼ�                         *\n");
    printf("*               4.����Ӣ��ɼ�                         *\n");
    printf("*               5.����ƽ���ɼ�                         *\n");
    printf("*               0.����                                 *\n");
    printf("*                                                      *\n");
    printf("*               ��Enter����                            *\n");
    printf("*******************************************************");
}

void SortByNum()
{
    flag_s = 0; //head_sort�ڴ˺����н����ı�
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //ƽ��ֵ��С��
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->num) > (head->num)) //��������
            {                                //ֻ���������е����ݲ��ı�����ṹ
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
    flag_s = 0; //head_sort�ڴ˺����н����ı�
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //ƽ��ֵ��С��
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->chinese_mark) > (head->chinese_mark)) //��������
            {                                                  //ֻ���������е����ݲ��ı�����ṹ
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
    flag_s = 0; //head_sort�ڴ˺����н����ı�
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //ƽ��ֵ��С��
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->math_mark) > (head->math_mark)) //��������
            {                                            //ֻ���������е����ݲ��ı�����ṹ
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
    flag_s = 0; //head_sort�ڴ˺����н����ı�
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //ƽ��ֵ��С��
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->english_mark) > (head->english_mark)) //��������
            {                                                  //ֻ���������е����ݲ��ı�����ṹ
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
    flag_s = 0; //head_sort�ڴ˺����н����ı�
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //ƽ��ֵ��С��
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->average) > (head->average)) //��������
            {                                        //ֻ���������е����ݲ��ı�����ṹ
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
    while (1) //���س�������
    {
        if (getch() == 13)
            break;
    }
    while (1)
    {
        int choice;
        printf("\n�����������Ӧ����ţ�");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            SortByNum();        //����ѧ��
            mark_sort_output(); //���
        }
        if (choice == 2)
        {
            SortByChinese();    //�������ĳɼ�
            mark_sort_output(); //���
        }
        if (choice == 3)
        {
            SortByMath();       //������ѧ�ɼ�
            mark_sort_output(); //���
        }
        if (choice == 4)
        {
            SortByEnglish();    //����Ӣ��ɼ�
            mark_sort_output(); //���
        }
        if (choice == 5)
        {
            SortByAverage();    //����ƽ���ɼ�
            mark_sort_output(); //���
        }
        if (choice == 0)
        {
            system("cls");
            Data_analysis_show();
            return; //����
        }
    }
}