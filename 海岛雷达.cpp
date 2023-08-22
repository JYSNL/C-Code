#include <iostream>
#include <vector>
#include<math.h>
#include<sstream>
#include <algorithm>  //find函数在此头文件
using namespace std;  //使用vector就要加这一行
 
//为岛屿坐标定义一个结构体
struct spot
{
    int x,y;
};
 
//用于岛屿排序，按岛屿横坐标从小到大排序
bool vv(const spot &a,const spot &b)
{
    return a.x < b.x;
}
 
int main()
{
    int n,d;
    int count=0; //记录这是第几组测试
    while(cin>>n>>d){
        if(n==0&&d==0) break;
 
        vector<spot> v(n); //定义一个动态数组v，里面每个元素是一个岛屿
        for(int i=0;i<n;i++){
            cin>>v[i].x>>v[i].y;
        }
        vector<int> aim; //定义目标数组，装有所有雷达横坐标，且里面雷达横坐标是从小到大排序的
        sort(v.begin(),v.end(),vv); //按岛屿横坐标将岛屿从小到大排序
 
        for(int i=0;i<n;i++){ //遍历每一个岛屿
 
            if(v[i].y>d){ //如果岛屿纵坐标大于雷达半径，则肯定不在雷达范围，输出-1
                cout<<-1<<endl;
                break;
            }
 
            if(i==0){  //根据第一个岛屿找第一个雷达位置
                int x0; //新雷达的横坐标
                if(v[i].x<0){  //当岛屿横坐标为负数，则令雷达坐标向上取整，如-2.3则取-3
                    x0 = v[i].x+sqrt(d*d-v[i].y*v[i].y)-1;
                    aim.push_back(x0);  //将雷达横坐标加入目标数组
                }else{  //当岛屿横坐标为正数，则令雷达横坐标向下取整，如2.3则取2
                    x0 = v[i].x+sqrt(d*d-v[i].y*v[i].y);
                    aim.push_back(x0);
                }
            }else{
                if((v[i].x-aim.back())*(v[i].x-aim.back())+v[i].y*v[i].y>d*d){ //如果目标数组中最后一个雷达与当前岛屿的距离大于雷达半径（说明该岛屿不在最后一个雷达范围中），则寻找下一个雷达
                    int x0;
                    if(v[i].x<0){
                        x0 = v[i].x+sqrt(d*d-v[i].y*v[i].y)-1;
                        aim.push_back(x0);
                    }else{
                        x0 = v[i].x+sqrt(d*d-v[i].y*v[i].y);
                        aim.push_back(x0);
                    }
                }
            }
        }
 
        count++;
        string b = "Case ";
        string a = ": ";
        stringstream ss;
        ss<<b<<count<<a<<aim.size(); //输出
        cout<<ss.str()<<endl;
 
    }
 
}