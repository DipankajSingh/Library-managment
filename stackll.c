#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char value;
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
    node->ptr = NULL;
    node->value = value;
    return node;
}

StackLL createStack(int max_size)
{
    StackLL stk;
    stk.max_size = 4000;
    stk.size = 0;
    return stk;
}

int push(StackLL *stk, char value)
{

    if (stk->size >= stk->max_size)
    {
        printf("Push: Stack Overflow!!\n");
        return 0;
    }
    Node *newNode = createNode(value);

    if (stk->size <= 0)
    {
        stk->top = newNode;
    }
    else
    {
        newNode->ptr = stk->top;
        stk->top = newNode;
    }
    stk->size++;
    return 1;
}

int pop(StackLL *stk)
{

    if (stk->size <= 0)
    {
        printf("Pop: Stack is Empty!!\n");
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
        printf("Peek: Stack is Empty!!\n");
        return;
    }

    Node *ptr = stk->top;
    do
    {
        printf("%c ", ptr->value);
        ptr = ptr->ptr;
    } while (ptr != NULL);

    printf("\n");
}

// -1: Error, 0: Parentheses Balanced, >0: Parentheses Are Not Balanced

int main()
{
    StackLL stk = createStack(400);

    char exp[] = ")())(()";

    return 0;
}