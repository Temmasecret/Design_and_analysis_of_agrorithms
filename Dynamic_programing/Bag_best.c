#include <stdio.h>

int max_val(int a, int b)
{
    if (a > b) return a;
    else return b;
}

int main()
{
    int SL_do;
    scanf("%d",&SL_do);
    int w_bag;
    scanf("%d",&w_bag);
    int w[SL_do + 1];
    int c[SL_do + 1];
    w[0] = 0;
    c[0] = 0;
    for (int i = 1; i <= SL_do ; i++)
    {
        scanf("%d %d",&w[i],&c[i]);
    }
    // Trien khai
    // Khoi tao mang 2 chieu chua cac gia tri lon nhat co the mang di tren tung phan
    int max[w_bag + 1][SL_do + 1];
    for (int i = 0 ; i<= w_bag ;i++)
    {
        max[i][0] = 0;
    }
    for (int i = 0; i<= SL_do; i++)
    {
        max[0][i] = 0;
    }
    // Check in
    for (int i = 1; i<= SL_do;i++)
    {
        for (int j = 1; j <= w_bag; j++)
        {
            max[j][i] = max[j][i-1];
            if (j >= w[i] ) 
            {
                max[j][i] = max_val(max[j][i-1], max[j-w[i]][i-1] + c[i]);
            }
        }
    }
    printf("The max can handle is %d \n ",max[SL_do][w_bag]);
    for (int i = 0; i<=SL_do ;i++)
    {
        for (int j = 0; j<= w_bag;j++)
        {
            printf("%d ",max[j][i]);
        }
        printf("\n");
    }
    return 0;
}