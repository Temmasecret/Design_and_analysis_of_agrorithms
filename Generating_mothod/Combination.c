#include<stdio.h>
#define MAX 1000
int arr[MAX];

void init(int n, int k)
{
    for (int i = 0; i<k;i++)
    {
        arr[i] = i+1;
    }
}

void print_arr(int k)
{
    printf("\n");
    for (int i = 0; i<k;i++)
    {
        printf("%d",arr[i]);
    }
}

// Max of each pos is: n - k + idx + 1
void Combination(int n, int k)
{
    int idx = k-1;
    print_arr(k);
    while (idx >= 0)
    {
        if (arr[idx] < n - k + idx + 1)
        {
            arr[idx]++;
            for (int i = idx +1 ; i<k;i++)
            {
                arr[i] = arr[i-1]+1;
            }
            print_arr(k);
            idx = k-1;
        }
        else idx--;
    }
}

int main()
{
    init(5,3);
    Combination(5,3);
    return 0;
}