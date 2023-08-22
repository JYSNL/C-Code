 #include<iostream>
 #define x first
 #define y second

 using namespace std;

 typedef pair<int, int> PII;

 const int N = 200, M = N * N;
 int n, m;
 char g[N][N];
 bool st[N][N];
 PII q[M];

 int ddl1[4] = {0, -1, 0, 1}, ddl2[4] = {-1, 0, 1, 0};

 void flood(int sx, int sy){
     int p1 = 0, p2 = 0;
     q[0] = {sx, sy};
     st[sx][sy] = true;

     while(p1 <= p2){
         auto t = q[p1 ++];
        
        for(int i = 0; i < 4; ++i){
             int a = t.x + ddl1[i], b = t.y + ddl2[i];
             if(a < 0 || a >= n || b < 0 || b >= m) continue;
             if(st[a][b]) continue;
             if(g[a][b] == '0') continue;

             q[++ p2] = {a, b};
             st[a][b] = true;
         }
        
     }
 }

 int main(){
     cin >> n >> m;
     for(int i = 0; i < n; ++i) 
        cin >> g[i];

     int count = 0;
     for(int i = 0; i < n; ++i)
     {
         for(int j = 0; j < m; ++j)
         {
             if(!st[i][j] && g[i][j] != '0')
             {
                 ++ count;
                 flood(i, j);
             }
         }
     } 
     cout << count;
     return 0;
 }
