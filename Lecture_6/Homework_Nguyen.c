#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* atm_recv(int money, int cost_m[], int num_past)
{
    int *Num_pass  = (int*)malloc(sizeof(int)*num_past);
    memset(Num_pass, 0, sizeof(int)*num_past);
    int i = 0;
    while (money > 0)
    {
        Num_pass[i] = money / cost_m[i];
        money = money % cost_m[i];
        i++;
    }
    return Num_pass;
}

void Swap(int *a, int *b)
{
    int tg = *a;
    *a = *b;
    *b = tg;
}

void Heapify(int arr[],int l,int r,int idx)
{
    int num1 = 2*idx + 1;
    int num2 = 2*idx + 2;
    if (num1 <= r) 
    {
        Heapify(arr,l,r,num1);
        if (arr[num1] > arr[idx])
        {
            Swap(&arr[idx],&arr[num1]);
        } 
        
    }
    if(num2 <= r)
    {
        Heapify(arr,l,r,num2);
        if (arr[num2] > arr[idx])
        {
            Swap(&arr[idx],&arr[num2]);
        }
        
    }
}

void Heap_sort(int arr[],int l,int r)
{
    for (int i = r;i>=l;i--)
    {
        Heapify(arr,l,i,l);
        Swap(&arr[i],&arr[l]);
    }
}

typedef struct Node Node;
struct Node
{
    int pos;
    float cost;
    Node *next;
};

Node* MakeNode(int pos)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->pos = pos;
    temp->cost = 10000000000;
    temp->next = NULL;
    return temp;
}

void Makeline(float cost, Node** begin, Node** end)
{
    if (begin == NULL || end == NULL)
    {
        return;
    }
    (*begin)->cost = cost;
    (*begin)->next = (*end);
}

void InsertLast(int newpos, float cost, Node* temp)
{
    Node* newbie = MakeNode(newpos);
    Node* run = temp;
    while (run->next !=NULL)
    {
        run = run->next;
    }
    Makeline(cost,&run,&newbie);
}

typedef struct Graph{
    int size;
    Node** lists;
}Graph;

Graph* InitGraph(int size)
{
    Graph* Newbie = (Graph*)malloc(sizeof(Graph));
    Newbie->size = size;
    Newbie->lists = (Node**)malloc(sizeof(Node*)*size);
    for (int i = 0;i<size;i++)
    {
        Newbie->lists[i] = MakeNode(i);
    }
    return Newbie;
}

void Push_Graph(int oldpos,int newpos,Graph** Gr,float cost)
{
    Node* temp = (*Gr)->lists[oldpos];
    InsertLast(newpos,cost,temp);
}

int main()
{
    Graph* Gr = InitGraph(6);
    int con = 1;
    while(con)
    {
        int oldpos, newpos;
        float cost;
        //printf("Please sign the old pos, new pos and cost : ");
        scanf("%f %d %d", &cost, &oldpos, &newpos);
        InsertLast(newpos,cost,Gr->lists[oldpos]);
        //printf("Do u want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &con);
    }
    float res_cost[6];
    for (int i = 0;i<6;i++)
    {
        res_cost[i] = 10000000000;
    }
    int idx =1;
    res_cost[0] = 0;
    int visited[6];
    int curr = 0;
    for (int i = 0;i<6;i++)
    {
        visited[i] = 0;
    }
    visited[curr] = 1;
    while (idx < 6)
    {
        Node* temp = Gr->lists[curr];
        int min_pos = curr;
        while (temp->next != NULL)
        {
            if (visited[temp->next->pos] == 0 && res_cost[temp->next->pos] > res_cost[curr] + temp->cost && temp->next->pos != curr )
            {
                //printf("%d %d %d\n",temp->next->pos,curr,idx);
                res_cost[temp->next->pos] = res_cost[curr] + temp->cost;
            }
            temp = temp->next;
        }
        temp = Gr->lists[curr];
        float Min_cost = 10000000;
        while (temp ->next!= NULL)
        {
            if (Min_cost > res_cost[temp->next->pos] && visited[temp->next->pos] == 0 )
            {
                Min_cost = res_cost[temp->next->pos];
                min_pos = temp->next->pos;
            }
            temp = temp->next;
        }
        curr = min_pos;
        visited[curr] = 1;
        idx++;
    }
    for (int i = 0;i<6;i++)
    {
        printf("%.2f ",res_cost[i]);
    }
}
/*
    20 0 1 1
    15 0 2 1
    80 0 4 1
    40 1 0 1
    10 1 4 1
    30 1 5 1
    20 2 0 1
    4 2 1 1
    10 2 5 1
    36 3 0 1
    18 3 1 1
    15 3 2 1
    90 4 2 1
    15 4 3 1
    45 5 2 1
    4 5 3 1
    10 5 4 0
*/