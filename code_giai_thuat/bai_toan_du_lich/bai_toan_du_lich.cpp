#include<iostream>
#include<fstream>
using namespace std;

int n;
int a[100][100];
void init()
{
    fstream f;
    f.open("input1.txt", ios::in);
    if(!f) cout<<"Loi k mo duoc file";
    f >> n;
    int i,j ;
    for ( i =1; i<=n ; i++)
    {
        for( j= 1; j <=n; j++)
        {
            f >> a[i][j];
            if ( i == j) a[i][j] = 1000000;
            if ( a[i][j] == 0) a[i][j] = 1000000;
        }
    }
}
void hd()
{
    int d_bd; // diem bat dau
    int cost = 0; // tong trong so
    int i;
    int daxet[100];
    for ( i = 1; i<=n; i++)
    {
        daxet[i] = 0;
    }
    int dangxet;
    cout<<" Nhap gia tri diem bat dau: ";
    cin>> d_bd;
    cout<<" Chu trinh: "<<d_bd;
    int d_quaylai = d_bd;
    daxet[d_bd] = 1;
    int min = 1000;
    int dem = 1;
    while ( dem < n)
    {
        min = 1000000;
        for ( i = 1; i <=n; i++)
        {
            if ( !daxet[i] && min > a[d_bd][i]) // phai la dinh chua xet
            {
                    dangxet = i;
                    min = a[d_bd][i];
            }
        }
        cost+= a[d_bd][dangxet];
        daxet[dangxet] = 1;
        cout<<" -> "<<dangxet;
        d_bd = dangxet;

        dem++;
    }
    cout<<" -> "<<d_quaylai;
    cost += a[d_bd][d_quaylai];
    cout<<" \n cost: "<<cost;

}
int main()
{
    init();
    hd();
}