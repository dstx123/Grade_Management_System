//����ѧ������
struct Student
{
    long long num;      //ѧ��
    char class[10];     //�༶
    char name[20];      //����
    float chinese_mark; //���ĳɼ�
    float math_mark;    //��ѧ�ɼ�
    float english_mark; //Ӣ��ɼ�
    float average;      //ƽ���ɼ�
    int ranking;        //����

    struct Student *next;
};
int sum = 0;                          //ѧ������
void data_input(struct Student *stud) //����ѧ����Ϣ
{
    printf("������ѧ�ţ�");
    scanf(" %lld", &stud->num);
    if (stud->num == 0) //����¼��
        return;
    printf("������༶��");
    fflush(stdin);
    gets(stud->class);
    printf("������������");
    fflush(stdin);
    gets(stud->name);
    printf("���������ĳɼ���");
    scanf(" %f", &stud->chinese_mark);
    printf("��������ѧ�ɼ���");
    scanf(" %f", &stud->math_mark);
    printf("������Ӣ��ɼ���");
    scanf(" %f", &stud->english_mark);
    sum++;
}

struct Student *head; //ͷָ��

int flag = 0; //�ж��Ƿ���¼������

//����ѧ������
struct Student *Create()
{
    sum = 0;
    printf("��ʾ��������ѧ��Ϊ0ʱ����¼�룡\n");
    struct Student *ps, *pend;
    ps = (struct Student *)malloc(70); //����70�ֽ��ڴ棬sizeof�ó��ṹ��ռ��64�ֽ�
    data_input(ps);
    head = NULL;
    pend = ps;
    while (ps->num != 0) //����ѭ������
    {
        if (head == NULL) //�ǵ�һ���ڵ�
            head = ps;
        else //���ǵ�һ���ڵ�
            pend->next = ps;
        pend = ps;                         //Ϊ�����ڵ�ҽӷ���
        ps = (struct Student *)malloc(70); //�����ڶ����ڵ��ڶ����Ժ�ڵ�
        data_input(ps);
    }
    pend->next = NULL; //��β
    free(ps);
    printf("¼��ɹ���");
    flag = 1;
    return (head);
}

struct Student *head_fixed; //��¼ͷָ��

void csv_create() //����csv�ļ������ӻ�ģ��ʹ��
{
    FILE *fp;
    fp = fopen(".\\student_score.csv", "w");

    head = head_fixed;
    fprintf(fp, "ѧ��,����,�༶,����,��ѧ,Ӣ��\n");
    while (head != NULL)
    {
        fprintf(fp, "%lld,%s,%s,%.2f,%.2f,%.2f\n", head->num, head->name, head->class, head->chinese_mark, head->math_mark, head->english_mark);
        head = head->next;
    }
    fclose(fp);
}

//¼��ѧ������
void Data_keyin()
{
    head_fixed = Create(); //����ѧ�����������Ϣ����
    csv_create();          //����csv�ļ�
}
//ɾ��ѧ������
void Data_delete(long long number)
{
    struct Student *temp = head_fixed;
    int p = 1, p1 = 1;
    head = head_fixed;
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("����¼�����ݣ�");
        return;
    }
    while (head->num != number)
    {
        p1 = 0;
        if (head->next == NULL)
        {
            printf("��ѧ�������ڣ�");
            p = 0;
            break;
        }
        temp = head;
        head = head->next;
    }
    if (p1 == 1) //����Ͽ�����ķ�ʽɾ���޷�ɾ����һ��������
    {            //ɾ����һ������
        head_fixed = head_fixed->next;
        sum--;
        printf("ɾ���ɹ���\n");
        csv_create(); //����csv�ļ�
        return;
    }
    if (p == 1) //ɾ����������
    {
        temp->next = head->next;
        printf("ɾ���ɹ���\n");
        sum--;
        csv_create(); //����csv�ļ�
    }
}
//���ѧ������
void Data_add(long long number)
{
    struct Student *insert = head_fixed;
    head = head_fixed;
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("����¼�����ݣ�");
        return;
    }
    if (number == 0) //ѧ��Ϊ0ʱ������һ��
        return;
    while (head->num != number) //�ҵ���Ӧѧ��
    {
        if (head->next == NULL)
            break;
        head = head->next;
    }

    insert = (struct Student *)malloc(70);
    data_input(insert);
    if (insert->num == 0)
        return;
    insert->next = head->next;
    head->next = insert;
    printf("��ӳɹ���");
    csv_create(); //����csv�ļ�
}
//�޸�ѧ������
void Data_change(long long number)
{
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("����¼�����ݣ�");
        return;
    }
    if (number == 0)
        return;
    head = head_fixed;
    while (head->num != number)
    {
        if (head->next == NULL)
        {
            printf("����������");
            return;
        }
        head = head->next;
    }
    data_input(head);
    sum--; //�޸Ĳ�������ѧ����
    printf("�޸ĳɹ�");
    csv_create(); //����csv�ļ�
}
//��ȡѧ������
void Data_read()
{
    if (flag == 0) //�ж��Ƿ���¼������
    {
        printf("����¼�����ݣ�");
        return;
    }
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n", "ѧ��", "����", "�༶", "���ĳɼ�", "��ѧ�ɼ�", "Ӣ��ɼ�");
    head = head_fixed;
    while (head != NULL)
    {
        printf("%-10lld%-10s%-10s%-10.2f%-10.2f%-10.2f\n", head->num, head->name, head->class, head->chinese_mark, head->math_mark, head->english_mark);
        head = head->next;
    }
    printf("��%d��ѧ��\n", sum);
}