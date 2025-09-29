#include<iostream>
#include<fstream>
using namespace std;
int n;
float M;
struct MonDo
{
    char id[100];
    double w;
    double c;
    double ty_le;
};
MonDo Do[100];
void init()
{
    fstream f;
    f.open("input.txt", ios::in);
    if(!f) cout<<"Loi k mo duoc file.";
    f>>n;
    f>>M;
    int j,i;
    for( i = 0; i<n; i++)
    {
        f>>Do[i].id;
        f >>Do[i].w;
        f>>Do[i].c;
        Do[i].ty_le = Do[i].c / Do[i].w;
    }
    f.close();
}
void hoatdong()
{
    int j,i;
    MonDo tem;
    for( i = 0; i<n-1; i++)
    {
        for( j =i+1;j<n;j++)
        {
            if( Do[j].ty_le > Do[i].ty_le )
            {
                tem=Do[i];
                Do[i] = Do[j];
                Do[j] = tem;
            }
        }
    }
    cout<<"In ra thu tu cac mon do co ty le giam dan: \n";
    cout<<"ID"<<"\t\tTy le\n";
    for( i = 0; i<n; i++ )
    {
        cout<<Do[i].id<<"\t\t"<<Do[i].ty_le<<endl;
    }
    double sum=0;
    cout<<"in ra danh sach cac mon do trong tui:\n";
    cout<<"ID"<<"\t\tTy le"<<"\t\tNang"<<"\t\tGia tri\n";
    MonDo chon[100];
    int dem =0;
    for ( i = 0; i<n; i++)
    {
        if ( (sum + Do[i].w) <= M)
        {
            sum+= Do[i].w;
            
            chon[dem] = Do[i];
            dem++;
            cout<<Do[i].id<<"\t\t"<<Do[i].ty_le<<"\t\t"<<Do[i].w<<"\t\t"<<Do[i].c<<endl;
        }
    }
    fstream f2;
    f2.open("caitui.out", ios::out);
    dem--;
    for( i=0;i<dem;i++)
    {
        f2<<chon[i].id<<" ";
    }
    f2<<chon[dem].id;


}
int main()
{
    init();
    hoatdong();
}