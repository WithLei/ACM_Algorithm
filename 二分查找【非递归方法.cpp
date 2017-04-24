#include<stdio.h>
#include<stdlib.h>
int BinarySearch1(int a[], int value, int n)//非递归版本 n为长度 
{
  int low, high, mid;
  low = 0;
  high = n-1;
  while(low<=high)
  {
    mid = (low+high)/2;
    if(a[mid]==value)
      return mid;
    if(a[mid]>value)
      high = mid-1;
    if(a[mid]<value)
      low = mid+1;
  }
  return -1;
}
int cmp(const void *a,const void *b){//升序排列 
	return (*(int *)a - *(int *)b);
}
int main(){
	int str[100]={1,7,8,5,58,90,60,2,22};
	qsort(str,9,sizeof(str[0]),cmp);
	printf("%d",str[0]);
	for(int i=1;i<9;i++){
		printf(" %d",str[i]);
	}
	int c=BinarySearch1(str,90,9);
	printf("\n%d\n",c);
	//查找到的为str[c] 
}
