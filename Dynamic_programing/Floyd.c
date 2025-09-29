#include <stdio.h>

#define INF (int)1e9

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    int d[n][n];
    int p[n][n];    
    for (int i = 0; i< n;i++)
    {
        for (int j =0 ; j< n;j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j] == -1) a[i][j] = INF;
            if (i == j ) a[i][j] = 0;
            d[i][j] = a[i][j];
            p[i][j] = -1;
        }
    }
    for (int k = 0; k < n ;k++)
    {
        for (int i = 0; i< n;i++)
        {
            if (d[i][k] > 0 && d[i][k] < INF)
            {
                for (int j = 0; j< n ;j++)
                {
                    if (d[k][j] > 0 && d[i][j] > d[i][k] + d[k][j])
                    {   
                        d[i][j] = d[i][k] + d[k][j];
                        p[i][j] = k;
                    }
                }
            }
        }
    }

    printf("This is how the world show : \n");
    for (int i = 0; i< n; i++)
    {
        for (int j = 0 ; j< n ;j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }

    printf("Haiz\n");
    for (int i = 0; i< n;i++)
    {
        for (int j = 0; j< n; j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }

    return 0;
}