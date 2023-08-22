
#include <iostream>
using namespace std;

int main( )
{
    short int j = 2;
    int i = 6;
    float f2 = 3e2;
    cout << f2 << endl;
    cout << i+j << sizeof(j) <<sizeof(i) <<endl;
    int k ;
    char ch[200];
    cin >> k;
    for(i = 0 ; i < k ; i++)
    {
    	ch[i] = 'a';
	}
    cout << ch << "\thelloworld" << endl;
    return 0;
}
