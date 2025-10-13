#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
int n, a[100][100];
// Init for the base matrix
void Init1(void)
{
    fstream f;
    f.open("input.txt",ios::in);
    if (!f)
    {
        cerr << "Khong mo duoc file "<<endl;
        exit(0);
    }
    f >> n;
    memset(a,0,sizeof(a));
    for (int i = 0 ;i<n;i++)
    {
        for (int j = 0; j<n;j++)
        {
            f >> a[i][j];
        }
    }
}

void Prim_ke(void)
{
    bool visited[100];
    memset(visited,false,sizeof(visited));
    int curr = 0;
    visited[curr] = true;
    int min_curr[100];
    int min_res = 0;
    memset(min_curr,MAX,sizeof(min_curr));
    min_curr[0] = 0;
    int before[100];
    before[0] = 0;
    int idx = 1;
    while (idx < n)
    {
        int Min_pos;
        int Min_tst = MAX;

        for (int i = 0; i< n;i++)
        {
            cout << a[curr][i]<< ' '<<min_curr[i]<<' ' <<visited[i]<<endl;
            if (a[curr][i] != 0 && a[curr][i] < min_curr[i] && !visited[i])
            {
                cout << curr << ' '<<i<<endl;
                min_curr[i] = a[curr][i];
                before[i] = curr;
            }
        }
        for (int i =0 ; i<n;i++)
        {
            if (!visited[i] && Min_tst > min_curr[i])
            {
                Min_pos = i;
                Min_tst = min_curr[i];
            }
        }
        visited[Min_pos] = true;
        min_res += Min_tst;
        curr = Min_pos;
        idx++;
    }
    for (int i = 0; i<n;i++)
    {
        cout << i << "\t"<<before[i]<<"\t"<<min_curr[i]<<endl;
    }
    cout << "Min count is "<< min_res <<endl;
}

int main()
{
    Init1();
    Prim_ke();
}