#include<stdio.h>
int factorial(int index){
	if(index==1){
		return 1;
	}else{
		return factorial(index-1)*index;
	}
}
int main(){
	int factorial(int index);
	int num;
	scanf("%d",&num);
	int result=factorial(num);
	printf("%d\n",result);
}
