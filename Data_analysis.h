void Data_analysis_show()
{
    printf("********************************************************");
    printf("\n*                 ѧ���ɼ�ͳ�ƹ���                     *\n");
    printf("*                                                      *\n");
    printf("*               1.�ɼ�ƽ��ֵ                           *\n");
    printf("*               2.��������                             *\n");
    printf("*               3.ѧ��ƽ���ɼ��ֲ�ͼ                   *\n");
    printf("*               0.����                                 *\n");
    printf("*                                                      *\n");
    printf("*               ��Enter����                            *\n");
    printf("*******************************************************");
}

#include <string.h>

void exchange(struct Student *p1, struct Student *p2) //�������������ڵ�����ݲ���
{
    //��ʱ����
    long long stud_num;      //ѧ��
    char stud_class[10];     //�༶
    char stud_name[20];      //����
    float stud_chinese_mark; //���ĳɼ�
    float stud_math_mark;    //��ѧ�ɼ�
    float stud_english_mark; //Ӣ��ɼ�
    float stud_average;      //ƽ���ɼ�
    //��ʼ��������
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

struct Student *head_sort; //����ƽ��ֵ���������µ�����ͷָ��

int flag_s = 0; //��������ƽ��ֵ��Ϊ1,��head_sort���ı���Ϊ0

void mark_average() //���ƽ��ֵ������
{
    flag_s = 1;
    head = head_fixed;
    while (head != NULL) //��ƽ��ֵ
    {
        head->average = (head->chinese_mark + head->math_mark + head->english_mark) / 3.0;
        head = head->next;
    }
    //����
    head = head_fixed->next;
    struct Student *stud_min = head_fixed; //ƽ��ֵ��С��
    int i, j;
    for (i = 0; i < sum - 1; i++)
    {
        for (j = i + 1; j < sum; j++)
        {
            if ((stud_min->average) > (head->average)) //��������
            {                                          //ֻ���������е����ݲ��ı�����ṹ
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
    //�������
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
           "����", "ѧ��", "����", "�༶", "���ĳɼ�", "��ѧ�ɼ�", "Ӣ��ɼ�", "ƽ���ɼ�"); //���
    while (head != NULL)
    {
        printf("%-5d%-10lld%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f\n",
               head->ranking, head->num, head->name, head->class, head->chinese_mark, head->math_mark, head->english_mark, head->average);
        head = head->next;
    }

    printf("��%d��ѧ��\n", sum);
}

#include "Data_analysis_sort.h"

void Data_analysis()
{
    system("cls");
    Data_analysis_show();
    while (1) //���س�������
    {
        if (getch() == 13)
            break;
    }
    mark_average(); //���ƽ��ֵ������
    while (1)
    {
        int choice;
        printf("\n�����������Ӧ����ţ�");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            if (flag_s = 0) //head_sort�����������ı��
                mark_average();
            mark_sort_output(); //�鿴�ɼ�ƽ��ֵ
        }
        if (choice == 2)
        {
            sort_menu(); //��������
        }
        if (choice == 3)
        {
            printf("Python���м��仺���������ĵȴ���(̯��)\n");  //ʹ��ǰ�ڴ˴��޸��ļ�·������������
            system("Visualization\\students_scores_avg.exe"); //ѧ��ƽ���ɼ��ֲ�ͼ
        }
        if (choice == 0)
        {
            system("cls");
            return; //����
        }
    }
}