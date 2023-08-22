#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include <cmath>
using namespace std;
int puz[6][8];
int press[6][8];
bool p(int a[][8]) {
    for (int i = 1; i <5; i++) {
        for (int j = 1; j <= 6; j++) {
            a[i + 1][j] = (puz[i][j] + a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i - 1][j]) % 2;
        }
    }
    for (int i = 1; i <= 6; i++) {
        if ((puz[5][i] + a[5][i] + a[5][i - 1] + a[5][i + 1] + a[4][i]) % 2 != 0) return false;
    }
    return true;
}

int main() {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 8; j++) {
            puz[i][j] = 0;
            press[i][j] = 0;
        }
    for (int i = 1; i <=5; i++)
        for (int j = 1; j <=6; j++)
            scanf("%d", &puz[i][j]);
    int pu=1; 
    for(int a1=0;a1<2;a1++)
        for (int a2 = 0; a2<2; a2++)
            for (int a3 = 0; a3<2; a3++)
                for (int a4 = 0; a4<2; a4++)
                    for (int a5 = 0; a5<2; a5++)
                        for (int a6 = 0; a6 < 2; a6++) {
                            press[1][1] = a1;
                            press[1][2] = a2;
                            press[1][3] = a3;
                            press[1][4] = a4;
                            press[1][5] = a5;
                            press[1][6] = a6;
                            if (p(press)) {
                                for (int i = 1; i <= 5; i++) {
                                    for (int j = 1; j <= 6; j++) {
                                        printf("%d", press[i][j]);
                                        if (j < 6) printf(" ");
                                    }
                                    printf("\n");
                                }

                            }
                             
                        }

    
        
    return 0;
}

