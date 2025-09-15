#include<stdio.h>

float Shortest_way(float Map[5][5])
{
    float res = 0;
    int cur = 0;
    int visit[5];
    for (int i = 0; i< 5;i++)
    {
        visit[i] = 0;
    }
    visit[cur] = 1;
    int idx = 1;
    while (idx < 5)
    {
        float min = 10000;
        int find_min = cur;
        for (int i = 0;i< 5;i++)
        {
            if (visit[i] == 0 && cur!=i && min > Map[cur][i])
            {
                min = Map[cur][i];
                find_min = i;
            }
        }
        cur = find_min;
        visit[cur] = 1;
        res += min;
        idx++;
    }
    return res + Map[cur][0];
}

int main()
{
    float arr[5][5];
    for (int i = 0;i<5;i++)
    {
        for (int j = 0;j<5;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }
    printf("The shortest is %.2f",Shortest_way(arr));
    return 0;
}