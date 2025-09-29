#include<iostream>
using namespace std;
//bài toán sinh tập con tương tự bài toán chuỗi nhị phân tăng dần, cộng 1, gặp 1 chuyển 0, gặp 0 chuyển 1 và dừng

int next( int c[], int n)
{
    int i = n-1;
    while( i>=0 && c[i] == 1)
    {
        c[i] = 0; 
        i--;
    }
    if( i >=0 ) c[i] = 1;

}
bool check(int c[], int n )
{
    int i,sum=0;
    bool result = false;
    for( i = 0; i<n; i++)
    {
        sum+=c[i];
    }
    if ( sum == n )
        result = true;
    return result;

}
int process( int a[],int c[], int n)
{
    int i,sum=0;
    for( i = 0; i<n; i++)
    {
        if( c[i] == 1)
            sum+=a[i];
    }
    return sum;
}
void in( int a[], int c[], int n)
{
    int i;
    cout<<endl;
    for( i = 0; i < n; i++)
    {
        if( c[i] == 1)
        {
            cout<<a[i]<<"  ";
        }
    }
    cout<<"\t\t\tSUM: "<<process(a,c,n);
}
int main()
{
    int c[100], n, a[100];

    cout<<"Nhap n: "; cin>>n;
    int i;
    cout<<"\n Nhap cac phan tu: \n ";
    for ( i = 0; i<n; i++)
    {
        cin>>a[i];
        c[i] = 0;
    }
    bool  lap = true;
    int max=0;
    next(c,n); //vi cai dau tien la chua chon gi nen cho next truoc de co 1 hoan vi
    while(lap)
    {
        in(a,c,n);
        if( max < process( a,c,n) )
        {
            max = process(a,c,n);
        }

        if(check(c, n))  
            lap = false;
        else next(c,n);
    }
    cout<<"\n\n Tong lon nhat trong day la: "<<max;
}