#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "Data_management_menu.h"
#include "Data_analysis.h"
#include "Data_inquiry.h"
#include "System_about.h"

void mainwindow_show() //���˵���ʾ����
{
    printf("********************************************************");
    printf("\n*                 �����˵�                             *\n");
    printf("*                                                      *\n");
    printf("*               1.ѧ�����Ϲ���                         *\n");
    printf("*               2.ѧ���ɼ�ͳ�ƹ���                     *\n");
    printf("*               3.ѧ����ѯ����                         *\n");
    printf("*               4.����ϵͳ                             *\n");
    printf("*               0.�˳�ϵͳ                             *\n");
    printf("*                                                      *\n");
    printf("*               ��Enter����                            *\n");
    printf("*******************************************************\n");
    printf("*                                                      *\n");
    printf("********************************************************");

    while (1) //���س�������
    {
        if (getch() == 13)
            break;
    }
}
void mainwindow_operator() //���˵�����ѡ��
{
    while (1)
    {
        int choice;
        printf("\n�����������Ӧ����ţ�");
        scanf("%d", &choice);
        if (choice == 1)
        {
            Data_management(); //ѧ�����Ϲ���
            break;
        }

        if (choice == 2)
        {
            if (flag == 0) //�ж��Ƿ���¼������
            {
                printf("��δ¼�����ݣ�\n");
                char ss;
                while (1)
                {
                    printf("�Ƿ񷵻���һ��(y/n)��");
                    scanf(" %c", &ss);
                    if (ss == 'y')
                    {
                        system("cls");
                        return;
                    }
                }
            }
            Data_analysis(); //ѧ���ɼ�ͳ�ƹ���
            break;
        }

        if (choice == 3)
        {
            Data_inquiry(); //ѧ����ѯ����
            break;
        }

        if (choice == 4)
        {
            System_about(); //����ϵͳ
            break;
        }

        if (choice == 0)
            exit(0); //�˳�ϵͳ

        else
            printf("��������ȷ�����!");
    }
}