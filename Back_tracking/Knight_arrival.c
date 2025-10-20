#include<stdio.h>
#define MAX 10000
int n;
int board[MAX][MAX];
int count = 0;

typedef struct Point{
    int x;
    int y;
}Point;

int check(Point test);
void init()
{
    for (int i = 0;i < 1000;i++)
    {
        for (int j = 0; j<1000; j++)
        {
            board[i][j] = 0;
        }
    }
    scanf("%d",&n);
    
}

int check(Point test)
{  
    // printf("%d %d %d\n",test.x,test.y,n);
    
    if (test.x >= n || test.y >=n || test.x <0 || test.y <0)
    {
        return 0;
    }
    if (board[test.x][test.y] != 0 ) return 0;
    return 1;
}

int check_all()
{
    for (int i = 0; i< n;i++)
    {
        for (int j = 0; j< n;j++)
        {
            if (board[i][j] == 0 ) return 0 ;
        }
    }
    return 1;
}

void Show_result()
{
    count++;
    printf("Part %d\n",count);
    for (int i = 0;i<n;i++)
    {
        for (int j = 0 ; j<n;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solve(Point start,int step)
{
    if (check_all() == 1) return Show_result();
    // Show_result();
    // printf("\n");
    // int haiz;
    // scanf("%d",&haiz);
    //setting up for all posible point
    //point 1
    Point p1;
    p1.x =  start.x+ 1;
    p1.y =  start.y +2;
    if (check(p1) == 1) 
    {
        board[p1.x][p1.y] = ++step;
        solve(p1,step);
        board[p1.x][p1.y] = 0;
        step--;
    }
    //point1
    Point p2;
    p2.x =  start.x +2;
    p2.y =  start.y +1;
    if (check(p2) == 1) 
    {
        board[p2.x][p2.y] = ++step;
        solve(p2,step);
        board[p2.x][p2.y] = 0;
        step--;
    }
    //point 3
    Point p3;
    p3.x =  start.x -1;
    p3.y =  start.y +2;
    if (check(p3) == 1) 
    {
        board[p3.x][p3.y] = ++step;
        solve(p3,step);
        board[p3.x][p3.y] = 0;
        step--;
    }
    Point p4;
    p4.x =  start.x -2;
    p4.y =  start.y +1;
    if (check(p4) == 1) 
    {
        board[p4.x][p4.y] = ++step;
        solve(p4,step);
        board[p4.x][p4.y] = 0;
        step--;
    }
    Point p5;
    p5.x =  start.x+ 1;
    p5.y =  start.y -2;
    if (check(p5) == 1) 
    {
        board[p5.x][p5.y] = ++step;
        solve(p5,step);
        board[p5.x][p5.y] = 0;
        step--;
    }
    Point p6;
    p6.x =  start.x +2;
    p6.y =  start.y -1;
    if (check(p6) == 1) 
    {
        board[p6.x][p6.y] = ++step;
        solve(p6,step);
        board[p6.x][p6.y] = 0;
        step--;
    }
    Point p7;
    p7.x =  start.x- 1;
    p7.y =  start.y -2;
    if (check(p7) == 1) 
    {
        board[p7.x][p7.y] = ++step;
        solve(p7,step);
        board[p7.x][p7.y] = 0;
        step--;
    }
    Point p8;
    p8.x =  start.x -2;
    p8.y =  start.y -1;
    if (check(p8) == 1) 
    {
        board[p8.x][p8.y] = ++step;
        solve(p8,step);
        board[p8.x][p8.y] = 0;
        step--;
    }
}

int main()
{
    init();
    Point begin;
    int first_x;
    int first_y;
    scanf("%d %d",&first_x,&first_y);
    begin.x = first_x;
    begin.y = first_y;
    while (check(begin) == 0)
    {
        scanf("%d %d",&first_x,&first_x);
    }
    board[first_x][first_y] = 1;
    solve(begin,1);
    return 0;
}