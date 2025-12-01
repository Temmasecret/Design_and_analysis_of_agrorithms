#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int Map[MAX][MAX];
int d[MAX][MAX];
int p[MAX][MAX];
int n;
void init()
{
    cin >> n;
    for (int i = 0;i <n;i++)
    {
        for (int j = 0; j< n;j++)
        {
            cin >> Map[i][j];
            if (i != j && Map[i][j] == 0) Map[i][j] = MAX;
            d[i][j] = Map[i][j];
            p[i][j] = 0; 
        }
    }
}

void Min_road()
{
    for (int i = 0;i<n;i++)
    {
        for (int k = 0; k<n;k++)
        {
            for (int j = 0; j< n;j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
    cout<< "-------------MATRIX d-------------------"<<endl;
    for (int i = 0;i<n;i++)
    {
        for (int j = 0; j<n;j++)
        {
            cout << d[i][j] << '\t';
        }
        cout <<endl;
    }
    cout<< "-------------MATRIX p-------------------"<<endl;
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j< n;j++)
        {
            cout << p[i][j] << '\t';
        }
        cout <<endl;
    }
}
int main()
{
    init();
    Min_road();
    return 0;
}