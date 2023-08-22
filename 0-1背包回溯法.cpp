#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200;
int C,n;
int x[MAXN],bestK[MAXN];//存储节点序号
int cw;//cw存储当前已放入背包的重量
double bestv=-1,curv=0;//bestv存储全局最大价值，curv存储当前的价值
struct Knap{
    int num;//物品的序号
    double weight;//必须是double才可以进行除法的比大小
    double value;//物品的价值
};
Knap K[MAXN];
bool Compare(Knap a,Knap b){//单位重量价值高的排在前面
    return a.value/a.weight > b.value/b.weight;
}
double remainMaxValue(int k){//求出不选择第k性价比物品时，有可能的剩余最大价值
    int rw = C - cw;//背包剩余的质量
    double b = curv;//当前已有的价值
    while (k + 1 <= n && K[k + 1].weight <= rw) {//如果还有物品，并且这个物品小于剩余的质量，则放入
        b += K[k + 1].value;//更新价值
        rw += K[k + 1].weight;//跟新剩余容量
        k = k + 1;//对下一个物品进行判断
    }
    if (k + 1 <= n) {//剩余的容量选择部分物品
        b = b + K[k+1].value / K[k+1].weight * rw;
    }
    return b;
}
void Backtrack(int k){//对第k性价比的物品进行搜索
    if (k > n) {//所有的物品都循环完了
        if (curv > bestv) {
            bestv = curv;//记录最大值
            for (int i = 1; i <= n; ++i) {
                bestK[i] = x[i];//更新放入的物品序号
            }
        }
    }
    else{
        if (cw + K[k].weight <= C) {//如果当前这个序号的物品不超重(小于等于)，试着放入
            x[K[k].num] = 1 ;//把当前序号标记
            cw += K[k].weight;//更新当前重量
            curv +=  K[k].value;//更新当前价值
            Backtrack(k + 1);//进入下一步
            cw -= K[k].weight;//回退重量
            curv -= K[k].value;//回退价值
        }
        if(remainMaxValue(k) > bestv){
            //如果不选择第k性价比的物品时剩余最大价值可以超过当前最大价值，有进行下一步的必要
            x[K[k].num] = 0;//不选择k
            Backtrack(k + 1);//下一步
       }
    }
    
}
int main(){
    cout << "输入背包最大容量C，物品种类数目n"<< endl;
    cin >> C >> n;
    cout << "输入n件物品的重量与价值" << endl;
    for (int i = 1; i <= n; ++i) {
        K[i].num = i;
        cin >> K[i].weight >> K[i].value;
    }
    sort(K + 1, K + n + 1,Compare);//按照性价比进行排序
    Backtrack(1);//子集树回溯
    cout << "最大价值为" << bestv << endl;
    cout << "放入背包的物品序号" << endl;
    for (int i = 1; i <= n; ++i) {
        if (bestK[i] != 0) {
            cout << i << " ";
        }
    }
    return 0;
}


