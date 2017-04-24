#include<stdio.h>
#include<math.h> 
#define PI 3.141592654
#define E 2.71828182846
int l(int n)
{
    int s=1;
    if(n>3)
        s=log10(2*PI*n)/2+n*log10(n/E)+1;
    return s;
}
// 斯特林（Stirling）公式：
int main(){
	int num,time;
	scanf("%d",&time);
	for(int i=0;i<time;i++){
	scanf("%d",&num);
	printf("%d\n",l(num));}
} 

