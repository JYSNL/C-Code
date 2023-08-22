#include<iostream>
#include<algorithm>  
#include<string.h>  
#include<string>   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int maxProfit(int prices[],int n ) {
       if(n==0) return 0;
        int max = 0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<=prices[i+1]){
                max += prices[i+1]-prices[i]; //if next > before,then max+ their -
            }
        }
        return max;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i <n ; i++)
    {
        cin >> a[i];
    }
    int sum = maxProfit(a,n);
    cout<<sum;
    return 0;
}
