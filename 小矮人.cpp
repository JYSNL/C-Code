#include <iostream>
using namespace std;

int calculates(int t[] , int n)
{
    int count = 0; //保存计算所得值
    int border_l;   
    int border_r;       //对于t[]中某一项的左右管辖范围
    int temp;                       //对每次循环的最小值进行存储
    for (int i = 0; i < n; i++)
    {
        border_l = i-1;
        border_r = i+1;

        if(i==0){
            while(t[border_r] > t[i])
            {
                border_r++;
            }
            count += (i-border_l)*(border_r-i)*t[i];
        }

        else if (i == n-1)
        {
            while (t[border_l] > t[i])
            {
                border_l--;
            }
            count += (i-border_l)*(border_r-i)*t[i];
        }

        else
        {
            while (t[border_l] > t[i])
            {
                border_l--;
            }
            while (t[border_r] > t[i])
            {
                border_r++;
            }
            count += (i-border_l)*(border_r-i)*t[i];
        }
    }
    return count;
}

int main(){
    int N_lm;   //小矮人数量
    cin >> N_lm;
    int tall_lm[N_lm];     //身高数组

	for(int i = 0 ; i < N_lm ; i++)
	{
		cin >> tall_lm[i];
	}
    int cal_height;
    cal_height = calculates(tall_lm,N_lm);
    cout<<cal_height;
    return 0;
}
