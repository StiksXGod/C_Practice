#include <stdio.h>

#define SIZE_MASS   10

void buble_sort(int mass[])
{
    int size = SIZE_MASS;
    while(size !=0)
    {
        int max_ind = 0;
        for (int i = 1; i < size; i++)
        {
            if (mass[i-1]>mass[i])
            {
                int temp = mass[i];
                mass[i] = mass[i-1];
                mass[i-1] = temp;
                max_ind = i;
            }
            
        }
        size = max_ind;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", mass[i]);
    }
    printf("\n");
    

}
