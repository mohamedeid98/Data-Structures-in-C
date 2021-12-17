/*
 * median-heap-sort.c
 *
 *  Created on: Dec 17, 2021
 *      Author: mohamed
 */
#include <stdio.h>
#include <stdlib.h>
void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void Heapify(int arr[] , int h_size , int i)
{
    int largest , l , r;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if(l < h_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r < h_size && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&arr[i] , &arr[largest]);
        Heapify(arr , h_size, largest);
    }
}


void Build_Heap(int arr[] , int h_size)
{
    int i;
    for (i = h_size / 2 - 1 ; i >= 0 ; i--)
        Heapify(arr , h_size , i);
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

void Heap_Sort(int arr[] , int h_size)
{
    int i;
    for(i = h_size - 1 ; i >= 1 ; i--)
    {
        swap(&arr[i] , &arr[0]);
        h_size--;
        Heapify(arr , h_size, 0);
    }
}



int isInteger(float N)
{
    if (N < 0)
        N *= -1;
    int X = N;

    double temp2 = N - X;

    if (temp2 > 0) {
        return 0;
    }
    return 1;
}

int main()
{
    float median;
    int size, i;
    scanf("%d", &size);
    if(size <= 0 || size > 10000)
    {
        printf("Not Exist");
        exit(0);

    }
    int arr[size];
    for (i = 0 ; i < size ; i++)
        scanf("%d", &arr[i]);


    //printArray(arr , size);

    Build_Heap(arr , size);

    //printArray(arr , size);

    Heap_Sort(arr , size);

    //printArray(arr , size);

    if (size % 2 != 0)
        printf("%d", arr[size / 2]);
    else if(size % 2 == 0)
    {
        median = (arr[(size - 1) / 2 ] + arr[(size - 1) / 2 + 1]) / 2.0;
        if(isInteger(median))
            printf("%d", (int)median);
        else
            printf("%.1f", median);

    }
    return 0;
}
