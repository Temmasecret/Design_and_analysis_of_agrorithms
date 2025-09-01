#include<stdio.h>

int Binary_search(int value,int arr[], int l,int r)
{
    int mid = (r-l)/2 + l;
    printf("Mid is %d\n",arr[mid]);
    if (value < arr[mid]) return Binary_search(value,arr,l,mid ) + 1;
    else if (value > arr[mid]) return Binary_search(value,arr,mid,r) + 1;
    else return 1;
}
int main()
{
    int arr[100];
    for (int i = 0;i<200;i+=2)
    {
        arr[(i/2)] = i;
    }
    printf("Time find %d ", Binary_search(88,arr,0,99));
    return 0;
}