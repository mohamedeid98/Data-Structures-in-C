#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

unsigned concat(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return (x * pow + y);
}

int compare(int X, int Y)
{

    int XY, YX;
    XY = concat(X , Y);
    YX = concat(Y , X);
    return XY <= YX ? 1 : 0;
}


int partition(int arr[] , int start , int end)
{
    int pivot = arr[end];
    int partitionIndex = start;
    for(int i = start ; i < end ; i++)
    {
        if(compare(arr[i], pivot))
        {
            swap(&arr[i] , &arr[partitionIndex]);
            partitionIndex++;
        }

    }
    swap(&arr[partitionIndex] , &arr[end]);
    return partitionIndex;
}

void QuickSort(int arr[] , int start , int end)
{
    if(start < end)
    {
        int partitionIndex = partition(arr , start , end);
        QuickSort(arr , start , partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, end);
    }
}


int main()
{

    int N;
    scanf("%u", &N);

    int arr[N];
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &arr[i]);

    }
    if(N > 0)
    {
        QuickSort(arr , 0 , N-1);

        for(int i = N-1 ; i >= 0 ; i--)
        {
            printf("%d", arr[i]);
        }
    }



}





