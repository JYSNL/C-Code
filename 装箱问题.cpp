#include <iostream>
using namespace std;
int V;   //�����ݻ� 
int n;   //�������� 
int a[31];	//��Ʒ��� 
int dp[20001] = {0};	//dp[i]��ʾ�����ݻ�Ϊiʱ�ɷ�����Ʒ����� 

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
