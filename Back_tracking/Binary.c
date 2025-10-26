#include<stdio.h>
#define MAX 10000

int n;
int check[MAX];
int count = 0;

void Show_res()
{
    count++;
    printf("Count time %d : ",count);
    for (int i =0 ;i<n;i++)
    {
        printf("%d",check[i]);
    }
    printf("\n");
}

void Bin(int a)
{
    if (a == n) return Show_res();
    else
    {
        for (int i = 0;i<2;i++)
        {
            check[a] = i;
            Bin(a+1);
        }
    }
}

int main()
{
    printf("Nhap vao: ");
    scanf("%d",&n);
    Bin(0);
    return 0;
}