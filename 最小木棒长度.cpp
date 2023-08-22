
//totalSticks    ľ��������  
//len            ���ڳ��Ե�ԭʼľ������  
//unusedSticks   ��δƴ�ӵ�len�е�ľ��  
//temp           ��ǰ����ƴ�ӵ�ľ����ʣ�೤��  

#include <stdio.h>  
#include <stdlib.h>  
  
bool is_original(int,int,int,int); //�ݹ麯�����ж�ĳһ�����Ƿ������ľ����ԭʼ����  
  
int cmp(const void *elem1,const void *elem2)  //qsort�ȽϺ���  
{  
    return *(int *)elem2 - *(int *)elem1;   //��������  
}  
  
int sticks[100];  //���ľ��������  
bool used[100];    //��¼ľ����ʹ�����  
  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    int n;  
    scanf("%d",&n);   //ľ������  
    while(n!=0)  
    {  
        int i,sum=0,len;  
        for(i=0; i<n; i++)  
        {  
            used[i] = false;  //��ʼ�� ��δʹ��  
            scanf("%d",&(sticks[i])); //�������ľ������  
            sum += sticks[i];   //ľ���ܳ���  
        }  
        qsort(sticks,n,sizeof(int),cmp);  //��ľ����������  
        len = sticks[0];      //len����С���ܾ��� �����һ��ľ��  
        for(i=len; i<=sum; i++)  //������ö��ԭʼľ���Ŀ��ܳ���  
        {  
            if(sum%i!=0)         //�ܳ��Ȳ����������ܳ��� ������  
                continue;  
            if(is_original(n,n,0,i))  //���������ԭʼ����  
            {  
                printf("%d\n",i);   //��������  
                break;  
            }  
        }  
        scanf("%d",&n);  
    }  
    return 0;  
}  
  
bool is_original(int totalSticks,int unusedSticks,int temp,int len)  
{  
    int i;  
    if(unusedSticks == 0&&temp == 0)  //���ʣ��ľ��Ϊ0��ʣ�೤��Ϊ0��ƴ�����  
        return true;  
    if(temp  == 0)         //��ǰƴ��ľ��ʣ�೤��Ϊ0��  
        temp = len;        //�����µ�һ��ԭʼ����  
    for(i=0; i<totalSticks; i++) //��ͷ��βѰ�ҿ��õ�ľ��  
    {  
        if(used[i]==true)      //�ù��ˣ�����  
            continue ;  
        if(sticks[i]>temp)      //ľ������ʣ�೤�ȣ�����  
            continue ;  
        used[i] = true;         //���Ϊ�ù���  
        if(is_original(totalSticks,unusedSticks-1,temp-sticks[i],len))  
            return true;  //temp��unusedSticks ����С �����µݹ�  
        used[i] = false;     //�˳��ϴγ��Ե�ľ��,׼����ʼ��һ��  
        if(sticks[i]==temp||temp==len) //������Ե���ĳ��ľ���ĵ�һλ�û������λ��  
            break;      //���ҵ���ʧ�ܣ��Ͳ��س���ʣ���ľ����  
    }  
    return false;  
}  

