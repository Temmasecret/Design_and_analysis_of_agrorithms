#include<iostream>
#include<fstream>
using namespace std;

int n;
int a[100][100];
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
            if ( i == j  ||  a[i][j] == 0 ) a[i][j] = 10000;
        }
    }
    f.close();
}
void hd()
{
    int daxet[100];
    int i;
    for ( i = 1; i <= n; i++)
        daxet[i] = 0;
    int khoangcach[100];// kc cua quang duong tu diem bat dau den diem do
    for ( i = 1; i <= n; i++)
        khoangcach[i] = 10000;//khoi tao cho moi khoang cach deu la vo cuc
    int bd ;
    cout<<" Nhap diem bat dau: ";
    cin >> bd;
    int tem_print = bd;
    khoangcach[bd] = 0;
    daxet[bd] = 1;
    int j;
    int lientruoc[ 100 ];
    for( j = 1; j<=n;j++) lientruoc[j]=-1;// khoi taotao
    for ( j = 1; j <=n ; j++)
    {
        khoangcach[j] = a[bd][j]; // cap nhat trong so tu dinh bd den cac dinh ke
        //if ( khoangcach[j] > khoangcach[bd] + )
        if ( khoangcach[j] < 10000 && j != bd ) 
           lientruoc[j] = bd;
    }
    


    
    int count = 1; // da co diem dau tien
    while ( count < n )
    {
        int min = 10000;//tim min trg cac kc da co de lam diem bat dau moi
        int tem = bd;
        for( j = 1; j <=n; j++)
        {
            if ( !daxet[j] && khoangcach[j] < min)
            {
                min = khoangcach[j];
                bd = j;
            }
        }
        daxet[bd] = 1;
        for ( j = 1; j<=n; j++) // xac dinh xem khoang cach nao bi doi
        {
            if ( !daxet[j]  && khoangcach[j] > khoangcach[ bd ] + a[bd][j] )
            {
                khoangcach[j] = khoangcach[bd]  + a[bd][j];
                lientruoc[j] = bd;
            }
        }
        count++;
    }
    j = 1;
    while ( j <= n  )
    {
        
        if( lientruoc[j] == -1 ) { cout<<"\n k co duong di tu "<<tem_print<<" den "<<j<<endl; }
        else{
        cout<<"\n Duong di ngan nhat tu "<<tem_print<<" den "<<j<<" la: \n";
        int k = j;
        while( k!= tem_print)
        {
            cout<< k <<" <-- ";
            k=lientruoc[k]; 
        }
        cout<<tem_print;
        }
        j++;
    }
    

}
int main()
{
    init();
    hd();
}

//https://chidokun.github.io/2021/09/dijkstra-algorithm/  link thuat toan