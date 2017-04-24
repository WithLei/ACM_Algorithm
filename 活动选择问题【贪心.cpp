#include <stdio.h>
#include <stdlib.h>

#define N 11

void recursive_activity_selector(int *s,int* f,int i,int n,int *ret);

void greedy_activity_selector(int *s,int *f,int *ret)
{
  int i,m;
  *ret++ = 1;
  i =1;
  for(m=2;m<=N;m++)
    if(s[m] >= f[i])
    {
       *ret++ = m;
       i=m;
    }
} 

int main()
{
    int s[N+1] = {-1,1,3,0,5,3,5,6,8,8,2,12};
    int f[N+1] = {-1,4,5,6,7,8,9,10,11,12,13,14};
//    int c[N+1][N+1]={0};
    int ret[N]={0};
    int i,j;
    //recursive_activity_selector(s,f,0,N,ret);
    greedy_activity_selector(s,f,ret);
    printf("最大子集为:{ ");
    for(i=0;i<N;i++)
    {
       if(ret[i] != 0)
         printf("a%d ",ret[i]);
    }
    printf(" }\n");
//    system("pause");
    return 0;
}

void recursive_activity_selector(int *s,int* f,int i,int n,int *ret)
{
     int *ptmp = ret;
     int m = i+1;
     //在i和n中寻找第一个结束的活动 
     while(m<=n && s[m] < f[i])
        m = m+1;
     if(m<=n)
     {
        *ptmp++ = m;  //添加到结果中 
        recursive_activity_selector(s,f,m,n,ptmp);
     }
}

