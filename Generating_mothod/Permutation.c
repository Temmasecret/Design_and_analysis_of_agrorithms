#include<stdio.h>
#define MAX 1000
int arr[MAX];
int count;

void print_arr(int n)
{
    count++;
    printf("Time %d : ",count);
    for (int i = 0; i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void init(int n)
{
    count = 0;
    for (int i = 0; i<n;i++)
    {
        arr[i] = i+1;
    }
}

void swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

void reverse_arr(int arr[], int l, int r)
{
    while (r > l)
    {
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }
}

void Permutation(int n)
{
    int idx = n-1;
    print_arr(n);
    while (idx >0)
    {
        if (arr[idx] < arr[idx-1])
        {
            idx --;
        }
        else
        {
            int tg = MAX;
            int pos = 0;
            for (int i = idx; i<n;i++)
            {
                if (arr[i] > arr[idx-1] && arr[i] < tg) 
                {
                    tg = arr[i];
                    pos = i;
                }
            }
            swap(&arr[pos],&arr[idx-1]);
            reverse_arr(arr,idx,n-1);
            print_arr(n);
            idx = n-1;
        }
    }
}

int main()
{
    init(5);
    Permutation(5);
    return 0;
}