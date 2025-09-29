#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_LENGTH 1005

string X;
string Y;
int m,n; //m la chieu dai X, n la chieu dai Y
int c[MAX_LENGTH][MAX_LENGTH];//DO DAI XAU CON CHUNG
int b[MAX_LENGTH][MAX_LENGTH]; //TRUY VET
void docDL()
{
    fstream fin ;
    fin.open("input1.txt", ios::in);
    if( !fin )
    {
        cout<<"Loi k mo duoc input!";
        return;
    }

    getline(fin,X);
    getline(fin, Y);
    fin.close();

}
void hd()
{
    m=X.length();
    n = Y.length();
    int i,j;// i truc hoanh, j truc tung di xuong
    for( i = 0; i<= m; i++)
    {
        c[i][0] = 0;
    }
    for( j = 0; j <=n; j++)
    {
        c[0][j] = 0;
    }
    for ( i = 1; i<= m; i++)
    {
        for( j =1; j <= n; j++)
        {
            if( X[i-1] == Y[j-1]) 
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1; // lay cheo 
            }
            else 
            {
                if( c[i-1][j] > c[i][j-1] )
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 2 ;// sang ngang
                }
                else
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] =  3; // ha xuong
                }

            }
        }
    }


 int l = c[m][n]; // do dai cua chuoi con chung lon nhat
 char kq[l+1];
 kq[l] = '\0';
i =m; j = n;

fstream fout;
fout.open("output.txt", ios::out);
fout<<"Do dai chuoi con max : "<<c[m][n]<<"\n";
    while ( i > 0 && j > 0)
        {
            if ( b[i][j] == 1 )
            {
                kq[l-1] = X[i-1];
                i--;
                j--;
                l--;
            }
            else if( b[i][j] == 2 )
            {
                i--;
            }
            else
            {
               j--;
            }
        }

    fout<<kq;
    fout.close();

}

int main()
{
    docDL();
    hd();
}