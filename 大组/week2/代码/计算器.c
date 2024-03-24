
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define size 10

typedef struct stacknode//定义一个储存字符类型的栈
{
    char* top;
    char* base;
    int stacksize;
} stacknode, * stacklink;

typedef struct shuzinode//定义一个储存数字类型的栈
{
    int* top;
    int* base;
    int stacksize;
} shuzinode, * shulink;

void initstack(stacklink l)//对字符类型的栈初始化
{
    l->base = (char*)malloc(MAXSIZE * sizeof(char));
    if (!(l->base)) return ERROR;
    l->top = l->base;
    l->stacksize = MAXSIZE;
}

void initstacks(shulink l)//对数字类型的栈初始化
{
    l->base = (int*)malloc(MAXSIZE * sizeof(int));
    if (!(l->base)) return ERROR; 
    l->top = l->base;
    l->stacksize = MAXSIZE;
}

void push(stacklink l, char e)//对字符类型的栈进行入栈操作
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

void pushs(shulink l, int e)//对整型类型的栈进行入栈
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

void pop(stacklink l, char* e)//字符类型出栈
{
    if (l->base == l->top)
    {
        return ERROR;
    }
    *e = *--(l->top);
}

void fpop(shulink l, int* e)//整数类型的栈出栈
{
    if (l->base == l->top)
    {
        return ERROR;
    }
    *e = *--(l->top);
}

int stacklen(stacklink l)//计算长度看栈是否为空栈
{
    if (l->top - l->base)return 1;
    else return 0;
}

void tohouzui(char* s, stacklink stuff)//将前缀表达式转化为后缀表达式
{
    stacklink string;//string为储存符号的栈
    string = (stacklink)malloc(sizeof(stacknode));
    initstack(string);

    char e;
    while (*s != '\0')
    {
        if ('0' <= *s && *s <= '9')//数字直接压入目标栈
        {
            push(stuff, *s);
            s++;
        }
        else if (*s == '(')//左括号直接压入目标栈
        {
            push(stuff, *s);
            s++;
        }
        else if (*s == '+' || *s == '/' || *s == '*' || *s == '-')//计算符看情况
        {
            if (string->top == string->base || *(string->top - 1) == '(')//栈顶为左括号或栈空直接插入目标栈
            {
                push(string, *s);
                s++;
            }
            else if ((*s == '*' && *(string->top - 1) == '+') || (*s == '*' && *(string->top - 1) == '-') || (*s == '/' && *(string->top - 1) == '+') || (*s == '/' && *(string->top - 1) == '-'))//优先级较高也是直接插入目标栈
            {
                push(string, *s);
                s++;
            }
            else//同级则输出栈顶，并重复
            {
                pop(string, &e);
                push(stuff, e);
            }
        }
        else if (*s == ')')//若为右括号则一直将string输入直到匹配到左括号
        {
            while (*(string->top - 1) != '(')
            {
                pop(string, &e);
                push(stuff, e);
            }
            pop(string, &e);
        }
    }
    while (string->top > string->base)//将剩下的符号输入
    {
        pop(string, &e);
        push(stuff, e);
    }
}

int main()
{//初始化，ch用于储存数字，stuff用于储存转化后的逆波兰表达式
    int result;
    shulink ch;
    stacklink  stuff;
    ch = (shulink)malloc(sizeof(shuzinode));
    stuff = (stacklink)malloc(sizeof(stacknode));
    initstack(stuff);
    initstacks(ch);

    char s[1000];
    printf("请输入要计算的表达式：");
    scanf("%s", s);
    tohouzui(s, stuff);//将s转化为逆波兰表达式并存入stuff

    while (stacklen(stuff))
    {
        char a;
        int num1 = 0, num2 = 0;
        pop(stuff, &a);
        if (a >= '0' && a <= '9')//是数字则直接输入stuff
        {
            pushs(ch, a - '0');
        }
        else//是字符则可以对stuff最上面的两个数字进行计算在插入
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
                    printf("除数不能为0！");
                    return 0;
                }
                else {
                    pushs(ch, num2 / num1);
                    break;
                }
            }
        }
    }

    result = *(ch->top - 1);//最后输出结果
    printf("结果为: %d\n", result);

    return 0;
}
