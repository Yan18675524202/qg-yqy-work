

#include"header.h"

// 初始化栈
void initStack(Stack* stack) {
    stack->top = NULL;
}

// 入栈
void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈
char pop(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    char data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// 获取栈顶元素
char peek(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// 判断栈是否为空
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 操作符优先级比较
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 计算表达式
int evaluateExpression(const char* expression) {
    Stack operandStack;
    initStack(&operandStack);

    Stack operatorStack;
    initStack(&operatorStack);

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isspace(expression[i])) {
            continue;
        } else if (isdigit(expression[i])) {
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i;
            push(&operandStack, operand);
        } else if (expression[i] == '(') {
            push(&operatorStack, expression[i]);
        } else if (expression[i] == ')') {
            while (peek(&operatorStack) != '(') {
                char op = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                switch (op) {
                    case '+':
                        push(&operandStack, operand1 + operand2);
                        break;
                    case '-':
                        push(&operandStack, operand1 - operand2);
                        break;
                    case '*':
                        push(&operandStack, operand1 * operand2);
                        break;
                    case '/':
                        push(&operandStack, operand1 / operand2);
                        break;
                    default:
                        fprintf(stderr, "Invalid operator.\n");
                        exit(EXIT_FAILURE);
                }
            }
            pop(&operatorStack); // 弹出'('
        } else if (expression[i] == '+' || expression[i] == '-' || 
                   expression[i] == '*' || expression[i] == '/') {
            while (!isEmpty(&operatorStack) && precedence(peek(&operatorStack)) >= precedence(expression[i])) {
                char op = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                switch (op) {
                    case '+':
                        push(&operandStack, operand1 + operand2);
                        break;
                    case '-':
                        push(&operandStack, operand1 - operand2);
                        break;
                    case '*':
                        push(&operandStack, operand1 * operand2);
                        break;
                    case '/':
                        push(&operandStack, operand1 / operand2);
                        break;
                    default:
                        fprintf(stderr, "Invalid operator.\n");
                        exit(EXIT_FAILURE);
                }
            }
            push(&operatorStack, expression[i]);
        } else {
            fprintf(stderr, "Invalid character in expression.\n");
            exit(EXIT_FAILURE);
        }
    }

    while (!isEmpty(&operatorStack)) {
        char op = pop(&operatorStack);
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        switch (op) {
            case '+':
                push(&operandStack, operand1 + operand2);
                break;
            case '-':
                push(&operandStack, operand1 - operand2);
                break;
            case '*':
                push(&operandStack, operand1 * operand2);
                break;
            case '/':
                push(&operandStack, operand1 / operand2);
                break;
            default:
                fprintf(stderr, "Invalid operator.\n");
                exit(EXIT_FAILURE);
        }
    }

    return pop(&operandStack);
}


int main() {
	
    char expression[100];
    printf("please input :");
    scanf("%s",&expression);
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
