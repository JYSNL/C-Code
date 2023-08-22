
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#define MAX 30
int m , n , best;//m*n,���Ž�Ļ�������
int robots[MAX][MAX];//��ʾ�������������
int bestRobots[MAX][MAX];//��ŵ�ǰ���ŵĻ����˰������
int monitor[MAX][MAX];//��ʾ�ܼ������

//���ļ��ж�ȡm,n
void readFile ()
{
	FILE*f = fopen ( "D:\\ѧϰ\\������\\�㷨��������\\ʵ��5����+����\\input(2).TXT" , "r" );
	if (f == NULL)
	{
		printf ( "��ȡ�ļ�����" );
		return;
	}
	fscanf_s ( f , "%d%d" , &m , &n );
	fclose ( f );
}

//��ʼ������
void initData ()
{
	best = INT_MAX;
	memset ( monitor , 0 , sizeof ( monitor ) );
	memset ( robots , 0 , sizeof ( robots ) );
}

//�ڿ���̨��������˰����������ӡ���ļ���
void printArrange ()
{
	FILE* file = fopen ( "D:\\ѧϰ\\������\\�㷨��������\\ʵ��5����+����\\output(2).TXT" , "w" );
	printf ( "\n" );
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf ( "%2d" , bestRobots[i][j] );
			fprintf ( file,"%2d" , bestRobots[i][j] );
		}
		printf ( "\n" );
		fprintf (file, "\n" );
	}
	fclose ( file );
}

//����Ƿ�ȫ��������
bool checkAllRooms ()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (monitor[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

//��֦�������Ƿ���Բ���
bool canKeepUnsafe ( int x , int y )
{
	if (monitor[x][y - 1] == 0)
		return false;
	if (y==n)
	{
		if (y > 0 && monitor[x][y - 1] == 0)
			return false;
		if (y = n && monitor[x][y] == 0)
			return false;
	}
}

//���Ż����˼��ӳ�����
void arrangeRobots ( int x , int y , int robot )
{
	if (robot > best)//��֦
		return;
	if (x == m + 1)//�����������еĳ�����
	{
		if (checkAllRooms () && robot < best)//������еĳ����Ҷ�����������õĻ�����������֮ǰ����С��������
		{
			best = robot;
			memcpy ( bestRobots , robots , sizeof ( robots ) );//����ǰ�Ļ����˰ڷ�������ƴ���bestRobots
		}
		return;
	}
	//������԰ڷŻ�����
	if(monitor[x][y]==0&& monitor[x-1][y] == 0 && monitor[x][y-1] == 0 && 
		monitor[x][y+1] == 0 && monitor[x+1][y] == 0 )
	{
		//������ڷ�һ��������
		robots[x][y] = 1;
		robot++;
		monitor[x][y] = 1;
		monitor[x-1][y] = 1;
		monitor[x][y-1] = 1;
		monitor[x+1][y] = 1;
		monitor[x][y+1] = 1;
		//������һ��������
		if (y < n)
		{
			arrangeRobots ( x , y + 1 , robot );
		}
		else
		{
			arrangeRobots ( x + 1 , 1 , robot );
		}
		//���ݣ������ղŰڷŵĻ�����
		robots[x][y] = 0;
		robot--;
		monitor[x][y] = 0;
		monitor[x - 1][y] = 0;
		monitor[x][y - 1] = 0;
		monitor[x + 1][y] = 0;
		monitor[x][y + 1] = 0;
	}
	//���ڣ�ֱ�ӿ�����һ��������
	if (canKeepUnsafe)//��֦��������Բ��ڵĻ�
	{
		if (y < n)
		{
			arrangeRobots ( x , y + 1 , robot );
		}
		else
		{
			arrangeRobots ( x + 1 , 1 , robot );
		}

	}
}

//�����������ܵĺ���
void test (int x,int y)
{
	for (int i = x; i <= y; i++)
	{
		for (int j = x; j <= y; j++)
		{
			m = i;
			n = j;
			initData ();
			arrangeRobots ( 1 , 1 , 0 );
			if (best == INT_MAX)//�������best��ȻΪINT_MAX��ʾû�з���
			{
				printf ( "%2d%2d -1\n" , m , n );
			}
			else
			{
				printf ( "%2d%2d%2d\n" , m , n , best );
			}
		}
	}
}

int main ()
{
	readFile ();
	//���������㷨����
	//clock_t start_clock = clock ();
	//test ( 1 , 8 );
	//clock_t end_clock = clock ();
	//double passing_seconds = double ( end_clock - start_clock ) / CLOCKS_PER_SEC;
	//printf ( "total time:%fms\n" , passing_seconds );
	initData ();
	arrangeRobots ( 1 , 1 , 0 );
	if (best == INT_MAX)//�������best��ȻδINT_MAX��ʾû�з���
	{
		printf ( "no solution!" );
	}
	else
	{
		printf ( "���Ű��ŵĻ��������ǣ�%d" , best );
		printArrange ();
	}
	return 0;
}

