#include<iostream>
#include <fstream>
using namespace std;

int a[1005];
int n;
int bd;// vi tri bat dau cua day tong max
int kt; // vi tri bat dau cua day tong max
int bd_tem;// vi tri bat dau cua day con tam thoi dang xet
int maxS;// tong max
int maxT;// tong tam

void docDL()
{
    fstream fin;
    fin.open( "input5.txt",ios::in);
    if( !fin ) 
    {
        cout<<"Loi k mo duoc file.";
        return;
    }
    fin>>n;
    int i;
    
    for( i = 1; i <= n; i++)
    {
        fin>> a[i];
       
    }
    
    fin.close();

}

void hd()
{
    maxS=maxT=a[1];
    bd=kt=bd_tem=1;
    int i;
    for ( i = 2; i <= n; i++)
    {
        if (maxT <= 0)
        {
            maxT = a[i];
            bd_tem=i;
        }
        else
        {
            maxT += a[i];
        }
        if(maxS < maxT)
        {
            maxS = maxT;
            bd=bd_tem;
            kt =i;
        
        }
    }
    fstream fout;
    fout.open( "output.txt",ios::out);
    if( !fout ) 
    {
        cout<<"Loi k mo duoc file out.";
        return;
    }
    
    fout<<"\n"<<" Day con co tong lon nhat la: \n";
    for ( i = bd; i <= kt; i++)
    {
        if( i == bd ) 
        {
            fout<<a[i];
        }
        else fout<<" "<<a[i];
    }
    fout<<"\n Tong lon nhat la : "<< maxS;

    fout.close();

}
int main()
{
    docDL();
    hd();
}

