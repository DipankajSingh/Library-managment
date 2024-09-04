#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *ptr;
} Node;

typedef struct LinkedList
{
    Node *headNode;
    Node *lastNode;
    int size;
} LinkedList;

void printValue(LinkedList *list)
{
    Node *node = list->headNode;

    do
    {
        printf("%d ", node->value);
        node = node->ptr;
    } while (node != NULL);
}

void appendAtStart(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->ptr = list->headNode;

    list->headNode = newNode;
    list->size++;
}

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

void insertAtIndex(LinkedList *list, int index, int value)
{

    if (index < 0 || index > list->size)
    {
        printf("\nInvalid index!\n");
        return;
    }

    if (index == 0)
    {
        appendAtStart(list, value);
        return;
    }

    if (index == list->size)
    {
        appendElementAtEnd(list, value);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    Node *node = list->headNode;

    for (int i = 0; i < index - 1; i++)
    {
        node = node->ptr;
    }

    newNode->ptr = node->ptr;
    node->ptr = newNode;
    list->size++;
}

LinkedList createList(int initialValue)
{
    LinkedList list;
    list.headNode = NULL;
    list.lastNode = NULL;
    list.size = 0;

    appendElementAtEnd(&list, initialValue);

    return list;
}

int main()
{

    LinkedList list = createList(25);

    appendAtStart(&list, 20);
    appendElementAtEnd(&list, 30);
    appendElementAtEnd(&list, 305);
    appendAtStart(&list, 555);
    insertAtIndex(&list, 0, 255);
    printValue(&list);

    return 0;
}