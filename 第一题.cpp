#include <iostream>
using namespace std;
#include <math.h>

int main(){
    int n;
    cin >> n;
    int a[n+1];
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];              //以1为起始坐标，得到所有箱子的信息
    }
    
    int tomato[n+1];
    for (int i = 1; i <= n; i++)
    {
        tomato[i] = 2;        //记录每个箱子是否有番茄酱（0无1有）
    }
    
    int temp;     //用于暂存信息

    int whe = 0;  //记录是否有输出

    int i, j, k;   //循环变量

    int x1,x2;    //输出的两个箱子坐标
	
    for (i = 1; i < n; i++)   
    {
        for(j = i + 1 ; j <= n ; j++){//遍历每两个箱子的信息令其为错，检验是否成立
            if(a[i]<0){   //小于零说明该信息指向箱子有番茄酱
                temp = abs(a[i]);
                tomato[temp] = 1;
            }
            else{     //大于零则该信息指向箱子无番茄酱
                temp = a[i];
                tomato[temp] = 0;
            }
            if(a[j] < 0){
                temp = abs(a[j]);
                tomato[temp] = 1;
            }
            else{     
                temp = a[j];
                tomato[temp] = 0;
            }
        }
        for(k = 1 ; k <= n ; k++){
            if(k != i && k != j)        //剩下箱子的信息均为正确
            {
                if(a[k]<0){
                    temp = abs(a[k]);
                    if(tomato[temp] == 2 || tomato[temp] == 0){   //若进行二次修改且前后值不同则一定出错
                        tomato[temp] = 0;
                    }
                    else{
                        break;
                    }
                }
                else{
                    temp = a[k];
                    if(tomato[temp] == 2 || tomato[temp] == 1){   //若进行二次修改且前后值不同则一定出错
                        tomato[temp] = 1;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        for(k = 1 ; k <= n ; k++){
            if(tomato[k] == 0 || tomato[k] == 2){
                if(x1 < 0){
                    x1 = k;
                }
                else if(x2 < 0){
                    x2 = k;
                }
            }
        }
        if(x1 > 0 && x2 > 0){
            cout << x1 << " " << x2;
            whe = 1;
            break;
        }
    }
    
    if(whe!=1){
        cout << "No Solution";
    }

    return 0;
}
