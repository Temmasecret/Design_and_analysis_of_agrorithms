#include<stdio.h>

int board[9][9];
int x_s = 0;
int y_s = 0;
void init()
{
    for (int i = 0;i<9;i++)
    {
        for (int j = 0 ; j< 9;j++)
        {
            scanf("%d",&board[i][j]);
        }
    }
}

int checkrow(int value, int row)
{
    for (int i = 0; i<9;i++)
    {
        if (value == board[row][i] && board[row][i] !=0) 
        {
            return 0;
        }
    }
    return 1;
}

int checkcol(int value, int col)
{
    for (int i = 0; i<9;i++)
    {
        if (value == board[i][col] && board[i][col] != 0) return 0;
    }
    return 1;
}

int checkbox(int value, int row, int col)
{
    while (row%3!=0) row--;
    while (col%3!=0) col--;
    for (int i = row; i<row+3;i++)
    {
        for (int j = col; j<col+3;j++)
        {
            if (value == board[i][j] && board[i][j] !=0) return 0;
        }
    }
    return 1;
}

void show_res()
{
    printf("\n");
    for (int i =0 ;i<9;i++)
    {
        for (int j = 0;j<9;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}


void solve(int x, int y)
{
    if (y > 8) return show_res();
    // show_res();
    // printf("%d %d\n",x,y);
    // int x__;
    // scanf("%d",&x__);
    if (x == 9) return solve(0,y+1);
    if (board[x][y] !=0)
    {
        if (x < 8) return solve(x+1,y);
        else return solve(0,y+1);
    }
    for (int i = 1; i<= 9;i++)
    {
        // printf("%d %d %d %d %d %d\n",checkrow(i,y),checkcol(i,x),checkbox(i,x,y),i,x,y);
        // scanf("%d",&x__);
        if (checkrow(i,x) == 1 && checkcol(i,y) == 1 && checkbox(i,x,y) == 1)
        {
            board[x][y] = i;
            if (x <8) solve(x+1,y);
            else solve(0,y+1);
            board[x][y] = 0;
        }
    }
}

int main()
{
    init();
    solve(0,0);
    return 0;
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

*/