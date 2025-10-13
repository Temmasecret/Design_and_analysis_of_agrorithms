#include<bits/stdc++.h>
using namespace std;

int n,a[100][100];

void init()
{
    fstream f;
    f.open("input.txt",ios::in);
    if (!f)
    {
        cerr << "Loi khi mo file !!";
        exit(0);
    }
    f >> n;
    for (int i = 0;i<n;i++)
    {
        for (int j = 0 ; j<n;j++)
        {
            f >> a[i][j];
        }
    }
}

void solve(void)
{
    int mau[100];
    memset(mau,0,sizeof(mau));
    mau[0] = 1;
    for (int i = 1; i<n;i++)
    {
        bool mau_check[100];
        memset(mau_check,false,sizeof(mau_check));
        int mau_max = 0;
        bool check = true;
        memset(mau_check,0,sizeof(mau_check));
        for (int j = 0; j<n;j++)
        {
            if (a[i][j] != 0)
            {
                mau_check[mau[j]] = true;
                if (mau_max < mau[j]) mau_max = mau[j];
            }
        }
        mau[i] = 1;
        for (int j = 1; j<=mau_max;j++)
        {
            if (!mau_check[j])
            {
                break;
            }
            mau[i] = j+1;
        }
    }   
    cout <<"Mau\tDinh"<<endl;
    for (int t = 0; t < n;t++)
    {
        cout << t << "\t"<< mau[t] <<endl;
    }
}

int main()
{
    init();
    solve();    
}