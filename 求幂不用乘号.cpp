#include <iostream>
using namespace std;

int cheng_without_cf(int x , int n){
    if(n==1){
        return x;
    }
    else if (n<1)
    {
        cout << "Wrong input!"<<endl;
        return -1;
    }           
    else{
        return x + cheng_without_cf(x,n-1);
    }
}

int main(){
    int a , b;
    cin >> a >> b;
    cout<< cheng_without_cf(a,b);
    return 0;
}