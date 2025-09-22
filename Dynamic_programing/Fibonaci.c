#include<stdio.h>
#include<stdlib.h>

void Push_dynamic_array(int* arr,int curr_len,int data)
{
    printf("%d %d\n",curr_len,arr[curr_len - 1]);
    arr = (int*)realloc(arr,curr_len +1);
    printf("%d %d\n",curr_len,arr[curr_len - 1]);
    arr[curr_len] = data; 
    printf("%d--------\n",arr[curr_len]);
}

int Fibo(int n)
{
    int *arr = (int*)malloc(sizeof(int)*2);
    arr[0] = 1;
    arr[1] = 1;
    if (n < 0) return -1;
    if (n < 2) return arr[n];
    int idx = 2;
    while (idx < n)
    {
        int tg = arr[idx - 1] + arr[idx - 2];
        Push_dynamic_array(arr,idx,tg);
        idx ++;
    }
    return arr[idx-1];
}

long long Fibonacii(long long n)
{
    long long arr[1000];
    if (n < 0 || n > 1000) return -1;
    arr[0] = 1;
    arr[1] = 1;
    int idx = 1;
    while (idx < n)
    {
        idx ++;
        arr[idx] = arr[idx - 1] + arr[idx - 2];
    }
    return arr[idx];
}

int main()
{
    printf("%lld",Fibonacii(100));
}