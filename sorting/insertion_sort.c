#include <stdio.h>

#define MAX_SIZE    10


void inserion_sort(int mass[])
{
    for (int i = 1; i < MAX_SIZE; i++)
    {
        int gran = i - 1;
        while(gran > -1 && mass[gran] > mass[gran+1])
        {
            int temp = mass[gran];
            mass[gran] = mass[gran+1];
            mass[gran+1] = temp;
            gran--;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", mass[i]);
    }
    printf("\n");
    
}


