#include<iostream>
#include<fstream>
using namespace std;
#define maxx 9999
int MAX_TEM[maxx][maxx] = {0};
int w[maxx] = {0}; int c[maxx] = {0};
int n,b; int danhdau[maxx] = {0} ;//danh dau do vat duoc chon

void nhapdl( )
{
    fstream fin;
    fin.open( "caitui5.txt",ios::in);
    if( !fin ) 
    {
        cout<<"Loi k mo duoc file.";
        return;
    }
    fin>>n>>b;
    int i;
    for( i = 1; i <= n; i++)
    {
        fin>> c[i];
    }
    for( i = 1; i <= n ; i++)
    {
        fin>>w[i];
    }
    fin.close();
}
void QHD()
{
    int i,L;
    for( i = 1; i <= n; i++)
    {
        for( L = 0; L <= b; L++)
        {
            MAX_TEM[i][L] = MAX_TEM[i-1][L];
            if ( L >= w[i] && ( MAX_TEM[ i-1 ][ L-w[i] ] + c[i] ) > MAX_TEM[i-1][L] )
            {
                MAX_TEM[i][L] = MAX_TEM[i-1][L-w[i]] + c[i];
            }
        }
    }

    // truy vet lai vat da chon0.
    i = n; L = b;
    while( i > 0 )
    {
        if( L >= w[i] &&  ( MAX_TEM[i-1][L-w[i]] + c[i] ) > MAX_TEM[i-1][L])
        {
            danhdau[i] = 1;
            L = L - w[i];
        }
        i--;
    }
    int sum = 0;
    for( i = 1; i <= n; i++)
    {
        if( danhdau[i] == 1 )
        {
            sum += c[i];
            cout<<" "<<i;
        }
    }
    cout<<endl<<"Tong gt tui la "<<sum;

}

int main()
{
    nhapdl();
    QHD();
}
