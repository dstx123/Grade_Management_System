#include <string.h>
void Data_inquiry_show()
{
    printf("********************************************************");
    printf("\n*                 ѧ����ѯ����                         *\n");
    printf("*                                                      *\n");
    printf("*               1.��ѧ�Ų�ѯ                           *\n");
    printf("*               2.��������ѯ                           *\n");
    printf("*               3.�����ڰ༶��ѯ                       *\n");
    printf("*               0.����                                 *\n");
    printf("*                                                      *\n");
    printf("*               ��Enter����                            *\n");
    printf("*******************************************************");
    while (1) //���س�������
    {
        if (getch() == 13)
            break;
    }
}
void Searchbynum()
{
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("��δ¼�����ݣ�");
        return;
    }
    long long number = 0;
    head = head_fixed;
    printf("���������ѯѧ��ѧ�ţ�");
    scanf("%lld", &number);
    while (head->num != number)
    {
        if (head->next == NULL)
        {
            printf("���������ڣ�\n");
            return;
        }
        head = head->next;
    }
    printf("ѧ�ţ�%lld\n", head->num);
    printf("������%s\n", head->name);
    printf("�༶��%s\n", head->class);
    printf("���ĳɼ���%.2f\n", head->chinese_mark);
    printf("��ѧ�ɼ���%.2f\n", head->math_mark);
    printf("Ӣ��ɼ���%.2f\n", head->english_mark);
}
void Searchbyname()
{
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("��δ¼�����ݣ�");
        return;
    }
    char nam[20];
    head = head_fixed;
    printf("���������ѯѧ��������");
    fflush(stdin);
    gets(nam);
    while (strcmp(head->name, nam) != 0)
    {
        if (head->next == NULL)
        {
            printf("���������ڣ�\n");
            return;
        }
        head = head->next;
    }
    printf("ѧ�ţ�%lld\n", head->num);
    printf("������%s\n", head->name);
    printf("�༶��%s\n", head->class);
    printf("���ĳɼ���%.2f\n", head->chinese_mark);
    printf("��ѧ�ɼ���%.2f\n", head->math_mark);
    printf("Ӣ��ɼ���%.2f\n", head->english_mark);
}
void Searchbyclass()
{
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("��δ¼�����ݣ�");
        return;
    }
    char clas[10];
    head = head_fixed;
    printf("���������ѯѧ���༶��");
    fflush(stdin);
    gets(clas);
    while (strcmp(head->class, clas) != 0)
    {
        if (head->next == NULL)
        {
            printf("���������ڣ�\n");
            return;
        }
        head = head->next;
    }
    printf("ѧ�ţ�%lld\n", head->num);
    printf("������%s\n", head->name);
    printf("�༶��%s\n", head->class);
    printf("���ĳɼ���%.2f\n", head->chinese_mark);
    printf("��ѧ�ɼ���%.2f\n", head->math_mark);
    printf("Ӣ��ɼ���%.2f\n", head->english_mark);
}
void Data_inquiry()
{
    system("cls");
    Data_inquiry_show();
    while (1)
    {
        int choice;
        printf("\n�����������Ӧ����ţ�");
        scanf("%d", &choice);
        if (choice == 1)
        {
            Searchbynum(); //��ѧ�Ų�ѯ
        }
        if (choice == 2)
        {
            Searchbyname(); //��������ѯ
        }
        if (choice == 3)
        {
            Searchbyclass(); //�����ڰ༶��ѯ
        }
        if (choice == 0)
        {
            system("cls");
            return; //����
        }
    }
}