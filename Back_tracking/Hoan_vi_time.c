#include<stdio.h>
#define MAX 10000

int res[MAX];
int n;
int count = 0;
int check[MAX];

void Show_res()
{
    count++;
    printf("Time part %d : ",count);
    for (int i = 0; i< n;i++)
    {
        printf("%d",res[i] + 1);
    }
    printf("\n");
}

void init()
{
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
    {
        check[i] = 0;
        res[i] = 0;
    }
}

void Hoan_vi(int a)
{
    if (a == n) return Show_res();
    for (int i = 0; i<n;i++)
    {
        if (check[i] == 0)
        {
            check[i] = 1;
            res[a] = i;
            Hoan_vi(a+1);
            check[i] = 0;
        }
    }
}

int main()
{
    init();
    Hoan_vi(0);
    return 0;   
}