    #include<stdio.h>
    #include<iostream>
    #include<algorithm>
    #include<string.h>
    #include<math.h>
    using namespace std;
    typedef long long ll;
    int f[100];
    long long int INF=100000000000000000;//�趨���ֵ
    void sv(int n){
        f[1]=1;
        f[2]=3;
        for(int i=3;i<=n;i++){
            f[i]=INF;//f[i]����Ϊ���ֵ  �����߱Ƚ�
            for(int x=1;x<i;x++){
                if( (2*f[x]+pow(2,i-x)-1) <f[i])//С��f[i]�� �Ÿ���
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
