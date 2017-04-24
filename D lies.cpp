#include<stdio.h>
#include<stdlib.h>
int mmp(const void *a,const void *b){
	return (*(int*)a-*(int*)b);//ÕıĞòÅÅÁĞ
 	//return (*(int*)b-*(int*)a);//ÄæĞòÅÅÁĞ
}
int main(){
	int a[1000],b[1000],n,l,r,flag,t;
	while(~scanf("%d%d%d",&n,&l,&r)){
		flag=1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		for(int i=0;a[i]==l||a[i]==r;i++){
			if(a[i]!=b[i]){
				flag=0;
			}
		}
		for(int i=n-1;a[i]==l||a[i]==r;i--){
			if(a[i]!=b[i]){
				flag=0;
			}
		}
		qsort(a,n,sizeof(a[0]),mmp);
		qsort(b,n,sizeof(b[0]),mmp);
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				flag=0;
			}
		}
		if(flag==1){
			printf("TRUTH\n");
		}else{
			printf("LIE\n");
		}
	}
}