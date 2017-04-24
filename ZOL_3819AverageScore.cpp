 #include<stdio.h>
 int main(){
 	int num,m,n,mnum[51],nnum[51],msum,nsum,mave,nave;
 	scanf("%d",&num);
 	for(int i=0;i<num;i++){
 		msum=0,nsum=0;
	 	scanf("%d%d",&m,&n);
	 	for(int mi=0;mi<m-1;mi++){
 		scanf("%d",&mnum[mi]);
 		msum+=mnum[mi];
	 	}
	 	if((double)msum/(m-1)-(int)msum/(m-1)==0){
	 		mave=msum/(m-1)-1;
	 	}else mave=msum/(m-1);
	 	for(int ni=0;ni<n;ni++){
 		scanf("%d",&nnum[ni]);
 		nsum+=nnum[ni];
	 	}
	 	nave=nsum/n+1;
	 	printf("%d %d\n",nave,mave);
	 }
 }