#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
char b[9][9];
int main()
{
	char dfssudu(char board[][9] , char rowused[][10] , char colused[][10] , char boxused[3][3][10] , int row , int col);
	void solvesudu(char board[][9]);
	

    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            cin >> b[i][j];
        }
    }
    solvesudu(b);
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}

int dfssudu(char board[][9] , char rowused[][10] , char colused[][10] , char boxused[3][3][10] , int row , int col)
{
    if(col==9)
    {
        col = 0;
        row++;
        if(row == 9)
            return 1;
    }

    if(board[row][col]=='.')
    {
        for(int num = 1 ; num <=9 ; num++)
        {
            int canused = 0;
            if(rowused[row][num] == false || colused[col][num] == false || boxused[row/3][col/3][num] == false)
            {
                canused = 1;
            }
            if(canused)
            {
                rowused[row][num] = true;
                colused[col][num] = true;
                boxused[row/3][col/3][num] = true;
                board[row][col] = (char)('0'+num);

                char cansolve = dfssudu(board , rowused , colused , boxused , row , col+1);

                if(cansolve==true){
                    return 1;
                }
                else{
                    board[row][col] = '.';
                    rowused[row][num] = false;
                    colused[col][num] = false;
                    boxused[row/3][col/3][num] = false;
                }
            }
        }
    }
    else
    {
        return dfssudu(board , rowused , colused , boxused , row , col+1);
    }

    return 0;
}

void solvesudu(char board[][9])
{	
    char rowused[9][10];
    char colused[9][10];
    char boxused[3][3][10];

    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
        	char temp = board[i][j];
            int num = temp - '0';
            if(num >= 1 && num <=9){
                rowused[i][num] = true;
                colused[j][num] = true;
                boxused[i/3][j/3][num] = true;
            }
        }
    }

    dfssudu(board , rowused , colused , boxused , 0 , 0);
}




