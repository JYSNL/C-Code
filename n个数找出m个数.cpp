#include<iostream>
#include<algorithm>
using namespace std;
bool ok(int get[],int k)
{
for(int i=0;i<k;i++)if(get[i]>=get[k])return false;
return true;
}
void print(int a[],int len)
{
for(int i=0;i<len;i++)
cout<<a[i]<<" ";
cout<<endl;
}
int main()
{
int sum=0;int n,m;
//���ݷ���n����������ѡȡm������
cout<<"��������"<<endl;cin>>n;
int num[n];
cout<<"�ֱ�������"<<n<<"������"<<endl;
for(int i=0;i<n;i++)cin>>num[i];
sort(num,num+n);
cout<<"Ҫȡ���ٸ����������һ��"<<endl;
cin>>m;

int get5[m];
for(int i=0;i<m;i++)get5[i]=-1;
int k=0;int c[m];
for(int i=0;i<m;i++)c[i]=0;
while(k>=0)
{
while(c[k]<n)
{
get5[k]=num[c[k]++];
if(ok(get5,k)&&k==m-1)//�õ�һ��������� 
{
print(get5,m);sum++;
}
else if(ok(get5,k)&&k<m-1)k++;//�õ����ֽ⣬���������� 
}
get5[k]==-1;
c[k]=0;
k--;
} 
cout<<"����"<<sum<<"�����"<<endl;
return 0; 
} 

