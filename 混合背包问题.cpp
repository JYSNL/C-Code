#include<iostream>
#include<algorithm>  
#include<string.h>  
#include<string>   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define CRL(a) memset(a,0,sizeof(a))
#define M 100000000
typedef unsigned long long LL;
typedef  long long ll;
const int mod =1e9+7;

int V,dp[120002];

void ZeroOnePack(int cost,int valum)		//01背包问题
{
    for(int i=V;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]+valum);
    return; 
}

void CompletePack(int cost,int valum)		//完全背包问题
{
    for(int i=cost;i<=V;i++)
        dp[i]=max(dp[i],dp[i-cost]+valum);
    return;
}

void MultiplePack(int cost,int valum,int amount)	//多重背包问题
{
    if(cost*amount>=V)//注意这里！！！！！！！！！！！！！！！！！
        //如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
        CompletePack(cost,valum);
    else
    {
        int k=1;
        while(k<amount)
        {
            ZeroOnePack(cost*k,valum*k);//这里要调用01背包，但是要乘k
            amount-=k;
            k=k<<1; 	//k*=2
        }
        ZeroOnePack(cost*amount,valum*amount);//最后剩余一个amount
     }
    return; 
}

int main()
{
    int n,cost[1000],valum[1000],amount[1000];
    while(cin>>n>>V)
    {
        CRL(dp);
        for(int i=1;i<=n;i++)
            cin>>cost[i]>>valum[i]>>amount[i];
        
        for(int i=1;i<=n;i++)
            MultiplePack(cost[i],valum[i],amount[i]);
        
        cout<<dp[V]<<endl;
    }
    return 0;
}
