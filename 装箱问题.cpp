#include <iostream>
using namespace std;
int V;   //箱子容积 
int n;   //物体数量 
int a[31];	//物品体积 
int dp[20001] = {0};	//dp[i]表示箱子容积为i时可放入物品的体积 

int main()
{
	int i,j;
	int t;
	cin >>V;
	cin>>n;
	
	for(i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	
	for(i = 0 ; i < n ; i++)
	{
		for(j = V ; j >= a[i] ; j--)
		{
			if(dp[j]>(dp[j-a[i]]+a[i]))
				dp[j] = dp[j];
			else
				dp[j] = dp[j-a[i]] + a[i];
		}
	}
	printf("%d",V-dp[V]);
	return 0;
}
