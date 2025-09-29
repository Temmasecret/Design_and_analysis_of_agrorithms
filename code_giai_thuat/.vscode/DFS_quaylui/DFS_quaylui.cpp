#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 50


int n;
int bd, kt;
int a[MAX][MAX] ; // luu matran
int daxet[MAX];
int truoc[MAX];

void nhapDL()
{
    fstream fin;
    fin.open("input1.txt", ios:: in);
    fin>>n;
    for( int i = 1; i <= n; i++)
    {
        for( int j = 1; j <= n; j++)
        {
            fin>>a[i][j];
        }
    }
}
void init()
{
    for( int i = 1; i <= n; i++)
    {
        daxet[i]= 0;
        truoc[i] = 0;
    }
}
void in(int bd, int kt)
{
    int i = kt;
    int path[MAX];
    int len = 0;

    while (i != bd)
    {
        path[len++] = i;
        i = truoc[i];
        if (i == 0) // không có đường đi
        {
            cout << "Khong co duong di tu " << bd << " den " << kt << endl;
            return;
        }
    }

    cout << bd;
    for (int j = len - 1; j >= 0; j--)
    {
        cout << " -> " << path[j];
    }
    cout << endl;
}

void in1(int bd, int kt)
{
    int i, j = 0;
    int tem[MAX];
    cout<<"\n";
    for( i = kt; i > bd; i--)
    {
        if( truoc[i] != bd)
        {
            tem[j] = truoc[i];
            j++;
        }
        
    }

    cout<< bd;
    for( i = j--; i >= 0 ; i--)
    {
        cout<<" -> " <<tem[i];

    }
    cout<<" -> "<<kt;
}
int tem ;
void DFS( int bd, int kt)
{
    daxet[bd] = 1;
    int u;
    for( u = 1; u <= n; u++)
    {
        if( daxet[u] == 0 && a[bd][u] != 0 )
        {
            truoc[u] = bd;
            if( u == kt  )
            {
                in(tem, kt);
            }

        
            else
            
                DFS ( u, kt);
                
            daxet[u] = 0;
            
        

        }
    }

}
int main()
{
    cout<<"Nhap bd: "; cin>>bd;
    cout<<"\n Nhap ket thuc: ";  cin>> kt;
    tem = bd;
    nhapDL();
    init();
    DFS( bd, kt);
    //in( bd, kt);
}