#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200;
int C,n;
int x[MAXN],bestK[MAXN];//�洢�ڵ����
int cw;//cw�洢��ǰ�ѷ��뱳��������
double bestv=-1,curv=0;//bestv�洢ȫ������ֵ��curv�洢��ǰ�ļ�ֵ
struct Knap{
    int num;//��Ʒ�����
    double weight;//������double�ſ��Խ��г����ıȴ�С
    double value;//��Ʒ�ļ�ֵ
};
Knap K[MAXN];
bool Compare(Knap a,Knap b){//��λ������ֵ�ߵ�����ǰ��
    return a.value/a.weight > b.value/b.weight;
}
double remainMaxValue(int k){//�����ѡ���k�Լ۱���Ʒʱ���п��ܵ�ʣ������ֵ
    int rw = C - cw;//����ʣ�������
    double b = curv;//��ǰ���еļ�ֵ
    while (k + 1 <= n && K[k + 1].weight <= rw) {//���������Ʒ�����������ƷС��ʣ��������������
        b += K[k + 1].value;//���¼�ֵ
        rw += K[k + 1].weight;//����ʣ������
        k = k + 1;//����һ����Ʒ�����ж�
    }
    if (k + 1 <= n) {//ʣ�������ѡ�񲿷���Ʒ
        b = b + K[k+1].value / K[k+1].weight * rw;
    }
    return b;
}
void Backtrack(int k){//�Ե�k�Լ۱ȵ���Ʒ��������
    if (k > n) {//���е���Ʒ��ѭ������
        if (curv > bestv) {
            bestv = curv;//��¼���ֵ
            for (int i = 1; i <= n; ++i) {
                bestK[i] = x[i];//���·������Ʒ���
            }
        }
    }
    else{
        if (cw + K[k].weight <= C) {//�����ǰ�����ŵ���Ʒ������(С�ڵ���)�����ŷ���
            x[K[k].num] = 1 ;//�ѵ�ǰ��ű��
            cw += K[k].weight;//���µ�ǰ����
            curv +=  K[k].value;//���µ�ǰ��ֵ
            Backtrack(k + 1);//������һ��
            cw -= K[k].weight;//��������
            curv -= K[k].value;//���˼�ֵ
        }
        if(remainMaxValue(k) > bestv){
            //�����ѡ���k�Լ۱ȵ���Ʒʱʣ������ֵ���Գ�����ǰ����ֵ���н�����һ���ı�Ҫ
            x[K[k].num] = 0;//��ѡ��k
            Backtrack(k + 1);//��һ��
       }
    }
    
}
int main(){
    cout << "���뱳���������C����Ʒ������Ŀn"<< endl;
    cin >> C >> n;
    cout << "����n����Ʒ���������ֵ" << endl;
    for (int i = 1; i <= n; ++i) {
        K[i].num = i;
        cin >> K[i].weight >> K[i].value;
    }
    sort(K + 1, K + n + 1,Compare);//�����Լ۱Ƚ�������
    Backtrack(1);//�Ӽ�������
    cout << "����ֵΪ" << bestv << endl;
    cout << "���뱳������Ʒ���" << endl;
    for (int i = 1; i <= n; ++i) {
        if (bestK[i] != 0) {
            cout << i << " ";
        }
    }
    return 0;
}


