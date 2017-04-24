#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	return (*(int *)a-*(int *)b);
}//升序排列 
int main(){
	int time,now,str[1001];
	scanf("%d",&time);
	for(int i=0;i<time;i++){
		scanf("%d",&now);//当前Now个数字
		for(int ii=0;ii<now;ii++){
			scanf("%d",&str[ii]);
		} 
		qsort(str,now,sizeof(str[0]),cmp);
		printf("%d",str[0]);
		for(int t=1;t<now;t++){
			printf(" %d",str[t]);
		}
		printf("\n");
	}
} 