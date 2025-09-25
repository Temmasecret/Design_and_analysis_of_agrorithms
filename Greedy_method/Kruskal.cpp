// #include<bits/stdc++.h>
// using namespace std;

// typedef struct edge
// {
//     int x,y,w;
// }edge;

// bool cmp(edge a,edge b)
// {
//     return a.w < b.w;
// }

// void drawing_color()
// {
//     int n, m;
//     cin >> n>>m; // Số đỉnh và số cạnh 
//     vector <edge> lines;
//     for (int i = 0 ;i<m;i++)
//     {
//         edge e;
//         cin >> e.x >> e.y >> e.w;
//         lines.push_back(e);
//     }
//     vector <int> color(n+1);
//     for (int i = 1; i<=n;i++) color[i] = i;
//     sort(lines.begin(), lines.end(), cmp);
//     int mst_weight = 0;
//     vector <edge> mst;
//     for (auto e : lines)
//     {
//         if (color[e.x] != color[e.y]) 
//         {
//             mst.push_back(e);
//             mst_weight += e.w;
//             int old_color = color[e.x];
//             int new_color = color[e.y];
//             for (int i = 1; i<=n ;i++)
//             {
//                 if (color[i] == old_color) color[i] = new_color;
//             }
//         }
//     }
//     cout << "MST weight = " << mst_weight << "\n";
//     for (auto e : mst)
//     {
//         cout << e.x << " " << e.y << " " << e.w << "\n";
//     }
// }

// int main()
// {
//     drawing_color();
// }

#include<bits/stdc++.h>
using namespace std;

typedef struct edge{
    int x,y,w;
}edge;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void Drawing_table()
{
    int n, m;
    cin >> n >> m; // Nhap so dinh va so canh
    vector<edge> lines;
    for (int i = 0; i<m;i++)
    {
        edge tg;
        cin >> tg.x >> tg.y >> tg.w;
        lines.push_back(tg);
    }
    sort(lines.begin(), lines.end(),cmp);
    vector<int> color(n+1);
    for (int i = 1;i<=n;i++) color[i] = i;
    int mst_weight = 0;
    vector<edge> mst;
    for (auto e : lines)
    {
        cout << e.x<<' '<<e.y<<endl;
        if (color[e.x] == color[e.y]) 
        {
            int old_color = color[e.x];
            int new_color = color[e.y];
            mst.push_back(e);
            mst_weight += e.w;
            for (int i = 1; i<= n;i++)
            {
                if(color[i] == old_color) color[i] = new_color;
            }
        }
    }
    cout << "The mst weight is "<< mst_weight << endl;
    for (auto e:mst)
    {
        cout<< e.x << " - "<<e.y<< " ( "<<e.w<<" ) "<<endl;
    }
}

int main()
{
    Drawing_table();
}