#include<stdio.h>
int main(){
	int cases,N,num,max,flag,t;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		int a[1002]={0};
		while(N--){
			scanf("%d",&num);
			a[num]++;
		}
		max=a[0];
		flag=0;
		t=0;
		for(int i=1;i<1002;i++){if(a[i]>=max){max=a[i];flag=i;}}
		for(int i=0;i<1002;i++){
			if(i==flag)continue;
			if(max==a[i]){t=1;break;}
		}
		if(t==1){printf("Nobody\n");}
		else printf("%d\n",flag);
	}
}