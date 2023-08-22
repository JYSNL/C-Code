#include <stdio.h>

void test(int & x){
	x = 1024;
	printf("in:%d\n",x);
} 
int main(){
	printf("%d\n\n",l[0]);
	int x = 1;
	printf("before:%d\n",x);
	test(x);
	printf("after:%d",x);
	return 0;
}
