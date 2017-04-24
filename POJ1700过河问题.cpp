#include<iostream>  
#include<algorithm>  
using namespace std;  
  
int main()  
{  
    int a[1000],t,n,sum;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        sum=0;  
        for(int i=0;i<n;i++) scanf("%d",&a[i]);  
        while(n>3)  
        {  
            sum=min(sum+a[1]+a[0]+a[n-1]+a[1],sum+a[n-1]+a[0]+a[n-2]+a[0]);  
            n-=2;  
        }  
        if(n==3) sum+=a[0]+a[1]+a[2];  
        else if(n==2) sum+=a[1];  
        else sum+=a[0];  //只有一个人的情况 
        printf("%d\n",sum);  
    }  
}