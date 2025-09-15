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
        printf("Please sign the old pos, new pos and cost : ");
        scanf("%d %d %f", &oldpos, &newpos, &cost);
        printf("Do u want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &con);
    }
    float res_cost[6];
    for (int i = 0;i<6;i++)
    {
        res_cost[i] = 10000000000;
    }
    Node** res_way = (Node**)malloc(sizeof(Node*)*6);
    for (int i = 0;i<6;i++)
    {
        res_way[i] = MakeNode(i);
    }
    int idx =1;
    res_way[0] = Gr->lists[0];
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
        int min_pos = -1;
        float min_cost = 10000000000;
        Node* temp = Gr->lists[curr];
        while (temp->next != NULL)
        {
            if (visited[temp->pos] == 0 && temp->cost + res_cost[curr] < min_cost)
            {
                min_pos = temp->pos;
                min_cost = temp->cost + res_cost[curr];
            }
            temp = temp->next;
        }   
        InsertLast(min_pos, min_cost, res_way[curr]);
        visited[min_pos] = 1;
        res_cost[min_pos] = min_cost;
        idx++;
        curr = min_pos;
        if (curr == -1)
        {
            break;
        }
    }
    for (int i = 0;i<6;i++)
    {
        printf("Cost from 0 to %d is %.2f\n", i, res_cost[i]);
        Node* temp = res_way[i];
        printf("Path to %d: ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->pos);
            temp = temp->next;
        }
        printf("\n");
    }
}
/*
    20 0 1
    15 0 2
    80 0 4
    40 1 0
    10 1 4
    30 1 5
    20 2 0
    4 2 1
    10 2 5
    36 3 0
    18 3 1
    15 3 2
    90 4 2
    15 4 3
    45 5 2
    4 5 3
    10 5 4
*/