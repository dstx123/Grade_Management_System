#include "Data_management_operator.h"

void Data_management_show()
{
    printf("  *************************************\n");
    printf("  *          ѧ�����Ϲ���             *\n");
    printf("  *                                   *\n");
    printf("  *         1.¼��ѧ������            *\n");
    printf("  *         2.ɾ��ѧ������            *\n");
    printf("  *         3.���ѧ������            *\n");
    printf("  *         4.�޸�ѧ������            *\n");
    printf("  *         5.��ȡѧ������            *\n");
    printf("  *         0.����                    *\n");
    printf("  *                                   *\n");
    printf("  *         ��Enter����               *\n");
    printf("  *************************************");
}


void Data_management()
{
    system("cls");          //����
    Data_management_show(); //ѧ�����Ϲ��������ʾ
    while (1)               //���س�������
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
            Data_keyin(); //¼��ѧ������

        else if (choice == 2)
        {
            long long number;
            printf("������Ҫɾ����ѧ��ѧ�ţ�");
            scanf(" %lld", &number);
            Data_delete(number); //ɾ��ѧ������
        }

        else if (choice == 3)
        {
            long long number;
            printf("����Ҫ�������λѧ��֮�󣿣����޸������Զ���������\n");
            printf("������ѧ��0ʱ������һ����\n");
            printf("�����������ѧ�ţ�");
            scanf(" %lld", &number);
            Data_add(number); //���ѧ������
        }

        else if (choice == 4)
        {
            long long number;
            printf("������ѧ��0ʱ������һ����\n");
            printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
            scanf(" %lld", &number);
            Data_change(number); //�޸�ѧ������
        }

        else if (choice == 5)
            Data_read(); //��ȡѧ������

        else if (choice == 0) //����
        {
            system("cls");
            return;
        }

        else
            printf("��������ȷ�����!");
    }
}