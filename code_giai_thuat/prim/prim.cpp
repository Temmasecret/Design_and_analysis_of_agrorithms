#include<iostream>
#include<fstream>
#include<climits>
#include<algorithm>

using namespace std;

int n;
int a[100][100];
void init()
{
    fstream f;
    f.open("input.txt", ios::in);
    f >> n;
    int i,j;
    for ( i = 0; i < n ;i++)
    {
        for( j = 0; j < n; j++)
        {    
            f >> a[i][j]; 
            if( j == i ) a[i][j] = 0; // canh nao k ton tai thi gan bang 0
        }
    }
}
void  hd()
{
    int i,parent[100],daxet[100],kc[100];// kc[i] la khoang cach min tu dinh i den tap dinh da xet2
    int bd;
    cout<<"\n Nhap diem bat dau: "; cin>> bd; int sum = 0;
    cout<<"\n Khung cay theo thuat toan Prim la: \n ";
    for ( i = 0; i < n ; i++ )
    {
        kc[i] = INT_MAX;
        daxet[i] = 0;
    }
    kc[bd] = 0; // luc nay tap da xet chi co bd
    int con ;

    int count = 1;
    while ( count < n )
    {
        int min = INT_MAX;
        daxet[bd] = 1; 
        for ( i = 0; i < n; i++) //cap nhat lai khoang cach min tu cac dinh chua xet den tap da xet
        {
            if ( daxet[i] == 0 && a[bd][i] < kc[ i ] && a[bd][i] != 0 )
            {
                kc[i] = a[bd][i];
                parent[ i ] = bd;
                //con = i;
            }
        }
        for( i = 0; i <= n ; i++) // tim dinh co khoang cach den tap da xet min nhat
        {
            if ( daxet[i] == 0 && kc[i] < min )
            {
                min = kc[i];
                con = i;
            }
        }
        cout<<endl<<parent[con]<<"--"<<con<<"\t\t"<<a[parent[con]][con];
        sum+= a[parent[con]][con];
        bd = con;
        count++;
    }
    cout<<"\n Tong trong so la: "<<sum;
}
   
void hd2()
{
    int bd, dinhke, tongtrongso = 0;
    cout<< "Nhap diem bat dau: "; cin>>bd;
    int i,j, count_dx = 0;
    int daxet[100]; for( i = 0 ; i < n; i++) daxet[i] = -1;
    cout<<" Khung cay theo thuat toan prim la: \n";
    daxet[bd] = 1;
    int tap_dinhdx[100]; // vi prim la tim canh ngan nhat xuat phat tu tap dinh da xet
    tap_dinhdx[0] = bd;
    count_dx = 1;
    while ( count_dx < n)
    {

        
        int min = 100000;
        for ( j = 0; j< count_dx; j++)
        {
            for ( i = 0; i<n; i++)
            {
                if ( a[ tap_dinhdx[j] ][i] < min && a[ tap_dinhdx[j] ][i] != 0 && daxet[i] == -1 )
                {
                    dinhke = i;
                    bd = tap_dinhdx[j];
                    min = a[ tap_dinhdx[j] ][i];
                }
            }// het vong for la tim dc dinh ke gan nhat
        }
        tap_dinhdx[count_dx] = dinhke;
        tongtrongso += min;
        cout<<"\n" <<bd<<" _ "<<dinhke<<"\t\t Trong so: "<<min;
        daxet[dinhke] = 1;
        count_dx++;
    }
    cout<<"\n Tong trong so cua khung cay la: "<<tongtrongso;

}
int main()
{
    init();
    //hd();
    hd2();
}