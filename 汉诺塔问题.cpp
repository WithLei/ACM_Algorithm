#include<stdio.h>
	long long time=0;
void move(int n,char x,char y,char z){
	if(1==n){
//		printf("%c--->%c\n",x,z);
		time++;
	}
	else{
		move(n-1,x,z,y);	//�� n-1 �����Ӵ� x ���� z �Ƶ� y �� 
//		printf("%c-->%c\n",x,z);
		time++;	//���� n �����Ӵ� x �Ƶ� z �� 
		move(n-1,y,x,z);	//�� n-1 �����Ӵ� y ���� x �Ƶ� z �� 
	}
	//printf("%d\n",time);
} 
int main(){
	int n,M;
//	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		time=0;
	scanf("%d",&n);
//	printf("�ƶ��Ĳ������£�\n");
	move(n,'X','Y','Z'); 
	printf("%d\n",time%20142014);}
	return 0;
} 