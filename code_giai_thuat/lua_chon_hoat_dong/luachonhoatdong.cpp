#include<iostream>
#include<fstream>
using namespace std;
int n;
struct hoat_dong
{
    char id[100];
    int start;
    int end;
};
hoat_dong hd[100];

void init()
{
    fstream f;
    f.open("Input.txt", ios::in);
    if(!f) cout<<"Loi khong the mo tep.";
    f>>n;
    int i;
    for ( i=0; i<n;i++)
    {
        f>> hd[i].id;
        f>> hd[i].start;
        f>> hd[i].end;

    }
    f.close();
}
void lc()
{
    hoat_dong tem;
    int i, j;
    for( i = 0; i < n-1; i++)
    {
        for( j = i+1 ; j<n; j++)
        {
            if( hd[j].end < hd[i].end)
            {
                tem = hd[i];
                hd[i] = hd[j];
                hd[j] = tem;
            }
        }
    }
    cout<<"------------------";
    cout<<"Cac hoat dong duoc sap xep theo thu tu tang dan cua thoi gian ket thuc: \n";
    cout<<"\t Hoat dong"<<"\t Bat dau"<<"\t Ket thuc\n";
    for( i = 0; i<n; i++)
    {
        cout<<"\t"<<hd[i].id<<"\t"<<hd[i].start<<"\t"<<hd[i].end<<endl;   
    }
    cout<<"------------------------\n";
    cout<<"\t Hoat dong"<<"\t Bat dau"<<"\t Ket thuc\n";
    cout<<"\t"<<hd[0].id<<"\t"<<hd[0].start<<"\t"<<hd[0].end<<"\n";
    j=0;
    for ( i = 1; i<n; i++)
    {
        if( hd[j].end <= hd[i].start)
        {
            cout<<"\t"<<hd[i].id<<"\t"<<hd[i].start<<"\t"<<hd[i].end<<endl;
            j = i;
        }
    }
}
int main()
{
    init();
    lc();
}