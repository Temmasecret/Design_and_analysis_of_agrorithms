#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int N;
int The_map[MAX][MAX];

void Init()
{
    cin >> N;
    for (int i = 0; i< N ; i++)
    {
        for (int j = 0; j< N;j++)
        {
            cin >> The_map[i][j];
        }
    }
}

void Dijsktra(int start)
{
    int curr = start;
    int visited[N];
    memset(visited,0,sizeof(visited));
    visited[start] = 1;
    int Min_cost[N];
    memset(Min_cost,1000000,sizeof(Min_cost));
    int nearest[N];
    memset(nearest,start,sizeof(nearest));
    Min_cost[start] = 0;
    int idx = 1;
    while (idx < N)
    {
        int Min_curr = 1000000;
        int curr_pos = curr;
        for (int i = 0; i< N;i++)
        {
            if (visited[i] == 0 && Min_cost[i] > Min_cost[curr] + The_map[curr][i] && The_map[curr][i] !=0)
            {
                Min_cost[i] = Min_cost[curr] + The_map[curr][i];
                nearest[i] = curr;
            }
        }
        for (int i = 0; i< N;i++)
        {
            if (visited[i] == 0 && Min_curr > Min_cost[i])
            {
                Min_curr = Min_cost[i];
                curr_pos = i;
            }
        }
        visited[curr_pos] = 1;
        curr = curr_pos;
        Min_curr = 1000000;
        idx++;
    }
    for (int i = 0; i< N;i++)
    {
        cout <<"The nearest of " <<i<<" is "<< nearest[i]<< " cost is "<<Min_cost[i]<<endl;
    }
}

int main()
{
    Init();
    Dijsktra(0);
    return 0;
}