#include<stdio.h>

typedef struct edge{
    int x;
    int y;
    float cost;
}edge;

void Swap_edge(edge* a, edge* b)
{
    edge tg = *a;
    *a = *b;
    *b = tg;
}

void Heapify(edge list[],int l, int r,int idx)
{
    int tg_1 = idx*2 + 1;
    int tg_2 = idx*2 + 2;
    if (tg_1 <= r)
    {
        Heapify(list,l,r,tg_1);
        if (list[tg_1].cost > list[idx].cost) Swap_edge(&list[tg_1],&list[idx]);
    }
    if (tg_2 <=r )
    {
        Heapify(list,l,r,tg_2);
        if (list[tg_2].cost > list[idx].cost) Swap_edge(&list[tg_2],&list[idx]);
    }
}

void Heap_sort(edge list[], int l, int r)
{
    for (int i = r;i>l;i--)
    {
        Heapify(list,l,i,l);
        Swap_edge(&list[i],&list[l]);
    }
}

int main()
{
    int n = 0;
    printf("Nhap so luong canh : ");
    scanf("%d",&n);
    edge list[n];
    for (int i = 0; i<n;i++)
    {
        scanf("%d %d %f",&list[i].x,&list[i].y,&list[i].cost);
    }
    Heap_sort(list,0,n-1);
    printf("Nhap vao so dinh: ");
    int k;
    scanf("%d",&k);
    int check[k];
    for (int i =0 ;i<k;i++)
    {
        check[i] = 0;
    }
    check[0] = 1;
    int closet[k];
    float cost_tg[k];
    float min_cost;
    for (int i =0; i<n;i++)
    {
        if (check[list[i].y] == 0)
        {
            closet[list[i].y] = list[i].x;
            min_cost += list[i].cost;
            cost_tg[list[i].y] = list[i].cost;
            check[list[i].y] = 1;
        }
        else if (check[list[i].x] == 0)
        {
            closet[list[i].x] = list[i].y;
            min_cost += list[i].cost;
            cost_tg[list[i].x] = list[i].cost;
            check[list[i].x] = 1;
        }
    }
    printf("Cay khung nho nhat co trong so %.2f \n",min_cost);
    printf("Cac canh : ");
    for (int i =1 ; i< k;i++)
    {
        printf(":%d .. %d : %.2f : ",i,closet[i],cost_tg[i]);
    }
    return 0;
}