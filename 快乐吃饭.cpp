#include <stdio.h>
void eat(int day,int number)
{
	while(day-->1){
		printf("我第%d天吃了%d顿饭",day,number);
		number++;
	}
	return ;
}
int main(){
	int i,j;
	scanf("%d %d",&i,&j);
	eat(i,j);
	return 0;
}
