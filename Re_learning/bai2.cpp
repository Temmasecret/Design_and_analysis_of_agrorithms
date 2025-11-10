#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

void print_arr(int arr[], int l, int r)
{
    for(int i = l; i<=r;i++)
    {
        cout <<arr[i]<<' ';
    }
    cout <<endl;
}

void Merge_arr(int arr[], int l, int r, int mid)
{
    if (l >= r) return;
    int arr1[mid + 1 -l];
    int arr2[r-mid];
    for (int i = l; i<=mid;i++)
    {
        arr1[i-l] = arr[i]; 
    }
    for (int i = mid+1; i<=r;i++)
    {
        arr2[i - mid -1] = arr[i];
    }
    int i = 0;
    int j = 0;
    int idx = l;
    while (i <= (mid - l) && j <= (r - mid - 1))
    {
        if (arr1[i] < arr2[j])
        {
            arr[idx] = arr1[i];
            i++;
        }
        else{
            arr[idx] = arr2[j];
            j++;
        }
        idx++;
    }
    while (i <= (mid - l))
    {
        arr[idx] = arr1[i];
        i++;
        idx++;
    }
    while (j <= (r - mid - 1))
    {
        arr[idx] = arr2[j];
        j++;
        idx ++;
    }
}

void Merge_sort(int arr[], int l, int r)
{
    if (l >= r ) return;
    int mid = (l+r)/2;
    Merge_sort(arr,l,mid);
    Merge_sort(arr,mid + 1, r);
    Merge_arr(arr,l,r,mid);
}

int main()
{
    int arr[] = {9,1,8,2,7,3,6,4,5};
    Merge_sort(arr,0,8);
    print_arr(arr,0,8);
    return 0;
}