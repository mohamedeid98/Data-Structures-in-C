/*
 * Largest-Possible-Interval-using-heapsort.c
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

int Largest_Interval(int arr[], int size)
{
    int i, max, diff;
    if(size < 2)
        return 0;
    max = abs(arr[1] - arr[0]);
    for (i = 1 ; i < size -1 ; i++)
    {
        diff = abs(arr[i + 1] - arr[i]);
        if(diff > max)
            max = diff;

    }
    return max;
}



int main()
{
    int N;
    scanf("%d", &N);


    int arr[N];

    for(int i = 0 ; i < N ; i++)
        scanf("%d", &arr[i]);

    Build_Heap(arr, N);
    Heap_Sort(arr, N);
    printf("%d", Largest_Interval(arr, N));




    return 0;
}







