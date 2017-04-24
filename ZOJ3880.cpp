#include<stdio.h>
int main(){
	int cases,member,time=0,a;
	scanf("%d",&cases);
	 while(cases--){
	 	time=0;
 		scanf("%d",&member);
 		while(member--){
		 	scanf("%d",&a);
		 	if(a>6000){time++;}
		 }
		 printf("%d\n",time);
 	}
} 