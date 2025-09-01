#include <inttypes.h>
#include<stdio.h>
#include<stdlib.h>

void Swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}
/*
void Quick_sort(int arr[],int l,int r)
{
    if (l>=r) return;
    printf("%d %d \n",l,r);
    int temp = arr[l];
    int i = l+1;
    int j = r;
    while (i<j)
    {
        while (j > l && arr[j] >= temp) j--;
        while (i < r && arr[i] <= temp) i++;
        if (i < j) Swap(&arr[i],&arr[j]);
    }
    Swap(&arr[l],&arr[j]);
    Quick_sort(arr,l,j-1);
    Quick_sort(arr,j+1,r);
}
*/

void Quick_sort(int arr[], int l, int r)
{
    if (l >= r) return;
    int temp = arr[l];
    int i = l + 1;
    int j = r;
    while (i<j )
    {
        while (i <r && arr[i] < temp) i++;
        while (j >l && arr[j] > temp) j--;
        if (i<j)
        {
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[l],&arr[j]);
    Quick_sort(arr,l,j-1);
    Quick_sort(arr,j+1,r);
}


int main()
{
    int arr[] = {23,28,47,68,29,68,53,41,24,89};
    Quick_sort(arr,0,9);
    for (int i = 0; i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}