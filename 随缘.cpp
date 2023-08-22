int search-x(int a[] , int x , int l , int r)
{
    while (l<r)
    {
        int index = (l+r)/2;
        if (a[index] == x)
        {
            return x;
        }
        else if (a[index] > x)
        {
            r = index;
        }
        else
        {
            l = index;
        }
    }
    return -1;
}


int time-x(int arr[],int p,int r,int x){
	int q;
	if(p==r){    //1个数据
	  if(arr[p]==x)
		  return 1;
	  else
		  return 0;
	}
	else      //多个数据
		q=(p+r)/2;
		return(time-x(arr,p,q,x)+time-x(arr,q+1,r,x)); //递归方程
}