#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *ptr;
} Node;

void printValue(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->ptr;
    }
}

typedef struct LinkedList
{
    Node *headNode;
    Node *lastNode;
    int size;
    void (*appendElementAtEnd)(struct LinkedList *, int);

} LinkedList;

void appendElementAtEnd(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->ptr = NULL;

    if (list->headNode == NULL) // If the list is empty
    {
        list->headNode = newNode;
        list->lastNode = newNode;
    }
    else
    {
        list->lastNode->ptr = newNode;
        list->lastNode = newNode;
    }
    list->size++;
}

LinkedList createList(int initialValue)
{
    LinkedList list;
    list.headNode = NULL;
    list.lastNode = NULL;
    list.size = 0;
    list.appendElementAtEnd = appendElementAtEnd;

    list.appendElementAtEnd(&list, initialValue); // Add the initial element to the list

    return list;
}

int main()
{

    LinkedList list = createList(25);
    list.appendElementAtEnd(&list, 20);
    // printf("%d ", (headNode->value));

    printValue(list.headNode);

    return 0;
}