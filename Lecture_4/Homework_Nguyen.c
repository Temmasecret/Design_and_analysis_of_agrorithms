#include<stdio.h>
#include<stdlib.h>

void Swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

void Quick_sort(int arr[],int l, int r)
{
    if (l>= r) return;
    int temp = arr[l];
    int i = l+1;
    int j = r;
    while (i <= j )
    {
        while (i<=r && arr[i]<= temp) i++;
        while (j>l && arr[j]> temp) j--;
        if (i<=j) Swap(&arr[i],&arr[j]);
    }
    Swap(&arr[j],&arr[l]);
    Quick_sort(arr,l,j-1);
    Quick_sort(arr,j+1,r);
}

int Binary_search(int arr[],int l,int r,int key)
{
    if (l>=r ) return 0;
    int mid = (r-l)/2 + l;
    if (arr[mid] > key) return Binary_search(arr,l,mid-1,key);
    else if (arr[mid] < key) return Binary_search(arr,mid+1,r,key);
    else return 1;

}

void Merge_sort(int arr[],int l,int r)
{
    
}

int main()
{
    int arr[] = {3,5,8,9,4,2,7,5,3,9,8};
    Quick_sort(arr,0,10);
    for (int i = 0;i<11;i++)
    {
        printf("%d ",arr[i]);
    
    }
    printf("\n Can find 5,6,7 : %d , %d , %d \n",Binary_search(arr,0,10,5),Binary_search(arr,0,10,6),Binary_search(arr,0,10,7));
    return 0;
}