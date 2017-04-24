#include<stdio.h>
int fib(int index){
	if(index==1||index==2){
		return 1;
	}else{
		return fib(index-1)+fib(index-2);
	}
}
int main(){
	int fib(int index);
	int num;
	scanf("%d",&num); 
	int result=fib(num);
	printf("%d\n",result);
} 
