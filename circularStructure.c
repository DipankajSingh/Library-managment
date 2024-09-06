#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int elementCount;
} Queue;

Queue *createQueue()
{
    Queue *cir = (Queue *)malloc(sizeof(Queue));
    cir->front = NULL;
    cir->rear = NULL;
    cir->elementCount = 0;
    return cir;
}

int isEmpty(Queue *cir)
{
    return cir->front == NULL;
}

void enqueue(Queue *cir, int value)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    if (isEmpty(cir))
    {
        cir->front = n;
        cir->rear = n;
    }
    else
    {

        cir->rear->next = n;
        cir->rear = n;
    }
    cir->elementCount++;
}

int dequeue(Queue *cir)
{
    if (isEmpty(cir))
    {
        printf("\nDequeue: empty queue!\n");
        return 0;
    }
    int val = cir->front->value;
    if (cir->elementCount <= 1)
    {
        free(cir->front);
        cir->front = cir->rear = NULL;
        cir->elementCount = 0;
        return val;
    }

    Node *nxtElm = cir->front;
    cir->front = cir->front->next;
    free(nxtElm);
    printf("\nThe value that has been removed is %d \n", val);
    return val;
}

void traversal(Queue *cir)
{
    if (isEmpty(cir))
    {
        printf("\ntraversal: queue empty!\n");
        return;
    }
    Node *node = cir->front;
    do
    {
        printf("%d ", node->value);
        node = node->next;
    } while (node != NULL);
}

int main()
{
    Queue *cir = createQueue();

    enqueue(cir, 2);
    traversal(cir);
    dequeue(cir);
    dequeue(cir);
    dequeue(cir);
    traversal(cir);
    return 0;
}
