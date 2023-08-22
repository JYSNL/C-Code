#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
const int maxn = 35;
const double pi = acos(-1);
const double eps = 1e-10;
const double inf = 1e9;
struct node{
    double x,y;
};
int n;
node point[maxn];
 
double place_fish(double k){
    double maxx=-inf,minx=inf,maxy=-inf,miny=inf;
    double x,y;
    for(int i=1;i<=n;i++){
        x=point[i].x*cos(k)-point[i].y*sin(k);
        y=point[i].y*cos(k)+point[i].x*sin(k);
        maxx=max(maxx,x);
        minx=min(minx,x);
        maxy=max(maxy,y);
        miny=min(miny,y);
    }
    return max(maxx-minx,maxy-miny);
}
 
int main(){
    int all_fish;
    scanf("%d",&all_fish);
    while(all_fish--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&point[i].x,&point[i].y);
        }
        double l=0,r=pi/2;
        while(r-l>eps){
            double ll=(l*2+r)/3;
            double rr=(l+r*2)/3;
            double a1=place_fish(ll),a2=place_fish(rr);
            if(a1>a2)l=ll;
            else r=rr;
        }
        double s_wang = place_fish(l)*place_fish(l);
        if(s_wang < 5000)
        {
            if(all_fish >= 2)
                printf("%.2f\n",s_wang);
            else
                printf("%.2f",s_wang);
        }
            
        
        else
        {
        int temp = s_wang / 1000;
        double temp1 = temp * 1000;
        cout << temp1 << endl;
        double temp2 = (temp+1)*1000;
        cout << temp2 << endl;
        if(s_wang - temp1 >=500.00){
            if(all_fish >= 2)
                printf("%.2f\n",temp2);
            else
                printf("%.2f",temp2);
        }
        else{
           if(all_fish >= 2)
                printf("%.2f\n",temp1);
            else
                printf("%.2f",temp1);
        }
        }
    }
}
