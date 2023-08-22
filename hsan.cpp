#include <iostream>
using namespace std;

void move(int a[][2]){
	a[1][1] = 4;
}

int main()
{
	int a[2][2] = {0,0,0,0};
	move(a);
	cout << a[1][1];
	return 0;
}
