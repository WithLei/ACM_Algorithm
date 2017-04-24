#include<stdio.h>
#include<stdlib.h>
struct In{
	int s;
	int e;
} Ti[101];

int cmp( const void *a , const void *b ) 
	{ 
	struct In *c = (In *)a; 
	struct In *d = (In *)b; 
	if(c->e != d->e) return c->e - d->e; 
	else return d->s - c->s; 
	}
	
int greedy(int time,struct In Ti[]){
	int num=1,i=0;
	for(int j=1;j<time;j++){
		if(Ti[j].s>=Ti[i].e){
			i=j;num++;}
	}
	return num;
}

int main(){
	struct In Ti[101];
	int time;
	while(~scanf("%d",&time)&&time!=0){
		for(int t=0;t<time;t++){
			scanf("%d%d",&Ti[t].s,&Ti[t].e);
		}
		qsort(Ti,time,sizeof(Ti[0]),cmp);
		printf("%d\n",greedy(time,Ti));
		/*
for(int i=0;i<time;i++){
			printf("%d--%d\n",Ti[i].s,Ti[i].e);
		}*/
	}
} 