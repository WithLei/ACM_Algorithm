#include<stdio.h>
	long long time=0;
void move(int n,char x,char y,char z){
	if(1==n){
//		printf("%c--->%c\n",x,z);
		time++;
	}
	else{
		move(n-1,x,z,y);	//将 n-1 个盘子从 x 借助 z 移到 y 上 
//		printf("%c-->%c\n",x,z);
		time++;	//将第 n 个盘子从 x 移到 z 上 
		move(n-1,y,x,z);	//将 n-1 个盘子从 y 借助 x 移到 z 上 
	}
	//printf("%d\n",time);
} 
int main(){
	int n,M;
//	printf("请输入汉诺塔的层数：");
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		time=0;
	scanf("%d",&n);
//	printf("移动的步骤如下：\n");
	move(n,'X','Y','Z'); 
	printf("%d\n",time%20142014);}
	return 0;
} 