#include <iostream>
using namespace std;

int xinln(int like[],int x)
{
    for (int i = 0; i < 3; i++)
    {
        if (x == like[i])
        {
            return 1;
        }
        
    }
    return 0;
}

int main(){
    int like_number[3] = {3,5,7};
    int x;
    cin >> x;
    if (xinln(like_number,x) == 1)
    {
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
}
