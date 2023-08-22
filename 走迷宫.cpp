#include<iostream>
#include<stack>
using namespace std;

typedef pair<int,int> PII;//构建坐标类型数据容器
const int N = 11;
int mapss[N][N],d[N][N];//mapss是地图，数组d是用来记录每个点是否已经走过
int n,flag;//n是地图大小，flag用来判断搜索是否结束

stack<PII> s,ans; 
void dfs(int xx,int yy)
{
    s.push({xx,yy});//将传入的坐标入栈
    d[xx][yy] = 1;//该点状态定义为已走
    if((xx == n-2 && yy == n-2))
    {
        //如果已经到达出口
        flag = 1;
        return;
    }
    int dx[] = {0,1,0,-1} , dy[] = {1,0,-1,0};//定义四个方向

        for(int i = 0 ; i < 4 ; i ++)
        {
            int x = xx + dx[i], y = yy + dy[i];
            if(x < n &&x >= 0 && y < n && y >=0 && mapss[x][y] == 0 && !d[x][y])
            {
                dfs(x,y);
                if(flag)return;//到达出口后回溯至此时，可以直接结束
            }
        }
    s.pop();//该点不可走时，弹出该点坐标
    
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> mapss[i][j];//创建迷宫
    //if(mapss[1][1] == 0)s.push({1,1});
    dfs(1,1);//从出口开始搜索

    //由于最终得到的栈的顺序是从入口至出口的，故需要将栈反转一下

    if(!s.size())cout << "NO";//如果最后栈空，表示路径不通

    while(s.size())
    {
        ans.push({s.top().first,s.top().second});
        s.pop();
    }
    while(ans.size())//反转后依次输出即可
    {
        cout << '(' << ans.top().first << ',' << ans.top().second << ')';
        ans.pop();
    }
    return 0;
}
