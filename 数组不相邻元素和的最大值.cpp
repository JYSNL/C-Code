#include<iostream>
#include<algorithm>  
#include<string.h>  
#include<string>   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int max_two(int a,int b){
    return a>b?a:b;
}
int getMaxSum(int arr[] ,int n) {
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        if(n == 2) return max_two(arr[0], arr[1]);
        if(n == 3) return max_two(arr[1], arr[0] + arr[2]);
        int p[n];
        p[0] = arr[0];
        p[1] = arr[1];
        p[2] = arr[0] + arr[2];
        for(int i = 3; i < n; i++) {
            p[i] = arr[i] + max_two(p[i-2], p[i-3]);
        }
        return max_two(p[n-1],p[n-2]);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    if(n==0){
        cout << 0;
        return 0;
    }
    else if(n == 1){
        cout << a[0];
        return 0;
    }
    else{
    int b[n-1],c[n-1];			//b is no first. c no last
    for(int i = 1; i < n ; i++){
    	b[i-1] = a[i];
	}
	for(int i = 0 ; i < n-1;i++){
		c[i] = a[i];
	}
	int sum1 = getMaxSum(b,n-1);
    int sum2 = getMaxSum(c,n-1);
    int sum = max_two(sum1,sum2);
    cout << sum;
    return 0;
    }
}
