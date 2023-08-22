
//totalSticks    木棒的总数  
//len            正在尝试的原始木棍长度  
//unusedSticks   尚未拼接到len中的木棍  
//temp           当前正在拼接的木棍的剩余长度  

#include <stdio.h>  
#include <stdlib.h>  
  
bool is_original(int,int,int,int); //递归函数，判断某一长度是否可能是木棒的原始长度  
  
int cmp(const void *elem1,const void *elem2)  //qsort比较函数  
{  
    return *(int *)elem2 - *(int *)elem1;   //降序排列  
}  
  
int sticks[100];  //存放木棍的数组  
bool used[100];    //记录木棍的使用情况  
  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    int n;  
    scanf("%d",&n);   //木棍数量  
    while(n!=0)  
    {  
        int i,sum=0,len;  
        for(i=0; i<n; i++)  
        {  
            used[i] = false;  //初始化 ，未使用  
            scanf("%d",&(sticks[i])); //输入各个木棍长度  
            sum += sticks[i];   //木棍总长度  
        }  
        qsort(sticks,n,sizeof(int),cmp);  //对木棍进行排序  
        len = sticks[0];      //len的最小可能就是 最长的那一条木棍  
        for(i=len; i<=sum; i++)  //按升序枚举原始木棒的可能长度  
        {  
            if(sum%i!=0)         //总长度不能整除可能长度 ，跳过  
                continue;  
            if(is_original(n,n,0,i))  //如果可能是原始长度  
            {  
                printf("%d\n",i);   //输出所需答案  
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
    if(unusedSticks == 0&&temp == 0)  //如果剩余木棍为0，剩余长度为0，拼接完成  
        return true;  
    if(temp  == 0)         //当前拼接木棍剩余长度为0；  
        temp = len;        //尝试新的一个原始长度  
    for(i=0; i<totalSticks; i++) //从头到尾寻找可用的木棍  
    {  
        if(used[i]==true)      //用过了，跳过  
            continue ;  
        if(sticks[i]>temp)      //木棍大于剩余长度，跳过  
            continue ;  
        used[i] = true;         //标记为用过了  
        if(is_original(totalSticks,unusedSticks-1,temp-sticks[i],len))  
            return true;  //temp和unusedSticks 都减小 ，向下递归  
        used[i] = false;     //退出上次尝试的木棍,准备开始下一个  
        if(sticks[i]==temp||temp==len) //如果尝试的是某个木棍的第一位置或者最后位置  
            break;      //并且导致失败，就不必尝试剩余的木棍了  
    }  
    return false;  
}  

