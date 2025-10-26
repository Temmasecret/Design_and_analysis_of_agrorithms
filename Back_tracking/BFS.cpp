#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

//Thix is for matrix map
int themap[MAX][MAX];
int visited[MAX];

void init(int size)
{
    for (int i = 0; i<size;i++)
    {
        for (int j = 0; j< size;j++)
        {
            cin >> themap[i][j];
        }
    }
    for (int i =0 ; i< size;i++)
    {
        visited[i] = 0;
    }
}

void BFS(int size,int curr)
{
    queue<int> q;
    visited[curr] = 1;
    q.push(curr);
    while (!q.empty())
    {
        int test = q.front();
        cout << test + 1 <<' ';
        q.pop();
        for (int i = 0; i<size;i++)
        {
            if (themap[test][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

// This is for list 
vector<int> point[MAX];
void init2(int size)
{
    for (int i = 0;i<size;i++)
    {
        int tg = 1;
        while (tg > 0 && tg <= size)
        {
            cin >> tg;
            if (tg > 0 && tg <= size) point[i].push_back(tg -1);
        }
    }
    for (int i = 0; i< size;i++)
    {
        visited[i] = 0;
    }
}

void BFS2(int size, int curr)
{
    queue<int> q;
    visited[curr] = 1;
    q.push(curr);
    while(!q.empty())
    {
        int test = q.front();
        cout << test + 1 << ' ';
        q.pop();
        for (int i : point[test])
    {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int tg;
    cin >> tg;
    // init(tg);
    // BFS(tg,0);
    init2(tg);
    BFS2(tg,0);
}

