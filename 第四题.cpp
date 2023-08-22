    #include<stdio.h>
    #include<iostream>
    #include<algorithm>
    #include<string.h>
    #include<math.h>
    using namespace std;
    typedef long long ll;
    int f[100];
    long long int INF=100000000000000000;//设定最大值
    void sv(int n){
        f[1]=1;
        f[2]=3;
        for(int i=3;i<=n;i++){
            f[i]=INF;//f[i]先置为最大值  方便后边比较
            for(int x=1;x<i;x++){
                if( (2*f[x]+pow(2,i-x)-1) <f[i])//小于f[i]的 才更新
                    f[i]=2*f[x]+(int)pow(2,i-x)-1;
            }
        }
    }
    int n;
    int main(){
        sv(65);
        while(~scanf("%d",&n)){
            printf("%d\n",f[n]);
        }
    }
