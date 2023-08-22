#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int halveArray(vector<int>& nums) {
    priority_queue<double> pq;  // ���ȶ��У�Ĭ�ϴ󶥶�
    double sum = 0;             // ����Ԫ�غ�
    for(int i = 0 ; i <nums.size();i++){
        pq.push((double)nums[i]);   // ������Ԫ�ؼ������
        sum += nums[i];             // �ۼ�Ԫ�غ�
    }
    double target = sum / 2.0;  // Ŀ��ֵ�ǽ�Ԫ�غͼ���
    int count = 0;              // ��������
    double num;
    while(sum > target){
        num = pq.top() / 2.0;   // ÿ��ȡ����ǰ�����е����ֵ����
        pq.pop();
        sum -= num;             // Ԫ�غͼ��ټ����ֵ
        pq.push(num);           // ��������ֵ�ٷŻض�����
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
