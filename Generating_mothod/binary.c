#include<stdio.h>
#define MAX 1000
int arr[MAX];
void init(int n)
{
    for (int i = 0; i<n ;i++)
    {
        arr[i] = 0;
    }
}

void print_arr(int n)
{
    printf("\n");
    for (int i = 0;i< n;i++)
    {
        printf("%d",arr[i]);
    }
}

void Bin(int n)
{
    int idx = n -1;
    print_arr(n);
    while(idx >= 0 )
    {
        if (arr[idx] == 0)
        {
            arr[idx] = 1;
            print_arr(n);
            idx = n-1;
        }
        else
        {
            arr[idx] = 0;
            idx--;
        }
    }
    
}

int main()
{
    Bin(6);
    return 0;
}