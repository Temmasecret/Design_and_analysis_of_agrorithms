#include<iostream>
#include<fstream>
using namespace std;
int n;
float T;
struct MonDo
{
    int id;
    double w;
    double c;
    double ty_le;
    int num; // bang 0 or 1 
};
MonDo Do[1000];
int daxet_tem[1000] = {0};
float cur_val = 0;
float cur_w = 0;
float maxVal = 0, g, maxW = 0;
int sl;

void test()
{
    if( cur_val > maxVal)
    {
        maxVal = cur_val;
        maxW = cur_w;
        sl = 0;
        for( int i = 0; i<n; i++)
        {
            Do[i].num = daxet_tem[i];
            sl +=daxet_tem[i];
        }

    }
}
void init()
{
    fstream f;
    f.open("input1.txt", ios::in);
    if(!f) cout<<"Loi k mo duoc file.";
    f>>n;
    f>>T;
    int j,i;
    for( i = 0; i<n; i++)
    {
        f>>Do[i].c;
    }
    for( i = 0; i<n; i++)
    {
        f>>Do[i].w;
        
    }
    for( i = 0; i<n; i++)
    {
       
        Do[i].ty_le = Do[i].c / Do[i].w;
    }
    for( i = 0; i<n ; i++)
    {
        Do[i].id = i+1;
    }
    f.close();
}
void sx()
{
    MonDo Chon[1000];
    int dem;
    int j,i;
    MonDo tem;
    // sap xep theo thu tu giam dan ty le cua do vat
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
}

void Try( int k )
{
    for( int i = 0; i <= 1; i++)
    {
        if ( cur_w + i*Do[k].w  <= T)
        {
            cur_w += i*Do[k].w;
            cur_val += i*Do[k].c;
            daxet_tem[k] = i;

            if ( k == n && cur_w <= T)
            {
                test();
            }
            else
            {

                // tinh can tren
                g = cur_val + ( T - cur_w)*Do[k+1].ty_le;

                if ( g > maxVal)
                {
                    Try(k+1);
                }
            }

            cur_w -= i*Do[k].w;
            cur_val -= i*Do[k].c;
            daxet_tem[k] = 0;
        }
    }
}
void in()
{
    cout<<"Gia tri max : "<< maxVal;
    cout<<"\nKhoi luong sd la: "<<maxW;
    cout<<"\nTong so do vat la: "<< sl<<"\n Cac do vat la: \n";
    for( int i = 0; i<n; i++)
    {
        if( Do[i].num != 0 )
        {
            cout<<" "<<Do[i].id;
        }
    }
}
int main()
{
    init();
    sx();
    Try(0);
    in();
}