#include<stdio.h>
int main() {
	int x,y,n,m;
	scanf("%d%d%d%d",&x,&y,&n,&m);
	int sx=n-x;
	int sy=m-y;
	if(sy>sx) {//б�ʴ��� 1 ��ֱ�ߣ�ת�����꣬��y��Ϊ��������x��Ϊ������
		m>y?:(m^=(y^=(m^=y)),n^=(x^=(n^=x)));//��ֹ�����С���ˣ�Ҫ��Ȼ�����ɾ����ģ����Լ�鲢����һ�����ꣻ
		int d=sy-2*sx;
		int a=x;
		for(int i=y; i<=m; ++i) {
			printf("%d %d\n",a,i);
			if(d<0) {
				a++;
				d+=2*sy-2*sx;
			} else {
				d-=2*sx;
			}
		}
	} else if(1.*sy/sx>=0) {//б�ʴ���0��С�� 1
		n>x?:(m^=(y^=(m^=y)),n^=(x^=(n^=x)));
		int d=sx-2*sy;
		int b=y;
		for(int i=x; i<=n; ++i) {
			printf("%d %d\n",i,b);
			if(d<0) {
				b++;
				d+=2*sx-2*sy;
			} else {
				d-=2*sy;
			}
		}
	} else if(1.*sy/sx>-1) {//б�ʴ���-1��С��0
		n>x?:(m^=(y^=(m^=y)),n^=(x^=(n^=x)));
		int d=-sx-2*sy;
		int b=y;
		for(int i=x; i<=n; ++i) {
			printf("%d %d\n",i,b);
			if(d>0) {
				b--;
				d-=(2*sx+2*sy);
			} else {
				d-=2*sy;
			}
		}
	} else {//ʣ�µľ�֪��������������
		m>y?:(m^=(y^=(m^=y)),n^=(x^=(n^=x)));
		int d=-sy-2*sx;
		int a=x;
		for(int i=y; i<=m; ++i) {
			printf("%d %d\n",a,i);
			if(d<0) {
				a--;
				d-=2*sy+2*sx;
			} else {
				d-=2*sx;
			}
		}
	}
	return 0;
}
