#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
// For the cost matrix
int N;
int The_map[MAX][MAX];

void init()
{
    cin >> N;
    for (int i =0 ;i<N;i++)
    {
        for (int j = 0; j< N;j++)
        {
            cin >> The_map[i][j];
        }
    }
}

void Prim(int start)
{
    int curr = start;
    int visited[N];
    int full_w = 0;
    memset(visited,0,sizeof(visited));
    int idx = 1;
    int nearest[N];
    memset(nearest,start,sizeof(nearest));
    int curr_min[N];
    memset(curr_min,1000000,sizeof(curr_min));
    curr_min[start] = 0;
    visited[start] = 1;
    while(idx < N)
    {
        int min_test = 1000000;
        int curr_pos = curr;
        for (int i = 0; i<N;i++)
        {
            if (visited[i] == 0 && curr_min[i] > The_map[curr][i] && The_map[curr][i] != 0)
            {
                curr_min[i] = The_map[curr][i];
                nearest[i] = curr;
            }
        }
        for (int i = 0; i<N;i++)
        {
            if (visited[i] == 0 && min_test > curr_min[i])
            {
                min_test = curr_min[i];
                curr_pos = i;
            }
        }
        curr = curr_pos;
        visited[curr] = 1;
        full_w += min_test;
        idx++;
    }
    for (int i = 0; i< N;i++)
    {
        cout <<"The nearest of " <<i<<" is "<< nearest[i]<< " cost is "<<curr_min[i]<<endl;
    }
    cout<<"Full cost is "<<full_w<<endl;
}


int main()
{
    init();
    Prim(0);
    return 0;
}