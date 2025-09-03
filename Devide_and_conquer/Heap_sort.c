#include<stdio.h>
#include<stdlib.h>

void Swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

// void Heapify(int arr[],int l, int r, int index)
// {
//     int Num_1 = 2*index + 1;
//     int Num_2 = 2*index + 2;
//     printf("%d -",arr[index]);
//     if(Num_1 <= r) 
//     {
//         Heapify(arr,l,r,Num_1);
//         if (arr[Num_1] > arr[index])
//         {
//             Swap(&arr[index],&arr[Num_1]);
//         }
//         printf("%d --",arr[Num_1]);
//     }
//     if (Num_2 <= r)
//     {
//         Heapify(arr,l,r,Num_2);
//         if (arr[Num_2] > arr[index])
//         {
//             Swap(&arr[Num_2],&arr[index]);
//         }
//         printf("%d ---",arr[Num_2]);
//     }
//     printf("\n");
// }

// void Heap_sort(int arr[], int l, int r)
// {
//     for (int i = r;i>l;i--)
//     {
//         Heapify(arr,l,i,0);
//         Swap(&arr[l],&arr[i]);
//     }  
// }

void Heapify(int arr[], int l,int r, int index)
{
    int Num_1 = 2*index + 1;
    int Num_2 = 2*index + 2;
    if (Num_1 <= r)
    {
        Heapify(arr,l,r,Num_1);
        if (arr[Num_1] > arr[index])
        {
            Swap(&arr[Num_1],&arr[index]);
        }
    }
    if (Num_2 <= r)
    {
        Heapify(arr,l,r,Num_2);
        if(arr[Num_2] > arr[index])
        {
            Swap(&arr[Num_2], &arr[index]);
        }
    }
}

void Heap_sort(int arr[],int l,int r)
{
    for (int i = r;i>l;i--)
    {
        Heapify(arr,l,i,0);
        Swap(&arr[i],&arr[l]);
    }
}

int main()
{
    int arr[] = {82,57,47,20,56,26,21,347};
    Heap_sort(arr,0,7);
    for (int i= 0; i<8;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}