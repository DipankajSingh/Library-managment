#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int *arrPtr;
    int maxSize;
    int itemCount;
} Stack;

Stack createStack(int stackSize)
{
    Stack stk;
    stk.maxSize = stackSize;
    stk.arrPtr = (int *)malloc(stk.maxSize * sizeof(int));
    stk.top = -1;
    stk.itemCount = 0;
    return stk;
}

int pushToStack(Stack *stk, int value)
{
    if (stk->itemCount < stk->maxSize)
    {
        stk->top++;
        stk->itemCount++;
        stk->arrPtr[stk->top] = value;
        return 1;
    }
    else
    {
        printf("\nStack Overflow!!\n");
        return 0;
    }
}

int popFromStack(Stack *stk)
{
    if (stk->itemCount <= 0)
    {
        printf("\nStack is Empty!\n");
        return 0;
    }
    int value;
    value = stk->arrPtr[stk->top];
    stk->itemCount--;
    stk->top--;
    return stk->arrPtr[stk->top];
}

void peekStack(Stack stk)
{
    if (stk.top <= -1)
    {
        printf("\nStack is empty!\n");
        return;
    }
    for (int i = stk.top; i >= 0; i--)
    {
        printf("%d ", stk.arrPtr[i]);
    }
    printf("\n");
}

int main()
{

    Stack stack = createStack(10);

    pushToStack(&stack, 52);
    pushToStack(&stack, 55);
    pushToStack(&stack, 5256);
    pushToStack(&stack, 5582);
    pushToStack(&stack, 5288);

    peekStack(stack);
    popFromStack(&stack);
    peekStack(stack);

    return 0;
}