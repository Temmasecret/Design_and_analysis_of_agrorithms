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

long long fibo_ret(int n)
{
    if (n < 2) return n;
    else return fibo_ret(n-1) + fibo_ret(n-2);
}

long long fibo_dynamic(int n)
{
    long long tg_0 = 0;
    long long tg_1 = 1;
    int k = 2;
    if (n == 0) return tg_0;
    while (k <=n)
    {
        long long tg = tg_1;
        tg_1 += tg_0;
        tg_0 = tg; 
    }
    return tg_1;
}

long long fibo_fuse(int n)
{
    return 0;
}

int main()
{
    printf("%lld",Fibonacii(100));
}