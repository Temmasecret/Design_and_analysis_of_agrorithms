#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct ptu
{
    int d1;
    int d2;
    int trongso;
};
ptu Ptu[100];
int socanh, sodinh;

void init()
{
    fstream f;
    f.open("input.txt", ios :: in);
    if ( !f ) cout<<"loi";
    f >> socanh;
    f >> sodinh;
    int i;
    for ( i = 0; i < socanh; i++)
    {
        f >> Ptu[i].d1;
        f >> Ptu[i].d2;
        f >> Ptu[i].trongso;
    }
}
void hd()
{
    ptu tem;
    int i,j;
    for ( i = 0; i < socanh-1 ; i++)
    {
        for ( j = i+1 ; j < socanh; j++)
        {
            if ( Ptu[i].trongso > Ptu[j].trongso)
            {
                tem = Ptu[j];
                Ptu[j] = Ptu[i];
                Ptu[i] = tem;
            }
        }
    }
    int daxet[100], sum = 0;
    cout<<"\n Khung cay theo thuat toan KrusKal la: \n ";
    cout<<"\t"<<Ptu[0].d1<<" - "<<Ptu[0].d2<<"\t:Trong so: "<<Ptu[0].trongso;
    i = 1; sum+=Ptu[0].trongso;
    daxet[ Ptu[0].d1 ] = 1; daxet[ Ptu[0].d2 ] = 1;
    int count = 1;
    while (  count < socanh )
    {
        if ( daxet[Ptu[i].d1] == 1 && daxet[Ptu[i].d2] == 1)
            i++;
        else
        {
            cout<<"\n\t"<<Ptu[i].d1<<" - "<<Ptu[i].d2<<"\t:Trong so: "<<Ptu[i].trongso;
            sum+=Ptu[i].trongso;
            daxet[Ptu[i].d1] = 1;
            daxet[Ptu[i].d2] = 1;
            i++;
            count++;
        }
    }
}
int main()
{
    init();
    hd();
}