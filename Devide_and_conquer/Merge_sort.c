#include<stdio.h>
#include<stdlib.h>

void Merge_arr(int arr[],int l,int mid,int r)
{
    //setting up
    int N1 = mid - l + 1;
    int N2 = r - mid;
    int *A1 = (int*)malloc(sizeof(int) * N1);
    int *A2 = (int*)malloc(sizeof(int) * N2);
}

void Merge_sort(int arr[],int l,int r)
{
    if (l>= r) return;
    int mid = (r-l)/2 + l;
    Merge_sort(arr,l,mid);
    Merge_sort(arr,mid+1,r);
    Merge_arr(arr,l,mid,r);
}

int main()
{
    return 0;
}