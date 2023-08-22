#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

const int M = 60;

int bus[M];
int n;
vector<pair<int, PII>> routes;

bool is_route(int a, int b)
{
    for(int i = a; i < 60; i += b)
    {
        if(!bus[i]) return false;
    }
    
    return true;
}

bool dfs(int depth, int u, int sum, int start) //剪枝一
{
    if(u == depth) return sum == n;
    if(routes[start].first * (depth - u) + sum < n) return false; //剪枝3
    
    for(int i = start; i < routes.size(); i++) //注意：搜索的是路径
    {
        auto r = routes[i];
        int dist = r.first;
        int a = r.second.first, d = r.second.second;
        if(!is_route(a, d)) continue;
        for(int k = a; k < 60; k += d) bus[k]--;
        if(dfs(depth, u + 1, sum + dist, i)) return true;
        for(int k = a; k < 60; k += d) bus[k]++;
    }
    
    return false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        bus[t]++;
    }
    
    for(int i = 0; i < 60; i++) //枚举起点
    {
        for(int j = i + 1; i + j < 60; j++) //枚举公差
        {
            if(is_route(i, j))
            {
                routes.push_back({(59 - i)/ j + 1, {i, j}}); //覆盖点数 + 路线
            }
        }
    }
    
     sort(routes.begin(), routes.end(), greater<pair<int, PII>>()); //剪枝2

    
    int depth = 0;
    while(!dfs(depth, 0, 0, 0)) depth++;
    
    cout << depth << endl;
    
    return 0;
}



