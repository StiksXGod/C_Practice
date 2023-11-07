#include <stdio.h>

#define MAX_LENGHT  10

int main()
{
    int mass[MAX_LENGHT] = {1,-1,-1,5,6,7,4,3,-9,-3};
    int size = sizeof(mass)/sizeof(mass[0]);
    int pos;
    for (int i = 0; i < size-1; i++)
    {
        pos = i;
        for (int j = i+1; j < size; j++)
        {
            if (mass[pos]>mass[j])
            {
                pos = j;
            }
            
        }

        if (pos!=i)
        {
            int swtch = mass[pos];
            mass[pos] = mass[i];
            mass[i] = swtch;
        }
        
        
    }


    for (int i = 0; i < size; i++)
    {
        printf("%d ", mass[i]);
    }
    printf("\n");
    

}
