#include<stdio.h>
int main(){
	int seconds,time,i,num[101];
	do{
		scanf("%d",&time);
		if(time!=0){
		for(i=0;i<time;i++){
			scanf("%d",&num[i]);}
		seconds=time*5+num[0]*6;	
		for(i=1;i<time;i++){
			if(num[i-1]>num[i]){seconds+=(num[i-1]-num[i])*4;}
			if(num[i-1]<num[i]){seconds+=(num[i]-num[i-1])*6;}
		}
		printf("%d\n",seconds);
		}
	}while(time!=0);
} 