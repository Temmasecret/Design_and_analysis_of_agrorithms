#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxx 1001

int n;
int Ma[maxx+1][maxx+1];
int toado_x[] = {0,1, 2, 2, 1, -1, -2, -2, -1};
int toado_y[] = { 0, 2, 1, -1, -2, -2, -1, 1, 2};

void output()
{
    fstream fout;
    fout.open("output.txt", ios ::app);
    fout << "\n=============================\n";
    for(int j=n;j>=1;j--)
    {
        for(int i=1;i<=n;i++)
            fout<<Ma[i][j]<<" ";
        fout<<endl;
    }
    //getchar();
   
}

void madituan( int buoc, int x, int y)
{
    for( int i = 1; i<=8 ; i++ ) // 8 huong di
    {
        int xi = x + toado_x[i];
        int yi = y + toado_y[i];
        if( Ma[xi][yi] == 0 && 1 <= xi && xi <= n && 1 <=yi &&  yi <= n)
        {
            Ma[xi][yi] = buoc;
            if ( buoc < n*n)
            {
                madituan(buoc + 1, xi, yi);
            }
            else
            {
                output();
            }
            if( buoc != 1)
                Ma[xi][yi] = 0;
        }
    }
}
int main()
{
   // cout<<"Nhap n: "; cin>>n;
   n=6;
    for( int i = 0; i <= maxx; i++)
    {
        for( int j = 0; j <= maxx; j++)
            Ma[i][j] = 0;
    }
    madituan(1,1,1);
    return 0;
}
