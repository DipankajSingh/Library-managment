#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int front;
    int rear;
    int elementCount;
    int *arr;
    int size;
} CircularQueue;

CircularQueue *createCircular(int size)
{
    CircularQueue *cir = (CircularQueue *)malloc(sizeof(CircularQueue));
    cir->front = -1;
    cir->rear = -1;
    cir->size = size;
    cir->arr = (int *)malloc(size * sizeof(int));
    cir->elementCount = 0;
    return cir;
}

int isFull(CircularQueue *cir)
{
    return (cir->front == (cir->rear + 1) % cir->size);
}

int isEmpty(CircularQueue *cir)
{
    return cir->front == -1;
}

void enqueue(CircularQueue *cir, int value)
{
    if (isFull(cir))
    {
        printf("enqueue: queue full!\n");
        return;
    }

    if (isEmpty(cir))
    {
        cir->front = cir->rear = 0;
    }
    else
    {
        cir->rear = (cir->rear + 1) % cir->size;
    }

    cir->arr[cir->rear] = value;
    cir->elementCount++;
}

int dequeue(CircularQueue *cir)
{
    if (isEmpty(cir))
    {
        printf("dequeue: queue empty!\n");
        return -1;
    }

    int value = cir->arr[cir->front];

    if (cir->front == cir->rear) // Queue has only one element
    {
        cir->front = cir->rear = -1; // Reset the queue
    }
    else
    {
        cir->front = (cir->front + 1) % cir->size;
    }

    cir->elementCount--;
    return value;
}

void traversal(CircularQueue *cir)
{
    if (isEmpty(cir))
    {
        printf("traversal: queue empty!\n");
        return;
    }

    int i = cir->front;
    while (i != cir->rear)
    {
        printf("%d, ", cir->arr[i]);
        i = (i + 1) % cir->size;
    }
    printf("%d\n", cir->arr[i]); // Print the last element (rear)
}

int main()
{
    CircularQueue *cir = createCircular(10);

    enqueue(cir, 2);
    enqueue(cir, 5);
    enqueue(cir, 8);
    enqueue(cir, 10);

    traversal(cir);

    dequeue(cir);
    dequeue(cir);

    traversal(cir);

    enqueue(cir, 15);
    enqueue(cir, 20);

    traversal(cir);

    return 0;
}
