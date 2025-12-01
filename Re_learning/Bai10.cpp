#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> graph[n];
    for (int i = 0; i< n; i++)
    {
        int adding = 1;
        while (adding >= 0)
        {
            cin >> adding;
            if (adding >= 0) graph[i].push_back(adding);
        }
    }
    int mau[n];
    mau[0] = 0;
    for (int i = 1; i<n; i++)
    {
        bool mau_check[n];
        memset(mau_check,false,sizeof(mau_check));
        for (auto gi : graph[i])
        {
            mau_check[gi] = true;
        }
        for (int j = 0; j< n;j++)
        {
            if (!mau_check[j])
            {
                mau[i] = j;
                break; 
            }
        }
    }
    for (int i = 0; i<n;i++)
    {
        cout << "Diem "<< i<< " co mau "<< mau[i]<<endl;
    }

}