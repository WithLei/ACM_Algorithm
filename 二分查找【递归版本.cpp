#include<stdio.h>
#include<stdlib.h>
int BinarySearch2(int a[], int value, int low, int high)//二分查找，递归版本 
{
  int mid = low+(high-low)/2;
  if(a[mid]==value)
    return mid;
  if(a[mid]>value)
    return BinarySearch2(a, value, low, mid-1);
  if(a[mid]<value)
    return BinarySearch2(a, value, mid+1, high);
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
	int c=BinarySearch2(str,22,0,9);
	printf("\n%d\n",c);
	//查找到的为str[c] 
}
