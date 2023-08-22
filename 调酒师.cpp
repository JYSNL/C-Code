#include <iostream>
using namespace std;

int main()
{
    int klimit, swine;               //定义输入的每种酒上限klimit，酒的总量上限swine

    cin >> klimit >> swine;

    int v_wine1,v_wine2,v_wine3;    //定义三种酒的遍历初始条件1,2,3
    
    int count = 0;                  //总的方法count计数

    for ( v_wine1 = 0; v_wine1 <= klimit ; v_wine1++)            //对于第一种酒来说，从0到klimit进行遍历
    {
        if (v_wine1 > swine)                                    //第一种酒超过上限，立刻退出循环
        {
            break;
        }
        for ( v_wine2 = 0; v_wine2 <= klimit; v_wine2++)        //第二种酒也从0到klimit进行遍历
        {
            if(v_wine1+v_wine2 > swine)                         //如果和第一种酒加起来已经超过上限，退出循环
            {
                break;
            }
            if(swine - v_wine1 - v_wine2 <= klimit)             //判断剩下的第三种酒是否超过单种限制
            {
                count++;
                //cout << v_wine1 << ' ' << v_wine2 << ' ' << swine - v_wine1 - v_wine2 << '\n'; //输出满足条件的解
            }
        }
        
    }
    cout << count;
    return 0;
}
