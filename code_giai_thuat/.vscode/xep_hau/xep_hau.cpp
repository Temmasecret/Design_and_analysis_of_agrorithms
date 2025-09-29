#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxx 1001
int n; // ban co n*n
int TH = 0;
int kq[maxx];
int danhdau[maxx];
int cheo_thuan[maxx]; // tu trai xuong phai, i+j chay tu 2->2n
int cheo_nghich[maxx]; //  tu phai sang trai, i - j chay tu 1-n den n-1 => cong them n de tranh am
// 3 mang tren neu la 1 dong thoi thi co the xep hau vao, con neu la 0 thi k duoc

void init()
{
    int i;
    for( i =1; i<=2*n +1; i++)
    {
        danhdau[i] = 1;
        cheo_thuan[i] = 1;
        cheo_nghich[i] = 1;
    }
}
void in()
{
    fstream fout;
    
    fout.open("output1.txt", ios::app);
    fout<<"\n \t\t n = "<<n;
    fout<<"\n";
    TH++;
    fout<<"TH "<<TH<<":  ";
    for( int i = 1; i <= n; i++)
    {
        fout<<kq[i]<<" "; // chay lan luot vi tri tung hang
    }
    fout.close();
}
void xephau( int i )
{
    for( int j = 1; j <= n; j++)
    {
        if( danhdau[j] && cheo_nghich[i-j + n] && cheo_thuan[i+j])
        {
            danhdau[j] = 0;
            cheo_nghich[i-j + n] = 0;
            cheo_thuan[i+j] = 0;

            kq[i] = j; // hau o hang i, cot j;

            if( i != n)
            {
                xephau(i+1);
            }
            else
            {
                in();
            }

            danhdau[j] = 1;
            cheo_nghich[i-j + n] = 1;
            cheo_thuan[i+j] = 1;
            
        }
    }
}


int main()
{
    
    cout<<"Nhap n: "; cin>>n;
    init();
    xephau(1);
}