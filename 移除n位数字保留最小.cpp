#include <iostream>
#include <string.h>
#include <malloc.h>
using namespace std;

char * removeKdigits(char * num, int k){
int length=strlen(num);  
   if(length-k==0) 
   {
   	return "0";
   }

   char stack[length];
   int top=-1,i=0,count=0;    
   while(count<k)
   {
   	 if(top==-1||stack[top]<=num[i])   
        {
            stack[++top]=num[i++];
        }
            	 	  
	  else{	
             top--;
	  	     count++;
            }  
   }
  while(top<length-k-1)
  {
  	stack[++top]=num[i++];
   } 
   char * result=(char *)malloc(sizeof(char)*(length-k+1));
   result[length-k]=0;
   for(i=length-k-1;i>=0;i--)	
   {
       result[i]=stack[top--];
   } 
   for(i=0;result[i]=='0'&&(i+1)<length-k;i++);
   return result+i;
   }


int main()
{
    string s;
    int k;
    cin >>k;
    cin >>s;
    int l = s.length();
    char str1[l];
    for(int i = 0 ; i < l ; i++)
    {
        str1[i] = s[i];
    }
    string des = removeKdigits(str1,k);
    cout << des <<endl;
    return 0;
}
