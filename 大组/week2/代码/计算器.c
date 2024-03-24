
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define size 10

typedef struct stacknode//����һ�������ַ����͵�ջ
{
    char* top;
    char* base;
    int stacksize;
} stacknode, * stacklink;

typedef struct shuzinode//����һ�������������͵�ջ
{
    int* top;
    int* base;
    int stacksize;
} shuzinode, * shulink;

void initstack(stacklink l)//���ַ����͵�ջ��ʼ��
{
    l->base = (char*)malloc(MAXSIZE * sizeof(char));
    if (!(l->base)) return ERROR;
    l->top = l->base;
    l->stacksize = MAXSIZE;
}

void initstacks(shulink l)//���������͵�ջ��ʼ��
{
    l->base = (int*)malloc(MAXSIZE * sizeof(int));
    if (!(l->base)) return ERROR; 
    l->top = l->base;
    l->stacksize = MAXSIZE;
}

void push(stacklink l, char e)//���ַ����͵�ջ������ջ����
{
    if (l->top - l->base == l->stacksize)
    {
        l->base = (char*)realloc(l->base, (MAXSIZE + size) * sizeof(char));
        if (!(l->base)) return ERROR;
        l->top = l->base + l->stacksize;
        l->stacksize = MAXSIZE + size;
    }
    *(l->top) = e;
    l->top++;
}

void pushs(shulink l, int e)//���������͵�ջ������ջ
{
    if (l->top - l->base == l->stacksize)
    {
        l->base = (int*)realloc(l->base, (MAXSIZE + size) * sizeof(int));
        if (!(l->base)) return ERROR;
        l->top = l->base + l->stacksize;
        l->stacksize = MAXSIZE + size;
    }
    *(l->top) = e;
    l->top++;
}

void pop(stacklink l, char* e)//�ַ����ͳ�ջ
{
    if (l->base == l->top)
    {
        return ERROR;
    }
    *e = *--(l->top);
}

void fpop(shulink l, int* e)//�������͵�ջ��ջ
{
    if (l->base == l->top)
    {
        return ERROR;
    }
    *e = *--(l->top);
}

int stacklen(stacklink l)//���㳤�ȿ�ջ�Ƿ�Ϊ��ջ
{
    if (l->top - l->base)return 1;
    else return 0;
}

void tohouzui(char* s, stacklink stuff)//��ǰ׺���ʽת��Ϊ��׺���ʽ
{
    stacklink string;//stringΪ������ŵ�ջ
    string = (stacklink)malloc(sizeof(stacknode));
    initstack(string);

    char e;
    while (*s != '\0')
    {
        if ('0' <= *s && *s <= '9')//����ֱ��ѹ��Ŀ��ջ
        {
            push(stuff, *s);
            s++;
        }
        else if (*s == '(')//������ֱ��ѹ��Ŀ��ջ
        {
            push(stuff, *s);
            s++;
        }
        else if (*s == '+' || *s == '/' || *s == '*' || *s == '-')//����������
        {
            if (string->top == string->base || *(string->top - 1) == '(')//ջ��Ϊ�����Ż�ջ��ֱ�Ӳ���Ŀ��ջ
            {
                push(string, *s);
                s++;
            }
            else if ((*s == '*' && *(string->top - 1) == '+') || (*s == '*' && *(string->top - 1) == '-') || (*s == '/' && *(string->top - 1) == '+') || (*s == '/' && *(string->top - 1) == '-'))//���ȼ��ϸ�Ҳ��ֱ�Ӳ���Ŀ��ջ
            {
                push(string, *s);
                s++;
            }
            else//ͬ�������ջ�������ظ�
            {
                pop(string, &e);
                push(stuff, e);
            }
        }
        else if (*s == ')')//��Ϊ��������һֱ��string����ֱ��ƥ�䵽������
        {
            while (*(string->top - 1) != '(')
            {
                pop(string, &e);
                push(stuff, e);
            }
            pop(string, &e);
        }
    }
    while (string->top > string->base)//��ʣ�µķ�������
    {
        pop(string, &e);
        push(stuff, e);
    }
}

int main()
{//��ʼ����ch���ڴ������֣�stuff���ڴ���ת������沨�����ʽ
    int result;
    shulink ch;
    stacklink  stuff;
    ch = (shulink)malloc(sizeof(shuzinode));
    stuff = (stacklink)malloc(sizeof(stacknode));
    initstack(stuff);
    initstacks(ch);

    char s[1000];
    printf("������Ҫ����ı��ʽ��");
    scanf("%s", s);
    tohouzui(s, stuff);//��sת��Ϊ�沨�����ʽ������stuff

    while (stacklen(stuff))
    {
        char a;
        int num1 = 0, num2 = 0;
        pop(stuff, &a);
        if (a >= '0' && a <= '9')//��������ֱ������stuff
        {
            pushs(ch, a - '0');
        }
        else//���ַ�����Զ�stuff��������������ֽ��м����ڲ���
        {
            switch (a)
            {
            case '+':
                fpop(ch, &num1);
                fpop(ch, &num2);
                pushs(ch, num2 + num1);
                break;
            case '-':
                fpop(ch, &num1);
                fpop(ch, &num2);
                pushs(ch, num2 - num1);
                break;
            case '*':
                fpop(ch, &num1);
                fpop(ch, &num2);
                pushs(ch, num2 * num1);
                break;
            case '/':
                fpop(ch, &num1);
                fpop(ch, &num2);
                if (num1 == 0) {
                    printf("��������Ϊ0��");
                    return 0;
                }
                else {
                    pushs(ch, num2 / num1);
                    break;
                }
            }
        }
    }

    result = *(ch->top - 1);//���������
    printf("���Ϊ: %d\n", result);

    return 0;
}
