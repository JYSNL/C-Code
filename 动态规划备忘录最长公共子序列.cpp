#include<iostream>
#include<cstring>
using namespace std;
#define max 1000
 
int c[max][max];
char x[100],y[100],z[100];
int display[100][100];
 
int fillform(int n,int m){
    //并没有进行递归调用
    memset(c,0,sizeof(c));
    memset(z,0,sizeof(z));
    memset(display,0,sizeof(display));
    int i,j,k;
 
 
    //先填行和纵列，之后再每行每列的填表
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
        if(x[i-1]==y[j-1]) {c[i][j]=c[i-1][j-1]+1;display[i][j]=1;}
    else if(c[i][j-1]>c[i-1][j]) {c[i][j]=c[i][j-1];display[i][j]=2;}
       else {c[i][j]=c[i-1][j];display[i][j]=3;} } //这时已经算出了所有的情况来
   cout<<"test:"<<c[3][3]<<c[n][m-1]<<endl;
     return c[n][m];
}
 
void show()
{
 
    int n=strlen(x),m=strlen(y);
    int i,j,k;
 
    int count=0; //对应不同的作用
    while(n>0 && m>0) //不能是>=0
    {
        if(display[n][m]==1){
            z[count++]=x[n-1];n--;m--;}
            else if(display[n][m]==2) m--; //向上移动一层
             else if(display[n][m]==3) n--; //向左移动一层
    }
 
    while(--count) cout<<z[count];cout<<z[0];
}
 
int main(void)
{
   int count=5000;
   strcpy(x,"ABCBDAB");
    strcpy(y,"BDCABA");
 
   //cout<<x[1]<<y[1]<<endl;
    //cout<<strlen(x)<<" "<<strlen(y)<<endl;
    cout<<x<<endl;cout<<y<<endl;
         while(count--){
    cout<<"the length:"<<fillform(strlen(x),strlen(y))<<endl;}
    cout<<"the sequence:";show();
 
    return 0;
}       