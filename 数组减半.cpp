#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int halveArray(vector<int>& nums) {
    priority_queue<double> pq;  // 优先队列，默认大顶堆
    double sum = 0;             // 数组元素和
    for(int i = 0 ; i <nums.size();i++){
        pq.push((double)nums[i]);   // 将数组元素加入队列
        sum += nums[i];             // 累加元素和
    }
    double target = sum / 2.0;  // 目标值是将元素和减半
    int count = 0;              // 操作次数
    double num;
    while(sum > target){
        num = pq.top() / 2.0;   // 每次取出当前数组中的最大值减半
        pq.pop();
        sum -= num;             // 元素和减少减半的值
        pq.push(num);           // 将减半后的值再放回队列中
        count++;
    }
    return count;
}


int main(){
	int nums[5];
	for(int i = 0 ;i < 5 ; i++){
		nums[i] = i*3+5;
	}
	int count = halveArray();
	cout<<count;
	return 0;
}
