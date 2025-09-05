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

void Merge_arr(int arr[],int l, int r, int mid)
{
    int N1 = mid - l + 1;
    int N2 = r - mid;
    int* L1 = (int*)malloc(sizeof(int)* N1);
    int* L2 = (int*)malloc(sizeof(int )*N2);
    for (int i = 0;i<N1;i++)
    {
        L1[i] = arr[l+i];
    }
    for (int i = 0;i<N2;i++)
    {
        L2[i] = arr[mid + i + 1];
    }
    int idx1 = 0;
    int idx2 = 0;
    int arr_count = l;
    while (idx1 < N1 && idx2 < N2)
    {
        if (L1[idx1] > L2[idx2]) 
        {
            arr[arr_count] = L2[idx2];
            idx2++;
        }
        else 
        {
            arr[arr_count] = L1[idx1];
            idx1++;
        }
        arr_count++;
    } 
    while(idx1 < N1 )
    {
        arr[arr_count] = L1[idx1];
        idx1 ++;
        arr_count ++;
    }
    while(idx2 < N2)
    {
        arr[arr_count] = L2[idx2];
        idx2++;
        arr_count++;
    }
    free(L1);
    free(L2);
}

void Merge_sort(int arr[],int l,int r)
{
    if (l>= r || l< 0 || r < 0)  return;
    int mid = (r-l)/2 + l;
    Merge_sort(arr,l,mid);
    Merge_sort(arr,mid + 1,r);
    Merge_arr(arr,l,r,mid);
}

int main()
{
    int arr[] = {3,5,8,9,4,2,7,5,3,9,8};
    Merge_sort(arr,0,10);
    for (int i = 0;i<11;i++)
    {
        printf("%d ",arr[i]);
    
    }
    printf("\n Can find 5,6,7 : %d , %d , %d \n",Binary_search(arr,0,10,5),Binary_search(arr,0,10,6),Binary_search(arr,0,10,7));
    return 0;
}