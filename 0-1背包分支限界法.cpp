#include<iostream>
#include<windows.h>
#include<iomanip>
#define MAX 100
using namespace std;

double MaxValue = 0; 

struct Node{
	double w;
	double v;
	int level;
	double ub;
	int flag;
	struct Node *parent;
};

Node *PT[MAX];

int empty(Node *PT[],int count){
	for(int a=0;a<=count;a++){
		if(PT[a]->flag==0)
			return 0;
	}
	return 1;
}

int IsMax(Node *PT[],int count,Node *x){
	for(int a=0;a<=count;a++){
		if(x->ub<PT[a]->ub && PT[a]==0)
			return 0;
	}
	return 1;
}

Node *maxofPT(Node *PT[],int count){
	double max=0;int r=-1;
	for(int a=0;a<=count;a++){
		if(PT[a]->ub>max&&PT[a]->flag==0){
			max = PT[a]->ub;
			r = a;
		}	
	}
	PT[r]->flag=1;
	return PT[r];
}

Node *bestleaf(Node *PT[],int count,int n){
	Node * leaf;
	double max =0;
	for(int a=0;a<=count;a++){
		if ( (PT[a]->level==n) && (PT[a]->ub>max) ){
			max = PT[a]->ub;
			leaf = PT[a];
		}
	}
	return leaf;
}

int *bag(double w[],double v[],int W,int n){
	int i;
	int count = 0;
	int weight=0,downbound=0;
	int *x;
	x = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		x[i]=-1;
	}
	//���Ͻ� 
	double upbound = W*(v[0]/w[0]);
	//̰�ķ����½�
	for(i=0;i<n;i++){
		if(weight+w[i]<=W){
			weight+=w[i];
			downbound+=v[i];
		}
	}
	Node *N = (Node *)malloc(sizeof(Node)*1);

	N->flag=0;
	N->w=0;
	N->v=0;
	N->level=0;
	N->ub = upbound;
	N->parent=NULL;
	PT[count]=N;
	
	Node * leaf = (Node *)malloc(sizeof(Node)*1);
	
	Node *nodei = (Node *)malloc(sizeof(Node)*1);
	
	while( 1 ){
//		cout<<"PT-------PT:"<<endl;
//		for(int a=0;a<=count;a++){
//			if(PT[a]->flag==0)
//				cout<<PT[a]->ub<<" ";
//		}
//		cout<<endl;
		nodei = maxofPT(PT,count);
//		cout<<"nodei->ub"<<nodei->ub<<endl;
		//������Ҷ�ӽ�����������������ӽ�� 
		if(nodei->level != n){
			//��ڵ㣨������Ʒ�� 
			Node *nodej = (Node *)malloc(sizeof(Node)*1);
			nodej->flag = 0;
			nodej->w=nodei->w + w[nodei->level];
			nodej->v=nodei->v + v[nodei->level];
			nodej->level=nodei->level+1;
			if(nodej->level != n)
				nodej->ub = nodej->v + (W-nodej->w)*(v[nodej->level]/w[nodej->level]);
			else
				nodej->ub = nodej->v;
			nodej->parent=nodei;
			if(nodej->w<=W){
				PT[++count] = nodej;
//				cout<<"����PT1"<<endl; 
			}
			//�ҽ�㣨��������Ʒ��
			Node *nodek = (Node *)malloc(sizeof(Node)*1);
			nodek->flag = 0;
			nodek->w=nodei->w;
			nodek->v=nodei->v;
			nodek->level=nodei->level+1;
			if(nodek->level != n)
				nodek->ub = nodek->v + (W-nodek->w)*(v[nodek->level]/w[nodek->level]);
			else
				nodek->ub = nodek->v;
			nodek->parent=nodei;
			if(nodek->w<=W){
				PT[++count] = nodek;
//				cout<<"����PT2"<<endl;
			}
		}
		else{
			if(IsMax(PT,count,nodei))
				break;//ѭ������ 
		}
	}//while
	//��Ҷ�ӽ���Ӧ������ֵ���������������Ž�ĸ�������
	leaf = bestleaf(PT,count,n);
//	cout<<leaf->ub<<" "<<leaf->w<<" "<<leaf->v<<endl;
	MaxValue = leaf->v;
	while(leaf->parent!=NULL){
		if(leaf->w == leaf->parent->w)
			x[leaf->level-1]=0;
		else
			x[leaf->level-1]=1;
		
		leaf=leaf->parent;
	}
//	cout<<"count "<<count<<endl;
	return x;//�������Ž� 
}

int main(){
	double w[]={4,7,5,3};
	double v[]={40,42,25,12};
	int W = 10;
	int n = 4;
	int *r = (int *)malloc(sizeof(int)*n);
	
	//��ʱ�仨�� 
	LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	//��ʱ��������
	 
	r = bag(w,v,W,n);//���ʱ��� 
	
	QueryPerformanceCounter(&nEndTime);
	time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)*1000000000/(double)(nFreq.QuadPart);
	//����ʱ��������
	
	cout<<"����ֵ:"<<MaxValue<<endl; 
	cout<<"���Ž�:"<<endl; 
	for(int i=0;i<n;i++){
		cout<<r[i]<<endl;
	}
	cout<<time; 
	return 0;
} 

