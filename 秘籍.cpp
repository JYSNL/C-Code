#include <iostream>
using namespace std;

int flen(char miji[])              //返还输入字符串数组的长度
{
    int i = 0;
    while(miji[i] == 'S' || miji[i] == 'T')
    {
        i++;
    }
    return i;
}

int main(){
    char miji[200000];
    cin >> miji;
    int len_mi = flen(miji);
    int cnt=0;
    int count = 0;
    for(int i = 0 ; i < len_mi ; i++){
        if(miji[i] == 'S')
            cnt++;
        else if (miji[i] == 'T' && cnt>0)
            cnt--;
        else
            count++;
    }
    cout<<count+cnt;
    return 0;
}
