#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int The_map[MAX][MAX];
int N;
typedef struct Canh{
    int start;
    int end;
    int cost;
}Canh;
vector<Canh> DS;

bool cmp(Canh a, Canh b)
{
    if (a.cost > b.cost) return false;
    else return true;
}

void Init()
{
    cin >> N;
    for (int i = 0; i< N; i++)
    {
        for (int j = 0; j<N;j++)
        {
            cin >> The_map[i][j];
            if (The_map[i][j] != 0) 
            {
                Canh moi;
                moi.start = i;
                moi.end = j;
                moi.cost = The_map[i][j];
                DS.push_back(moi);
            }
        }
    }
    sort(DS.begin(),DS.end(),cmp);
}

void Kruskal(int start)
{
    int full_c = 0;
    int closest[N];
    int visited[N];
    memset(visited,0,sizeof(visited));
    memset(closest,-1,sizeof(closest));
    for (auto i : DS)
    {
        if (closest[i.start] != -1 && closest[i.end] != -1) continue;
        cout << "Chon canh: "<< i.start<< ' '<<i.end<<' '<<i.cost<<endl;
        full_c += i.cost;
        if (closest[i.start] == -1 && visited[i.end] == 0)
        {
            closest[i.start] = i.end;
            visited[i.end] = 1;
        }
        if (closest[i.end] == -1 && visited[i.start] == 0) 
        {
            closest[i.end] = i.start;
            visited[i.start] = 1;
        }
    }
    for (int i = 0; i<N;i++)
    {
        cout << i<< ' '<<closest[i]<<endl;
    }
}   

int main()
{
    Init();
    Kruskal(0);
    return 0;
}