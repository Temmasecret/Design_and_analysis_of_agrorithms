#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
double N;
double M;

typedef struct obj{
    int id;
    double w;
    double c;
    double tl;
}obj;

obj Vat_the[MAX];

void swap_obj(obj* a1,obj* a2)
{
    obj tg = *a1;
    *a1 = *a2;
    *a2 = tg;
}

void heapify(obj data[], int l ,int r, int idx)
{
    int idx1 = 2*idx +1;
    int idx2 = 2*idx +2;
    if (idx1 <= r)
    {
        heapify(data,l,r,idx1);
        if (data[idx1].tl > data[idx].tl)
        {
            swap_obj(&data[idx1], &data[idx]);
        }
    }
    if (idx2 <= r)
    {
        heapify(data,l,r,idx2);
        if (data[idx2].tl > data[idx].tl)
        {
            swap_obj(&data[idx2],&data[idx]);
        }
    }
}
void heap_sort_obj(obj data[], int l, int r)
{
    for (int i = r; i>=l;i--)
    {
        heapify(data,l,i,l);
        swap_obj(&data[l],&data[i]);
    }
}

void init()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i<N;i++)
    {
        cin >> Vat_the[i].id;
        cin >> Vat_the[i].w;
        cin >> Vat_the[i].c;
        Vat_the[i].tl = Vat_the[i].c / Vat_the[i].w;
    }
    heap_sort_obj(Vat_the,0,N-1);
}

int main()
{
    init();
    for (int i = 0; i<N;i++)
    {
        cout << Vat_the[i].id<<' ';
    }
    double sum_c = 0;
    double sum_w = 0;
    int idx = N-1 ;
    while (sum_w <= M && idx >= 0)
    {
        if (sum_w + Vat_the[idx].w <= M)
        {
            sum_w += Vat_the[idx].w;
            sum_c += Vat_the[idx].c;
            cout << "Chon "<<Vat_the[idx].id<<endl;
        }
        idx--;
    }
    cout << "Tong gia thu dc la: "<<sum_c<<endl;
    return 0;
}