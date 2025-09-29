#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    fstream fin ;
    fin.open("input5.txt", ios::out);
    int i;
    for( i = 0; i<1000; i++)
    {
        if( i <10)
            fin<< 'v';
        else fin<<'m';
    }
    fin<<"\n";
    for( i = 0; i<1000; i++)
    {
        if( i <15)
            fin<< 'm';
        else fin<<'v';

    }


}