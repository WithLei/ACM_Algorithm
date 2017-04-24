#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;//ÉýÐò 
}
int main(){
	int num,time,ii,t[21];
	while(scanf("%d",&time)){
	for(int i=0;i<time;i++){
		scanf("%d",&num);
		for(ii=0;ii<num;ii++){scanf("%d",&t[ii]);}
		qsort(t,num,sizeof(t[0]),cmp);
		if(t[num-1]==t[0]) printf("Nooooooo!\n",t[0]);
		else printf("%d\n",t[num-1]-t[0]);
	}
	}
}
