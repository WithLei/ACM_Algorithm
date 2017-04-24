#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
int woman=0,team_num=0,g=0,num;
char str[503];

struct In{
	int group;
	int sex;
	int flag;
	int hate[503];
}man[502];

struct Inn{
	int a;
	int b;
}group[300];

void input(){
	memset(man,0,sizeof(struct In)*502);
	memset(group,0,sizeof(struct Inn)*300);
	int h;
	char a;
	woman=0,team_num=0,g=0;
	scanf("%d",&num);
		scanf("%s",str);
		for(int i=0;i<num;i++){
			man[i].group=str[i]-48;
		}
		scanf("%s",str);
		for(int i=0;i<num;i++){
			man[i].sex=str[i]-48;
		}
		for(int i=0;i<num;i++){
			scanf("%d",&h);	
			for(int t=0;t<h;t++){
				scanf("%d",&man[i].hate[t]);
			}
		}
}

void team(){
	int f;
	for(int i=0;i<num;i++){
		if(man[i].sex==0&&man[i].group==0&&man[i].flag!=1){//woman&&0
			for(int k=0;k<num;k++){
				f=0;
				if(man[k].sex==0&&man[k].group!=0&&man[k].flag!=1){//find woman&&1
					for(int l=0;man[i].hate[l];l++){//if hate
						if(man[i].hate[l]==k+1){f=1;break;}
					}
					for(int l=0;man[k].hate[l]&&f!=1;l++){//if hate
						if(man[k].hate[l]==i+1){f=1;break;}
					}
					if(f!=1){//find!
						man[i].flag=1;man[k].flag=1;
						woman+=2;team_num++;group[g].a=i;group[g].b=k;g++;
						break;
					}
				}
			}
		}
		
		if(man[i].sex==0&&man[i].group!=0&&man[i].flag!=1){//woman&&1
			for(int k=i;k<num;k++){
				f=0;
				if(man[k].sex==0&&man[k].group==0&&man[k].flag!=1){//find woman&&1
					for(int l=0;man[i].hate[l];l++){//if hate
						if(man[i].hate[l]==k+1){f=1;printf("here!!@!!!\n");break;}
					}
					for(int l=0;man[k].hate[l]&&f!=1;l++){//if hate
						if(man[k].hate[l]==i+1){f=1;printf("here!!@!!23333!\n");break;}
					}
					if(f!=1){//find!
						man[i].flag=1;man[k].flag=1;
						woman+=2;team_num++;group[g].a=i;group[g].b=k;g++;
						break;
					}
				}
			}
		}	
	}
	
	for(int i=0;i<num;i++){
			if(man[i].sex==0&&man[i].group==0&&man[i].flag!=1){//woman&&0
				for(int k=0;k<num;k++){
					f=0;
						if(man[k].sex!=0&&man[k].group!=0){//man&&not hate
							for(int l=0;man[i].hate[l];l++){//if hate
							if(man[i].hate[l]==k+1){f=1;break;}
						}
							for(int l=0;man[k].hate[l]&&f!=1;l++){//if hate
							if(man[k].hate[l]==i+1){f=1;break;}
						}
							if(f!=1){//find!
								man[i].flag=1;man[k].flag=1;
								woman++;team_num++;group[g].a=i;group[g].b=k;g++;
								break;
						}
					}
				}
			}
			
			if(man[i].sex==0&&man[i].group!=0&&man[i].flag!=1){//woman&&1
				for(int k=i;k<num;k++){
					f=0;
						if(man[k].sex!=0&&man[k].group==0&&man[k].flag!=1){//man&&not hate
							for(int l=0;man[i].hate[l];l++){//if hate
							if(man[i].hate[l]==k+1){f=1;break;}
						}
							for(int l=0;man[k].hate[l]&&f!=1;l++){//if hate
							if(man[k].hate[l]==i+1){f=1;break;}
						}
							if(f!=1){//find!
								man[i].flag=1;man[k].flag=1;
								woman++;team_num++;group[g].a=i;group[g].b=k;g++;
								break;
						}
					}
				}
			}
			
	}
	
	for(int i=0;i<num;i++){
		if(man[i].sex!=0&&man[i].group==0&&man[i].flag!=1){//man&&0
				for(int k=0;k<num;k++){
					f=0;
						if(man[k].sex!=0&&man[k].group!=0&&man[k].flag!=1){//man&&not hate
							for(int l=0;man[i].hate[l];l++){//if hate
							if(man[i].hate[l]==k+1){f=1;break;}
						}
							for(int l=0;man[k].hate[l]&&f!=1;l++){//if hate
							if(man[k].hate[l]==i+1){f=1;break;}
							}
							if(f!=1){//find!
								man[i].flag=1;man[k].flag=1;
								team_num++;group[g].a=i;group[g].b=k;g++;
								break;
						}
					}
				}
			}
			
			if(man[i].sex!=0&&man[i].group!=0&&man[i].flag!=1){//man&&1
				for(int k=0;k<num;k++){
					f=0;
						if(man[k].sex!=0&&man[k].group==0&&man[k].flag!=1){//man&&not hate
							for(int l=0;man[i].hate[l];l++){//if hate
							if(man[i].hate[l]==k+1){f=1;break;}
						}
							for(int l=0;man[k].hate[l]&&f!=1;l++){//if hate
							if(man[k].hate[l]==i+1){f=1;break;}
						}
							if(f!=1){//find!
								man[i].flag=1;man[k].flag=1;
								team_num++;group[g].a=i;group[g].b=k;g++;
								break;
						}
					}
				}
			}
		
		
	} 
	
}

void output(){
	printf("%d %d\n",team_num,woman);
	for(int i=0;i<team_num;i++){
		printf("%d %d\n",group[i].a+1,group[i].b+1);
	}
}

int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		input();
		team();
		output();
	}	
}