#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* atm_recv(int money, int cost_m[], int num_past)
{
    int *Num_pass  = (int*)malloc(sizeof(int)*num_past);
    memset(Num_pass, 0, sizeof(int)*num_past);
    int i = 0;
    while (money > 0)
    {
        Num_pass[i] = money / cost_m[i];
        money = money % cost_m[i];
        i++;
    }
    return Num_pass;
}

void Swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

void Heapify(int arr[],int l,int r,int idx)
{
    int num1 = 2*idx + 1;
    int num2 = 2*idx + 2;
    if (num1 <= r) 
    {
        Heapify(arr,l,r,num1);
        if (arr[num1] > arr[idx])
        {
            Swap(&arr[idx],&arr[num1]);
        } 
        
    }
    if(num2 <= r)
    {
        Heapify(arr,l,r,num2);
        if (arr[num2] > arr[idx])
        {
            Swap(&arr[idx],&arr[num2]);
        }
        
    }
}

void Heap_sort(int arr[],int l,int r)
{
    for (int i = r;i>=l;i--)
    {
        Heapify(arr,l,i,l);
        Swap(&arr[i],&arr[l]);
    }
}


int main()
{
    int cost_m[4] = {100,50,20,10};
    int* atm_Nhan = atm_recv(410,cost_m,4);
    for (int i = 0;i<4;i++)
    {
        printf("%d ",atm_Nhan[i]);
    }
    printf("\n");
    int arr[] = {53,57,15,84,23};
    Heap_sort(arr,0,4);
    for (int i = 0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}