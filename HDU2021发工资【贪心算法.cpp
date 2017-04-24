#include<stdio.h>
int a[6]={100,50,10,5,2,1};
int ccl(int *p,int n){
	int num=0;
	for(int t=0;t<n;t++){
		for(int i=0;i<6;i++){
		num+=p[t]/a[i];
		p[t]=p[t]%a[i];}
	}
	return num;
}
int main(){
	int n,pay[102];
	while(~scanf("%d",&n)&&n!=0){
	for(int i=0;i<n;i++){
		scanf("%d",&pay[i]);}
	printf("%d\n",ccl(pay,n));
}
}