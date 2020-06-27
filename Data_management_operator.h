//建立学生链表
struct Student
{
    long long num;      //学号
    char class[10];     //班级
    char name[20];      //姓名
    float chinese_mark; //语文成绩
    float math_mark;    //数学成绩
    float english_mark; //英语成绩
    float average;      //平均成绩
    int ranking;        //排名

    struct Student *next;
};
int sum = 0;                          //学生总数
void data_input(struct Student *stud) //输入学生信息
{
    printf("请输入学号：");
    scanf(" %lld", &stud->num);
    if (stud->num == 0) //结束录入
        return;
    printf("请输入班级：");
    fflush(stdin);
    gets(stud->class);
    printf("请输入姓名：");
    fflush(stdin);
    gets(stud->name);
    printf("请输入语文成绩：");
    scanf(" %f", &stud->chinese_mark);
    printf("请输入数学成绩：");
    scanf(" %f", &stud->math_mark);
    printf("请输入英语成绩：");
    scanf(" %f", &stud->english_mark);
    sum++;
}

struct Student *head; //头指针

int flag = 0; //判断是否已录入数据

//创建学生链表
struct Student *Create()
{
    sum = 0;
    printf("提示：当输入学号为0时结束录入！\n");
    struct Student *ps, *pend;
    ps = (struct Student *)malloc(70); //分配70字节内存，sizeof得出结构体占用64字节
    data_input(ps);
    head = NULL;
    pend = ps;
    while (ps->num != 0) //链表循环创建
    {
        if (head == NULL) //是第一个节点
            head = ps;
        else //不是第一个节点
            pend->next = ps;
        pend = ps;                         //为后续节点挂接服务
        ps = (struct Student *)malloc(70); //创建第二个节点或第二个以后节点
        data_input(ps);
    }
    pend->next = NULL; //结尾
    free(ps);
    printf("录入成功！");
    flag = 1;
    return (head);
}

struct Student *head_fixed; //记录头指针

void csv_create() //创建csv文件供可视化模块使用
{
    FILE *fp;
    fp = fopen(".\\student_score.csv", "w");

    head = head_fixed;
    fprintf(fp, "学号,姓名,班级,语文,数学,英语\n");
    while (head != NULL)
    {
        fprintf(fp, "%lld,%s,%s,%.2f,%.2f,%.2f\n", head->num, head->name, head->class, head->chinese_mark, head->math_mark, head->english_mark);
        head = head->next;
    }
    fclose(fp);
}

//录入学生资料
void Data_keyin()
{
    head_fixed = Create(); //创建学生链表完成信息键入
    csv_create();          //创建csv文件
}
//删除学生资料
void Data_delete(long long number)
{
    struct Student *temp = head_fixed;
    int p = 1, p1 = 1;
    head = head_fixed;
    if (flag == 0) //判断是否已录入数据
    {
        printf("请先录入数据！");
        return;
    }
    while (head->num != number)
    {
        p1 = 0;
        if (head->next == NULL)
        {
            printf("该学生不存在！");
            p = 0;
            break;
        }
        temp = head;
        head = head->next;
    }
    if (p1 == 1) //上面断开链表的方式删除无法删除第一个的数据
    {            //删除第一个数据
        head_fixed = head_fixed->next;
        sum--;
        printf("删除成功！\n");
        csv_create(); //创建csv文件
        return;
    }
    if (p == 1) //删除其他数据
    {
        temp->next = head->next;
        printf("删除成功！\n");
        sum--;
        csv_create(); //创建csv文件
    }
}
//添加学生资料
void Data_add(long long number)
{
    struct Student *insert = head_fixed;
    head = head_fixed;
    if (flag == 0) //判断是否已录入数据
    {
        printf("请先录入数据！");
        return;
    }
    if (number == 0) //学号为0时返回上一级
        return;
    while (head->num != number) //找到对应学号
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
    printf("添加成功！");
    csv_create(); //创建csv文件
}
//修改学生资料
void Data_change(long long number)
{
    if (flag == 0) //判断是否已录入数据
    {
        printf("请先录入数据！");
        return;
    }
    if (number == 0)
        return;
    head = head_fixed;
    while (head->num != number)
    {
        if (head->next == NULL)
        {
            printf("该生不存在");
            return;
        }
        head = head->next;
    }
    data_input(head);
    sum--; //修改不增加总学生数
    printf("修改成功");
    csv_create(); //创建csv文件
}
//读取学生资料
void Data_read()
{
    if (flag == 0) //判断是否已录入数据
    {
        printf("请先录入数据！");
        return;
    }
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n", "学号", "姓名", "班级", "语文成绩", "数学成绩", "英语成绩");
    head = head_fixed;
    while (head != NULL)
    {
        printf("%-10lld%-10s%-10s%-10.2f%-10.2f%-10.2f\n", head->num, head->name, head->class, head->chinese_mark, head->math_mark, head->english_mark);
        head = head->next;
    }
    printf("共%d名学生\n", sum);
}