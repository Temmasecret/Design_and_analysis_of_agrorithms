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
int cmin=INF;
int Gtoiuu = INF;
int g;

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
            if ( cmin > Trongso[i][j]) {cmin = Trongso[i][j];}

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
    cout<<"Tong trong so min : "<<Gtoiuu;
}
void Try(int i) {
    for (int j = 2; j <= n; j++) {
        if (danhdau[j] == 1) {
            Thu[i] = j;
            TongTS[i] = TongTS[i - 1] + Trongso[Thu[i - 1]][Thu[i]];
            int g = TongTS[i] + (n - i + 1) * cmin;

            if (g < Gtoiuu) {
                danhdau[j] = 0;
                if (i == n) 
                {
                    int tong = TongTS[n] + Trongso[Thu[n]][1];
                    if (tong < Gtoiuu) 
                    {
                        Gtoiuu = tong;
                        for (int t = 1; t <= n; t++) Chot[t] = Thu[t];
                    }
                } 
                else 
                {
                    Try(i + 1);
                }
                danhdau[j] = 1; // QUAY LUI đúng
            }
        }
    }
}
void Try1( int i)
{
    for( int j = 2; j <= n; j++)
    {
        if( danhdau[j] == 1)
        {
            danhdau[j] = 0;
            Thu[i] = j;
            TongTS[i] = TongTS[i-1] + Trongso[ Thu[i-1] ][ Thu[i] ];
            if( Trongso[ Thu[i-1] ][ Thu[i] ] > 0 ) // phai noi duoc cai thanh pho lien truoc voi tp du dinh di hien tai
            {
                if( i == n )
                {
                    
                    if( TongTS[n] + Trongso[Thu[n]][1] < Gtoiuu )
                    {
                        //

                        Gtoiuu = TongTS[n] + Trongso[n][1];

                        //
                        for( int t = 1; t <= n; t++)
                        {
                            Chot[t] = Thu[t];
                        }
                    }
                }

                else
                
                {
                    g = TongTS[i]  + (n -i + 1)*cmin;
                    if( g < Gtoiuu) 
                    {
                        Try(i+1);
                    }
                }

                TongTS[i] -= Trongso[ Thu[i-1] ][ Thu[i] ];
                danhdau[ j ] = 1;
            }


        
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