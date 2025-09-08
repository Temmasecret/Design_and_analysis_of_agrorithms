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

int main()
{
    int cost_m[4] = {100,50,20,10};
    int* atm_Nhan = atm_recv(410,cost_m,4);
    for (int i = 0;i<4;i++)
    {
        printf("%d ",atm_Nhan[i]);
    }
    printf("\n");
    return 0;
}