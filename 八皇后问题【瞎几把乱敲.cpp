#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef pair<int,int>point;
point p;
const int maxn = 8;
map<point,int>range;
void biaoji(int x,int y){
	for(int i=0;i<maxn;i++){
		if(range[point(i,y)]!=2)
			range[point(i,y)]=1;
		if(range[point(x,i)]!=2)
			range[point(x,i)]=1;
	}
	int i=0;
	while(x+i<maxn){
		if(x+i<maxn&&y+i<maxn&&range[point(x+i,y+i)]!=2)
			range[point(x+i,y+i)]=1;
			i++;
	}
	i=0;
	while(y-i>0&&x+i<maxn){
		if(x+i<maxn&&y-i>0&&range[point(x+i,y-i)]!=2)
			range[point(x+i,y-i)]=1;
			i++;	
	}
}
void work(int &total){
	range[point(0,0)]=2;
	bool flag=false;
	for(int i=0;i<8;i++){
		for(int t=0;t<8;t++){
			if(range[point(i,t)]==0){
//			cout << i << ',' << t << endl;
			range[point(i,t)]=2;
			if(!flag){
				p=point(i,t);
				flag = true;
			}
			biaoji(i,t); 
			total++;
			}
		}
	}
}
int main(){
	int total=0;
	while(total!=9){
		work(total);
		if(total!=9){
			range.clear();
			range(p)=1;
		}
	}
	for(int i=0;i<8;i++){
		for(int t=0;t<8;t++){
			if(range[point(i,t)]==2)cout << '(' << i << ',' << t << ')' << ' ' ;
		}
	}
	cout << endl;
}