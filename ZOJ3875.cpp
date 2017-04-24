#include<stdio.h>
#include<stdlib.h>

struct Sn{
	int price;
	char str[52];
}s[100];

struct Mn{
	int price;
	char str[52];
}m[100];

struct Dn{
	int price;
	char str[52];
}d[100];

int cmp1( const void *a , const void *b ) 
	{ 
	struct Sn *c = (Sn *)a; 
	struct Sn *d = (Sn *)b; 
	if(c->price != d->price) return c->price - d->price; 
	}
	
int cmp2( const void *a , const void *b ) 
	{ 
	struct Mn *c = (Mn *)a; 
	struct Mn *d = (Mn *)b; 
	if(c->price != d->price) return c->price - d->price; 
	}

int cmp3( const void *a , const void *b ) 
	{ 
	struct Dn *c = (Dn *)a; 
	struct Dn *d = (Dn *)b; 
	if(c->price != d->price) return c->price - d->price; 
	}
void input(int sn,int mn,int dn){
	for(int i=0;i<sn;i++){
		scanf("%s%d",s[i].str,&s[i].price);
	}
	for(int i=0;i<mn;i++){
		scanf("%s%d",m[i].str,&m[i].price);
	}
	for(int i=0;i<dn;i++){
		scanf("%s%d",d[i].str,&d[i].price);
	}
}

int main(){
	int cases,s_num,m_num,d_num;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&s_num,&m_num,&d_num);
		input(s_num,m_num,d_num);
		qsort(s,s_num,sizeof(s[0]),cmp1);
		qsort(m,m_num,sizeof(m[0]),cmp2);
		qsort(d,d_num,sizeof(d[0]),cmp3);
		printf("%d %s %s %s\n",s[(s_num/2)].price+m[(m_num/2)].price+d[(d_num/2)].price,
		s[(s_num/2)].str,m[(m_num/2)].str,d[(d_num/2)].str);
		}
}