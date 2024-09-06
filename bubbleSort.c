#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            int temp = arr[j];
            if (temp > arr[j + 1])
            {
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    int arr[] = {1, 2, 34, 67, 88, 93, 34, 66, 3, 45};
    size = sizeof(arr) / sizeof(int);
    print(arr, size);

    bubbleSort(arr, size);

    print(arr, size);

    return 0;
}