#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int count = 0;
int n,ans[100],flag[100]; //输入数，结果数组，标记数组 
//判断两个数的和是不是素数函数 
int prime(int x, int y)
{
    int k=2, i=x+y;
    while(k<=sqrt(i) && i%k!=0)
        k++;
    if(k>sqrt(i))
        return 1;
    else
        return 0;    
}
//打印输出函数
int print()
{
	int i = 1;
    for(;i<n;i++)
        cout<<ans[i]<<" ";
    cout << ans[i];
    cout<<endl;    
} 
//搜索回溯算法
int search(int k)
{
    int i;
    for(i=1;i<=n;i++) //n个数 
        if( prime(ans[k-1],i) && (flag[i]==0)) //判断与前一个数是否构成素数及这个数当前是不是可用     
        {    ans[k]=i;
            flag[i]=1; //标记当前这个数使用过了 
            if(k==n) //到达边界 
            {
				if( prime(ans[n],ans[1]) && ans[1]==1) //严重最后一个和第一个 
                    print();
            }
            else
                search(k+1);
            flag[i]=0; 
    }
} 
int main()
{
    
    while(~scanf("%d",&n))
    {
    	count++;
    	printf("Case %d:\n",count);
    	search(1); //从第一个位置开始找 
    	cout << endl;
	}	
    
    return 0;
}
