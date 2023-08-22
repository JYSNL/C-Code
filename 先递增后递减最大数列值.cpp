#include<iostream>
#include<algorithm>  
#include<string.h>  
#include<string>   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
double a[550],b[550],dp1[550],dp2[550];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int mx=0;
		for(int i=0;i<n;i++)
		scanf("%lf",&a[i]);
		int pos;// 用于记录当前分割位置
		for(int k=0;k<n;k++){
		pos=k;
		int f=0;
		for(int i=n-1;i>=pos;i--)
		{
			b[f++]=a[i];  //将后半部分求递减数列部分逆置变为求递增数列便于理解
		}
		
		for(int i=0;i<=50;i++)
		dp1[i]=1;   //将dp数组内元素初始化为1，因为如果前面没有元素满足比它小（大）时，它本身算为一个长度
		int MAX1=1; //记录前一段数列中最长递增子序列的长度
		for(int i=0;i<=pos;i++)
		{
		    for(int j=0;j<i;j++)
			{
				if(a[i]>a[j])
				{
					dp1[i]=max(dp1[i],dp1[j]+1);  
//dp1[j]代表到j位置的数时最长的子序列长度，如果a[i]比a[j]长，那么此时dp[i]的最长子序列长度为dp[j]+1或者位置j之前更长的子序列
					if(dp1[i]>MAX1)
					MAX1=dp1[i];
				}
			}
		} 
		
		for(int i=0;i<=50;i++)
		dp2[i]=1;
		int MAX2=1;
		for(int i=0;i<f;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(b[i]>b[j])
				{
					dp2[i]=max(dp2[i],dp2[j]+1);   //同上
					if(dp2[i]>MAX2) 
					MAX2=dp2[i];
				}
			}
		}
		
		if(MAX1+MAX2>mx)
		mx=MAX1+MAX2;       //记录下最长的两部分子序列长度和
		}
		printf("%d\n",n+1-mx);  //由于有重复部分故需+1
	}
	return 0;
}
