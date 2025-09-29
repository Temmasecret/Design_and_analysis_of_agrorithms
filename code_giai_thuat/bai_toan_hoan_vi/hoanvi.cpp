#include<iostream>
using namespace std;
#include<fstream>

int n ;
void input()
{
    fstream f1 ;
    f1.open("input.txt", ios::in);
    f1>>n;
}
int flag[100] = {0}; // danh dau gia tri n da duoc dung hay chua 
int a[100];

void hoanvi(int k) //k la vi tri chay tu 1 den n
{
    fstream f2 ;
    f2.open("output.txt", ios::app); 
    int i;
    if(k==n+1)
    {
        
        for( i = 1; i <= n; i++)
            f2<<a[i]<<" ";
        f2<<endl;
        return;
    } 

    for( i = 1; i <= n; i++)
    {
        if( !flag[i] )
        {
            a[k] = i;
            flag[i] = 1;
            hoanvi(k+1);
            flag[i] = 0;
        }
    }
}
int main()
{
    input();
    hoanvi(1);
}