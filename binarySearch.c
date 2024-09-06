#include <stdio.h>

#define MAX_SIZE 10

void updatePointerValue(int *s, int updateBy)
{
    *(s) = *(s) + updateBy;
}

int findElement(int val, int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int deleteElement(int arr[], int *size, int position)
{

    if (position < 0 || position >= *size)
    {
        printf("Out Of Bound!\n");
        return -1;
    }
    for (int i = position; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }
    updatePointerValue(size, -1);
    return 1;
}

int insertAtIndex(int arr[], int *size, int position, int value)
{

    if (*(size) == MAX_SIZE)
    {
        return -1;
    }

    for (int i = *size; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    updatePointerValue(size, 1);

    return 1;
}

int binarySearch(int arr[], int *size, int value)
{
    int low = 0, high = *size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        printf("loop\n");
        if (value == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int initialSize = 7;
    int *size = &initialSize;

    int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7};

    // insertAtIndex(arr, size, 4, 45);

    printArray(arr, *size);
    // deleteElement(arr, size, -11);
    // printArray(arr, *size);
    printf("Result of binary search is: %d\n", binarySearch(arr, size, 4));

    return 0;
}
