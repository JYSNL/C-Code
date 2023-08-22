#include<iostream>
using namespace std;
int main(){
    char s[19];
    cin >> s;
    for(int i = 0 ; i < 19 ; i++)
    {
    	if(s[i]==',')
    	{
    		s[i] = ' ';
		}
	}
    cout << s;
    return 0;
}
