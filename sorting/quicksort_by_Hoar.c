#include <stdio.h>

void swap(int* a, int* b)
{
    int temp =* a;
    *a = *b;
    *b = temp;
}



int qsort_part(int mass[], int low, int high)
{
    int pivot = mass[high];
    int i = low -1;
    for (int j = low; j <= high-1; j++)
    {
        if (mass[j]<pivot)
        {
            i++;
            swap(&mass[i], &mass[j]);
        }
        
    }
    swap(&mass[i+1], &mass[high]);
    return i+1;

}


void qsort(int mass[], int low, int high)
{
    if (low<high)
    {
        int wall = qsort_part(mass, low, high);
        qsort(mass, low, wall-1);
        qsort(mass, wall+1, high);
    }
}




int main()
{
    int mass[10] = {1,-2,-3,4,5,6,-7,-8,3,2};
    qsort(mass, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", mass[i]);
    }
    printf("\n");
    


}