#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
void ccl(char *num,int length){
	for(int i=0;i<length;i++){
		num[i]-=48;}
}
int number(char *num){
	int n=atoi(num);
		return n;
}
int numsum(char *num,int length){
	int n=0;
	for(int i=0;i<length;i++){
		n+=num[i];
	}
	return n;
}
int numsqsum(char *num,int length){
	int n=0;
	for(int i=0;i<length;i++){
		n+=num[i]*num[i];
	}
	return n;
}
int main(){
	int time;
	char num[20],numcpy[20];
	scanf("%d",&time);
	while(time--){
		scanf("%s",num);
		int length=strlen(num);
		strcpy(numcpy,num);
		ccl(num,length);
//		printf("%d--%d--%d\n",number(numcpy),numsum(num,length),numsqsum(num,length));
		if(number(numcpy)%8==0||numsum(num,length)%8==0||numsqsum(num,length)%8==0)
		{puts("Lucky number!");}
		else puts("What a pity!");
		
	}
} 