#include <stdio.h>

int main()
{

    int listOfNumbers[15] = {11, 9, 3, 2, 4, 5, 1, 8, 7, 6};

    int arrSize = sizeof(listOfNumbers) / sizeof(listOfNumbers[0]);

    for (int i = 0; i < arrSize; i++)
    {
        for (int count = 0; count < arrSize - i; count++)
        {

            if (listOfNumbers[count] > listOfNumbers[count + 1])
            {

                int temp = listOfNumbers[count];

                listOfNumbers[count] = listOfNumbers[count + 1];
                listOfNumbers[count + 1] = temp;
            }
        }
        if (i + 1 == arrSize)
        {
            break;
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", listOfNumbers[i]);
    }

    return 0;
}