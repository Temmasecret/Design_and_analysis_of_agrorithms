#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int Map[n][n];
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++)
        {
            scanf("%d",&Map[i][j]);
        }
    }
    int check[n];
    for (int i = 0;i<n;i++)
    {
        check[i] = 0;
    }
    int cur = 0;
    check[cur] = 1;
    int cost_remain[n];
    for (int i = 1 ; i< n;i++)
    {
        cost_remain[i] = 100000;
    }
    int idx = 1;
    cost_remain[0] = 0;
    while (idx < n)
    {
        int cur_test = 1;
        for (int i = 1; i< n;i++)
        {
            if (check[i] == 0 && cost_remain[i] > cost_remain[cur] + Map[cur][i])
            {
                cur_test = i;
                cost_remain[i] = cost_remain[cur] + Map[cur][i];
            } 
        }
        cur = cur_test;
        check[cur] = 1;
        idx++;
    }
    for (int i = 0; i< n;i++)
    {
        printf("%d ",cost_remain[i]);
    }
    return 0;
}