#include <stdio.h>
void eat(int day,int number)
{
	while(day-->1){
		printf("�ҵ�%d�����%d�ٷ�",day,number);
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
