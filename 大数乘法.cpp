#include <iostream>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    int i,j,a[999]={0},b[999] = {0},a_len,b_len,k = 0,c[999] = {0};
    cin>>str1>>str2;
    a_len = str1.size();
    b_len = str2.size();
    for(i = a_len-1 , k=0;i>=0;i--,k++){
        a[k] = str1[i]-'0';
    }
    for(i = b_len-1 , k=0;i>=0;i--,k++){
        b[k] = str2[i]-'0';
    }
    for(i = 0 ; i < a_len ; i++){
        for(j = 0 ; j < b_len ; j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    for(i = 0 ; i < (a_len+b_len);i++){
        if(c[i]>9){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    for(i = a_len+b_len;i>=0;i--){
        if(c[i]==0) continue;
        else    break;
    }
    for(;i>=0;i--){
        cout<<c[i];
    }
    return 0;
}