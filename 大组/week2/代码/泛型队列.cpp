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

// 初始化队列
void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 入队列
void enqueue(Queue *queue, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队列
void *dequeue(Queue *queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    Node *temp = queue->front;
    void *data = temp->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// 销毁队列
void destroyQueue(Queue *queue) {
  Node *current = queue->front;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    queue->front = NULL;
    queue->rear = NULL;
	

   
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}


void printQueue(Queue* queue, void (*printElement)(void*)) {
    if (isEmpty(queue)) {
        printf("队列为空。\n");
        return;
    }

    Node* tempNode = queue->front;
    printf(" :");

    while (tempNode != NULL) {
        printElement(tempNode->data);
        tempNode = tempNode->next;
    }

    printf("\n");
}

// 打印整数元素
void printInt(void* data) {
    int* num = (int*)data;
    printf("%d->", *num);
}

// 打印双精度浮点数元素
void printDouble(void* data) {
    double* num = (double*)data;
    printf("%f->", *num);
}
//打印字符元素
void printChar(void* data) {
    char* c = (char*)data;
    printf("%c->", *c);
}
void menu1(){
	
	printf("1.int\n");
	printf("2.double\n");
	printf("3.char\n");
	
}
void menu2(){
	
	printf("1.enqueue\n");
	printf("2.dequeue\n");
	printf("3.printQueue\n");
	printf("4.destroyQueue\n");
	printf("0.exit\n");
}



int main() {
	Queue intQueue, charQueue, doubleQueue;
    initQueue(&intQueue);
    initQueue(&charQueue);
    initQueue(&doubleQueue);
	

    int a = 3, b = 7, c = 13 , d = 23, e = 4;
    enqueue(&intQueue, &a);
    enqueue(&intQueue, &b);
    enqueue(&intQueue, &c);
    enqueue(&intQueue, &d);
    enqueue(&intQueue, &e);
    printQueue(&intQueue,printInt);

    char x = 'A', y = 'B', z = 'C';
    enqueue(&charQueue, &x);
    enqueue(&charQueue, &y);
    enqueue(&charQueue, &z);

    printQueue(&charQueue,printChar);
    
    double m = 1.23, n = 4.56, p = 7.89;
    enqueue(&doubleQueue, &m);
    enqueue(&doubleQueue, &n);
    enqueue(&doubleQueue, &p);
    
     printQueue(&doubleQueue,printDouble);


    destroyQueue(&intQueue);
    destroyQueue(&charQueue);
    destroyQueue(&doubleQueue);
    
    

    return 0;
}

