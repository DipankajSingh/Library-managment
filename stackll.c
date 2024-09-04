#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *ptr;
} Node;

typedef struct StackLL
{
    Node *top;
    int size;
    int max_size;
} StackLL;

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("\nHeap overflow!!\n");
        return;
    }
    node->value = value;
    node->ptr = NULL;
    return node;
}

StackLL createStack(int initialValue, int max_size)
{
    StackLL stk;
    stk.max_size = 4000;
    Node *n = createNode(initialValue);
    stk.top = n;
    stk.size++;
    return stk;
}

int push(StackLL *stk, int value)
{

    if (stk->size >= stk->max_size)
    {
        printf("Stack Overflow!!\n");
        return 0;
    }

    Node *newNode = createNode(value);
    newNode->ptr = stk->top;
    stk->top = newNode;
    stk->size++;
    return 1;
}

int pop(StackLL *stk)
{

    if (stk->size <= 0)
    {
        printf("Stack is Empty!!\n");
        return 0;
    }
    Node *node = stk->top;
    stk->top = stk->top->ptr;
    free(node);
    stk->size--;
    return 1;
}

void peek(StackLL *stk)
{
    if (stk->size <= 0)
    {
        printf("Stack is Empty!!\n");
        return 0;
    }

    Node *ptr = stk->top;
    do
    {
        printf("%d ", ptr->value);
        ptr = ptr->ptr;
    } while (ptr != NULL);

    printf("\n");
}

int main()
{
    StackLL stk = createStack(54, 400);
    push(&stk, 45);
    push(&stk, 45558);
    peek(&stk);
    pop(&stk);
    pop(&stk);
    pop(&stk);
    pop(&stk);
    peek(&stk);

    return 0;
}