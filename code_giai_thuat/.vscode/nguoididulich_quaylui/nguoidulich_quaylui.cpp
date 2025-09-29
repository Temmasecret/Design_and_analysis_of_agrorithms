#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
#define maxE 1000
#define INF 99999

int Trongso[MAX + 1][MAX+1]; // TRONG SO TU I DEN J
int Thu[MAX+2];
int Chot[MAX+2];
int TongTS[MAX + 1];// tong trong so tinh den thanh pho thu i
int danhdau[MAX + 1];// danh dau thanh pho i da di qua chua, 1 la chua, 2 la r
int minTongTS;
int m,n;

void nhapDL()
{
    int i,j;
    fstream fin;
    fin.open("input1.txt", ios::in);
    fin >> n;
    for( i = 1; i<=n; i++)
    {
        for( j = 1; j<=n; j++)
        {
            fin >> Trongso[i][j];
            cout<< Trongso[i][j] << " ";
        }
        cout<<"\n";
    }
    fin.close();
}
void init()
{
    for( int i = 1; i<=n; i++)
    {
        danhdau[i] = 1;
    }
    danhdau[1]= 0;
    Thu[1]=1;
    TongTS[1]=0;
    minTongTS = INF;

}
void in()
{
    for( int i =1; i <=n ; i++)
    {
        cout<<Chot[i]<<" -> ";
    }
    cout<<" 1.";
    cout<<"Tong trong so min : "<<minTongTS;
}
void Try(int i)
{
    for (int j = 2; j <= n; j++)
    {
        if (danhdau[j] == 1 && Trongso[Thu[i-1]][j] > 0)
        {
            danhdau[j] = 0;
            Thu[i] = j;
            TongTS[i] = TongTS[i - 1] + Trongso[Thu[i - 1]][Thu[i]];

            if (i == n)
            {
                if (Trongso[Thu[n]][1] > 0) // phải quay về được
                {
                    int tong = TongTS[n] + Trongso[Thu[n]][1];
                    if (tong < minTongTS)
                    {
                        minTongTS = tong;
                        for (int t = 1; t <= n; t++)
                            Chot[t] = Thu[t];
                    }
                }
            }
            else
                Try(i + 1);

            danhdau[j] = 1; // Quay lui
        }
    }
}


int main()
{
    nhapDL();
    init();
    Try(2);
    in();
}