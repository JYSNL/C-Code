#include<iostream>
#include<algorithm>  
#include<string.h>  
#include<string>   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;


 
int getValue(int oldValue, int addValue) {
        return (oldValue + addValue) % 1000000007;
    }

int countVowelPermutation(int n) {
        int aNum = 0;
        int eNum = 0;
        int iNum = 0;
        int oNum = 0;
        int uNum = 0;
        int sum = 0;
 
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                aNum++;
                eNum++;
                iNum++;
                oNum++;
                uNum++;
                sum = 5;
                continue;
            }
            int sumLocal = 0;
            int aNumLocal = 0;
            int eNumLocal = 0;
            int iNumLocal = 0;
            int oNumLocal = 0;
            int uNumLocal = 0;
 
            //a
            eNumLocal = getValue(eNumLocal, aNum);
            sumLocal = getValue(sumLocal, aNum);
 
            //e
            aNumLocal = getValue(aNumLocal, eNum);
            sumLocal = getValue(sumLocal, eNum);
 
            iNumLocal = getValue(iNumLocal, eNum);
            sumLocal = getValue(sumLocal, eNum);
 
            //i
            aNumLocal = getValue(aNumLocal, iNum);
            sumLocal = getValue(sumLocal, iNum);
 
            eNumLocal = getValue(eNumLocal, iNum);
            sumLocal = getValue(sumLocal, iNum);
 
            oNumLocal = getValue(oNumLocal, iNum);
            sumLocal = getValue(sumLocal, iNum);
 
            uNumLocal = getValue(uNumLocal, iNum);
            sumLocal = getValue(sumLocal, iNum);
 
 
            //o
            iNumLocal = getValue(iNumLocal, oNum);
            sumLocal = getValue(sumLocal, oNum);
 
            uNumLocal = getValue(uNumLocal, oNum);
            sumLocal = getValue(sumLocal, oNum);
 
            //u
            aNumLocal = getValue(aNumLocal, uNum);
            sumLocal = getValue(sumLocal, uNum);
 
            //取模
            aNum = aNumLocal;
            eNum = eNumLocal;
            iNum = iNumLocal;
            oNum = oNumLocal;
            uNum = uNumLocal;
            sum = sumLocal;
        }
        return sum;
    }


int main(){
    int n;
    cin>>n;
    while (n--)
    {
        int k;
        cin>>k;
        int x = countVowelPermutation(k);
        cout<<x<<endl;
    }
    return 0;
}
