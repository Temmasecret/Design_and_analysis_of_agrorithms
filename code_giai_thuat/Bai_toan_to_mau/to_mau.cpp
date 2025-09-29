#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

int n, a[100][100];
void init()
{
    fstream f ;
    f.open("input.txt" , ios::in);
    if ( !f ) {
        cout<<"Loi k mo duoc file.";
        return;
    }
    f >> n;
    int i,j;
    for( i = 0; i < n; i++) // lay du lieu tu ma tran ke
    {
        for ( j = 0; j < n; j++)
        {
            f >> a[i][j];
        }
    }
}
void hd()
{
    int bd = 0,i,j=0,k,mau[100] = {0}, dato[100] = {0};
    mau[0] = j = 1;
    dato[0] = 1;
    
    //---
    for( i =0; i<n;i++)
    {
        int used[100] = { 0 };//danh dau mau nao da dung
        if( dato[i] != 1)
        {
            for( j = 0; j<n;j++)
            {
                if ( a[i][j] != 0 && dato[j] != 0 ) // tim mau cua dinh ke da dung va danh dau
                {
                    used[ mau[j] ] = 1;
                }
            }
            int color = 1;
            while (used[color] == 1)
            {
                color++;
            }
            mau[i] = color;
            dato[i] = 1;
        }
    }
//in
    cout<<"\n\tMau\t\tDinh";
    for( i = 0; i < n; i++)
    {
        cout<<"\n\t"<<mau[i]<<"\t\t"<<i;
    }
}
int main()
{
    init();
    hd();
}


