#include <iostream>
#include <vector>
#include<math.h>
#include<sstream>
#include <algorithm>  //find函数在此头文件
using namespace std;  //使用vector就要加这一行

int main(){
    
    int g;
    cin >>g;
    int k = 2*g;
    int a[k][2];         //初始化得到总的人数，二维为各自代价
    for(int i = 0 ;i < k  ;  i++){
        for(int j = 0 ;  j < 2 ; j++){
            cin >> a[i][j];
        }
    }                             //初始化数组
    int cmp[k];                    //存储两地花费的差值

    for(int i = 0 ; i < k ; i++){
        cmp[i] = a[i][0]- a[i][1];
    }

    int sum =0;
    while(g--)                      //选出差值前一半的人数去A地
    {
        int temp = 10000;
        int key = -1;
        for(int i = 0 ; i < k ; i++)
        {
            if(cmp[i]<temp)
            {
                temp = cmp[i];
                key = i;
            }
        }
    sum += a[key][0];
    cmp[key] = 100000;
    }
    for(int i = 0 ; i<k ; i++){
        if(cmp[i]!=100000){
            sum+= a[i][1];
        }
    }
    cout << sum;
    return 0;
}
