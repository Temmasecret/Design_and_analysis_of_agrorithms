#include<iostream>
using namespace std;
//dua ra tap con co k phan tu-> danh dau tap con co thu tu tu 1 den k
//c=[1,2,..,k]  max la [n-k+1; n-k+2,...,n]
/*thay
    while( i>=1 && c[i] == n-k+1) i--;
    if( i>=1)
    {
        c[i]++;i++;
        while(i<=k)
        {
            c[i] = c[i-1] +1
        }
    }
*/

void next( int c[], int k, int n )
{
    int i,j;
    // if( c[i] == (n-k+1) ) i--;
    // while( i >=1 )
    // {
    //     c[i]++;

    // }
    for( i = k; i >= 1; i++)
    {
        if( c[i] < (n-k+i) )
        {
            c[i]++;
            //i--;
            break;
        }
        //if( c[i] == (n-k+1) ) i--;
        else
        {
            for( int t = i-1; t >= 1 ; t--)
            {
                if(  c[t] < ( n-k+(t) ) ) // nếu vị trí i đã max, xét vị trí kề trước là i-1; nếu i-1 chưa max thì tăng gtr i-1 và set lại giá trị của các vtr sau i-11
                {
                    c[t]++;
                    c[i] = c[t]+1;
                    
                }
                break;
            }
            break;
        }
    }
}
int main()
{
    int n;
    cin>>n;
}
