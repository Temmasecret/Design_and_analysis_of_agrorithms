#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;



#define MAX 1000
int n; // so dinh do thi
int a[MAX][MAX]; // dl ban dau
int d[MAX][MAX]; // danh dau khoang cach max
int p[MAX][MAX]; // danh dau duong di
void init()
{
    fstream f;
    f.open("input1.txt", ios::in);
    if(!f) 
    {
        cout<<"Loi k mo duoc file.";
        return;
    }
    f >>n;
    int i,j;
    for ( i = 1; i<=n; i++)
    {
        for ( j = 1; j <= n; j++)
        {    
            f>>a[i][j];
            if ( i != j  &&  a[i][j] == 0 )  
                {a[i][j] = MAX;}
        }
    }
    f.close();
}

void hd()
{
    int i,j,k;
    for ( i = 1; i <= n; i++)
    {
        for( j =1; j<=n ; j++)
        {
            d[i][j] = a[i][j];
            p[i][j] = 0;
        }
    }

    for( k = 1; k <= n; k++)
    {
        for( i = 1; i <=n ; i++)
        {
            if ( d[i][k] > 0 && d[i][k] < MAX)
            {
                for( j = 1; j<= n ; j++)
                {
                    if ( d[i][k] + d[k][j] < d[i][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        p[i][j] = k;
                    }
                }
            }
        }
    }
}
void in()
{
    int i,j;
    fstream fout;
    fout.open("output.txt", ios::out);
    int duongdi[n];
    
    for( i = 1; i <=n; i++)
    {
        for( j = 1; j <=n; j++)
        {
            int count = 0, cs = 0;
            int tem1 = j;
            if( d[i][j] == MAX || i==j)
            {
                continue;
            }
            cout<<"\n Duong di min tu "<<i<<" den "<<j<<" co tong trong so "<< d[i][j] <<" la: ";
            while( p[i][tem1] != 0)
            {
                duongdi[cs] = p[i][tem1];
                count++;
                tem1 = duongdi[cs];
                cs++;
            }
            cout<< i;
            for( int t = count-1; t >= 0; t--)
            {
                cout<<" "<< duongdi[t];
            }
            cout<<" "<< j;

        }
    }
}

int main()
{
    init();
    hd();
    in();
}