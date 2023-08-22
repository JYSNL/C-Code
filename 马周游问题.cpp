#include<iostream>
#include <iomanip>
#include <queue>
using namespace std;
 
//��ĳһ���ӵİ����߷�
int fx[]= {2,1,-1,-2,-2,-1,1,2};
int fy[]= {-1,-2,-2,-1,1,2,2,1};
 
typedef struct
{
    int x,y; //����
    int number; //���
} Point; //�����еĸ���
 
//�����ε����̣�ע��ʹ�õ�ʱ���Ǵ��±�Ϊ1��ʼ
Point board[10000][10000];
 
int n; //���̴�С
int step =1; //���
 
//������
void outputResult(int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<endl<<endl;
        for(int j=1; j<=n; j++)
        {
            cout<<setw(3)<<board[i][j].number<<" ";
        }
    }
    cout<<endl<<endl;
}
 
bool check(int x,int y)
{
    if(x<1 || y<1 || x>n || y>n || board[x][y].number != 0)
        return false;
    return true;
}
 
//��һλ���ж������߷�
int nextPosHasSteps(int x, int y)
{
    int steps = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (check(x + fx[i], y + fy[i]))
            steps++;
    }
    return steps;
}
 
//�ǵݹ���߷�
void horseRun(Point point)
{
    queue<Point> pointQueue;
    pointQueue.push(point);
 
    Point temp;
 
    while(!pointQueue.empty())
    {
        temp = pointQueue.front();
        pointQueue.pop();
 
        board[temp.x][temp.y].number = step++;
 
        int minStep = 8;
 
        int flag = 0;
 
        for(int i=0; i<8; i++) //����һλ���߷����ٵĽ������
        {
            int x=temp.x + fx[i];
            int y=temp.y + fy[i];
 
            if(check(x,y))
            {
                if(nextPosHasSteps(x,y) <= minStep)
                {
                    minStep = nextPosHasSteps(x,y);
 
                    Point t;
                    t.x = x;
                    t.y = y;
 
                    if(flag) pointQueue.pop();
 
                    pointQueue.push(t);
                    flag = 1;
                }
            }
        }
    }
}
 
int main()
{
    cout<<"�������̴�Сn:";
    cin>>n;
 
    Point startPoint;
    cout<<"������������ʼλ��x(1~n),y(1~n):";
    cin>>startPoint.x>>startPoint.y;
 
    horseRun(startPoint);
    //������
    outputResult(n);
    return 0;
}
