/*
 * Shell_Sort.c
 *
 *  Created on: Dec 12, 2021
 *      Author: mohamed
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// Shell sort

void sort(int arr[], int n)
{
    for(int interval = n/2 ; interval > 0 ; interval /= 2)
    {
        for(int i = interval; i < n ; i++)
        {
            int temp = arr[i];
            int j;
            for(j = i; j >= interval && arr[j - interval] > temp ; j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;

        }
    }

}




int kthlargest(int arr[], int n, int k)
{
    sort(arr, n);
    /*
    for(int i = 0 ; i < n ; i++)
        printf("%d", arr[i]);
    printf("\n");*/
    return arr[n-k];
}

int main()
{
    int arr[10000];
    int k, N ;
    scanf("%d%d", &N, &k);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", kthlargest(arr, N, k));
    return 0;
}
