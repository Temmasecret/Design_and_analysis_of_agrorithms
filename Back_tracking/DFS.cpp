#include<bits/stdc++.h>
using namespace std;

// This is for matrix map
#define MAX 1000
int themap[MAX][MAX];
int visited[MAX];
void init(int size)
{
    for (int i = 0;i<size;i++)
    {
        for (int j = 0; j< size;j++)
        {
            cin >> themap[i][j];
        }
    }
    for (int i = 0; i<size;i++)
    {
        visited[i] = 0;
    }

}
void DFS(int size, int curr)
{
    visited[curr] = 1;
    cout<< curr + 1 <<' ';
    for (int i = 0;i<size;i++)
    {
        if (themap[curr][i] != 0 && visited[i] == 0)
        {
            DFS(size,i);
        }
    }
}

// This is for list 
vector<int> point[MAX];
void init2(int size)
{
    for (int i = 0; i<size;i++)
    {
        int tg = 1;
        while (tg >0 && tg <=size)
        {
            cin >> tg;
            if (tg >0 && tg <=size) point[i].push_back(tg-1);
        }
    }
    for (int i = 0; i<size;i++)
    {
        visited[i] = 0;
    }
}

void DFS2(int size,int curr)
{
    visited[curr] = 1;
    cout << curr + 1 << ' ';
    for (int i : point[curr])
    {
        if (visited[i] == 0)
        {
            DFS2(size,i);
        }
    } 
}

int main()
{
    int tst;
    cin >> tst;
    init(tst);
    DFS(tst,0);
    // init2(tst);
    // DFS2(tst,0);
    return 0;
}

/*
6                         
0 1 1 0 1 0
0 0 0 0 0 1
0 1 0 0 1 0
1 0 1 0 1 0
0 0 0 0 0 1
1 1 0 1 0 0

6
2 3 5 7
6 7
2 5 7
1 3 5 7
6 7
1 2 4 7
*/