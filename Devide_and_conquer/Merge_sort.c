#include<stdio.h>
#include<stdlib.h>

void Merge_arr(int arr[],int l,int mid,int r)
{
    //setting up
    int N1 = mid - l + 1;
    int N2 = r - mid;
    int *A1 = (int*)malloc(sizeof(int) * N1);
    int *A2 = (int*)malloc(sizeof(int) * N2);
    // Insert the value into new array
    for (int i = 0;i<N1;i++)
    {
        A1[i] = arr[i+l];
    }
    for (int i = 0;i<N2;i++)
    {
        A2[i] = arr[i+mid+1];
    }
    //Merge the array
    int i = 0;
    int j = 0;
    int Num_run = l;
    while (i<N1 && j <N2)
    {
        if (A1[i] < A2[j]) 
        {
            arr[Num_run] = A1[i];
            i++;
        }
        else 
        {
            arr[Num_run] = A2[j];
            j++;
        }
        Num_run ++;
    }
    while (i<N1)
    {
        arr[Num_run] = A1[i];
        i++;
        Num_run++;
    }
    while (i<N2)
    {
        arr[Num_run] = A2[j];
        j++;
        Num_run++;
    }
    free(A1);
    free(A2);
}

void Merge_sort(int arr[],int l,int r)
{
    if (l>= r) return;
    int mid = (r-l)/2 + l;
    for (int i = 0;i<13;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    Merge_sort(arr,l,mid);
    Merge_sort(arr,mid+1,r);
    Merge_arr(arr,l,mid,r);
}

int main()
{
    int arr[] = {23,43,123,56,564,29,126,65,20,45,21,78,46};
    Merge_sort(arr,0,12);
    for (int i = 0;i<13;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}