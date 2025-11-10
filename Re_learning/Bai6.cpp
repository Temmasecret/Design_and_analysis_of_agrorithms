#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int the_map[MAX][MAX];
int N;

void init()
{
    cin >> N;
    for(int i = 0;i<N;i++)
    {
        for (int j = 0; j< N;j++)
        {
            cin >> the_map[i][j];
        }
    }
}

void The_arrived(int start)
{
    int curr = start;
    int next = start;
    int full_cost = 0;
    int curr_min = 10000000;
    int visited[N];
    memset(visited,0,sizeof(visited));
    visited[start] = 1;
    int idx = 1;
    while (idx < N)
    {
        for (int i = 0; i< N;i++)
        {
            if (visited[i] == 0 && the_map[curr][i] < curr_min && the_map[curr][i] !=0)
            {
                next = i;
                curr_min = the_map[curr][i];
            }
        }
        full_cost += the_map[curr][next];
        visited[next] = 1;
        cout << "< "<<curr<<','<<next<<" >"<<endl;
        curr = next;
        curr_min = 10000000;
        idx ++;
    }
    full_cost += the_map[curr][start];
    cout << "< "<<curr<<','<<start<<" >"<<endl;
    cout << "The arrival cost is : "<< full_cost;
}

int main()
{
    init();
    The_arrived(2);
    return 0;
}
/*
5
0 1 2 7 5
1 0 4 4 3
2 4 0 1 2
7 4 1 0 3
5 3 2 3 0
*/