#include<bits/stdc++.h>
#include <utility>
using namespace std;

void swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}
void print_arr(int arr[], int l, int r)
{
    for (int i =l; i<=r; i++)
    {
        cout << arr[i]<<' ';
    }
    cout <<endl;
}

void Quick_sort(int arr[], int l, int r)
{
    if (l >= r) return;
    int tg = arr[l];
    int i = l+1;
    int j = r;
    while (i<j)
    {
        while (arr[i] <= tg && i< r) i++;
        while (arr[j] >= tg && j > l) j--;
        if (i<j && arr[i] > arr[j])
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[l],&arr[j]);
    Quick_sort(arr,l,j-1);
    Quick_sort(arr,j+1,r);
}

int main()
{
    int arr[] = {9,1,8,2,7,3,6,4,5};
    Quick_sort(arr,0,8);
    print_arr(arr,0,8);
    return 0;
}