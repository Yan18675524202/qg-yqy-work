#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>

// 定义队列的节点结构体
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

// 定义队列结构体
typedef struct {
    Node *front;
    Node *rear;
} Queue;

#endif