#include<stdio.h>
int main() {
	int x,y,n,m;
	scanf("%d%d%d%d",&x,&y,&n,&m);
	int sx=n-x;
	int sy=m-y;
	if(sy>sx) {//斜率大于 1 的直线，转换坐标，以y作为自增量，x作为因增量
		m>y?:(m^=(y^=(m^=y)),n^=(x^=(n^=x)));//防止坐标大小反了，要不然结果错干净净的，所以检查并调换一下坐标；
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
	} else if(1.*sy/sx>=0) {//斜率大于0但小于 1
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
	} else if(1.*sy/sx>-1) {//斜率大于-1但小于0
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
	} else {//剩下的就知道啦！！！！！
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
