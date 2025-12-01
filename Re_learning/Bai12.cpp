#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

typedef struct obj
{
    int w;
    int c;
}obj;

int Bag_size;
int num_obj;
obj vat_pham[MAX];

void init()
{
    cin >> num_obj >> Bag_size;
    for (int i = 1; i<= num_obj;i++)
    {
        cin >> vat_pham[i].w >> vat_pham[i].c;
    }
}

int Max_in_three(int a, int b, int c)
{
    if (a > b && a >c ) return a;
    else if (b > a && b>c ) return b;
    return c;
}

void Luachon()
{
    int Map[num_obj + 1][Bag_size + 1];
    for (int i =0 ;i<= num_obj;i++)
    {
        Map[i][0] = 0;
    }
    for (int i = 0;i<= Bag_size;i++)
    {
        Map[0][i] = 0;
    }
    for (int i = 1; i<= num_obj;i++)
    {
        for (int j = 1; j<= Bag_size ;j++)
        {
            int tg = 0;
            if (j >= vat_pham[i].w)
            {
                tg = Map[i-1][j - vat_pham[i].w] + vat_pham[i].c;
            }
            Map[i][j] = Max_in_three(Map[i-1][j],Map[i][j-1],tg);
        }
    }
    cout << "Max tien dem theo duoc la " << Map[num_obj][Bag_size]<<endl;
}

int main()
{
    init();
    Luachon();
    return 0;
}