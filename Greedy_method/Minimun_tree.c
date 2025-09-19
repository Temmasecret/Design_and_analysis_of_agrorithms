#include<stdio.h>
// #include<stdlib.h>

//inf for this one is 100000000

float Prim(float Map[7][7])
{
    float Min_cost = 0;
    int closest[7];
    int visited[7];
    float Min_full[7];
    for (int i = 0;i<7;i++)
    {
        closest[i] = 0;
        visited[i] = 0;
        Min_full[i] = 100000000;
    }
    Min_full[0] = 0;
    visited[0] = 1;
    int curr = 0;
    int idx = 1;
    while (idx < 7)
    {
        int min_pos = curr;
        float min_cost = 100000000;
        for (int i = 1;i<7;i++)
        {
            if (visited[i] == 0 && Min_full[i] > Map[curr][i] && curr !=i)
            {
                Min_full[i] = Map[curr][i];
                closest[i] = curr;
            }
        }
        for (int i = 1;i<7;i++)
        {
            if (min_cost > Min_full[i] && visited[i] == 0)
            {
                min_pos = i;
                min_cost = Min_full[i];
                
            }
        }
        curr = min_pos;
        visited[curr] = 1;
        idx++;
    }
    for (int i = 0;i<7;i++)
    {
        Min_cost += Min_full[i];
    }
    for (int i = 0;i< 7;i++)
    {
        printf(" %d .. %d : %.2f - ",i + 1,closest[i] + 1,Min_full[i]);
    }
    printf("\n");
    return Min_cost;
}

int main()
{
    float Graph[7][7];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            scanf("%f", &Graph[i][j]);
        }
    }
    printf("%.2f",Prim(Graph));
    return 0;
}

/*
0 1 100000000 4 100000000 100000000 100000000
1 0 2 6 6 100000000 100000000
100000000 2 0 100000000 4 5 100000000
4 6 100000000 0 3 100000000 4
100000000 6 4 3 0 8 7
100000000 100000000 5 100000000 8 0 3
100000000 100000000 100000000 4 7 3 0
*/