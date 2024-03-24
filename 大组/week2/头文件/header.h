#ifndef __HEADER_H__
#define __HEADER_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// 定义链栈的节点结构体
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 定义链栈结构体
typedef struct {
    Node* top;
} Stack;

void initStack(Stack* stack);
void push(Stack* stack, char data);
char pop(Stack* stack);
char peek(Stack* stack);
bool isEmpty(Stack* stack);
int precedence(char op);
int evaluateExpression(const char* expression);

#endif