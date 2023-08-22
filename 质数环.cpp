#include <stdio.h>
int Hash[35] = {0};
void circle(int n, int array[], int pos)
{
    if(pos == n){
        int temp = array[0] + array[n - 1];
        if (Hash[temp]) {
            for (int i = 0; i < n; i++) {
                printf("%d", array[i]); 
                if (i != n - 1) printf(" ");   
            }
            printf("\n");
        }
        return;
    }
    else {
        int j;
        //质数环奇偶一定间隔
        //pos为偶数位(pos & 1 = 0)时，放奇数
        //pos为奇数位(pos & 1 = 1)时，放偶数
        for (int i = 1 + (pos & 1); i <= n; i += 2) {
            //判断是否重复
            for (j = pos & 1; j < pos; j += 2) {
                if (i == array[j]) break;
            }
            if (j == pos) {
                int temp = i + array[pos - 1];
                if (Hash[temp]) {
                    array[pos] = i;
                    circle(n, array, pos + 1);
                } 
            }
        }
    }
}
int main()
{
    int n, i = 1;
    Hash[3] = 1; Hash[5] = 1; Hash[7] = 1; 
    Hash[11] = 1; Hash[13] = 1; Hash[17] = 1; 
    Hash[19] = 1; Hash[23] = 1; Hash[29] = 1; Hash[31] = 1;
    while (scanf("%d", &n) != EOF) {
        printf("Case %d:\n", i);
        if (n % 2 == 0) {
            int num[n];
            num[0] = 1;
            circle(n, num, 1);
        }
        else if (n == 1) {
            printf("1\n", i);
        }
        printf("\n");
        i++;
    }
	return 0;
}
