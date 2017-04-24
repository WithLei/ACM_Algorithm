#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s1[]= {"-_=+wertyuiop[{]}sdfghjkl;:zxcvbnm,<.>/?WERTYUIOPSDFGHJKLZXCVBN"};
char s2[]= {"[{]},.pyfgcrl/?=+oeuidhtnsS;qjkxbmwWvVzZ<>PYFGCRLOEUIDHTN:QJKXB"};
void s(char c){
	 for(int t=0; t<63; t++){
        if(s1[t]==c){c=s2[t];break;}
        if(c=='Q'){c='"';break;}
        if(c=='"'){c='_';break;}
        if(c=='q'){c=39;break;}
        if(c==39){c='-';break;}
	 }
		printf("%c",c);
}
int main(){
	char c;
	while(~scanf("%c",&c)){
		s(c);
	}
} 