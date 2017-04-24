#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1010
int dis[MAXN][MAXN];
int que[MAXN*MAXN];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int T,N,M,SX,SY,FX,FY;
int judge(int x,int y){
    if(x<1 || x>N || y<1 || y>M)
        return 0;
    return 1;
}
int bfs(){
    int tail=0,front=0,curx,cury,i,nxtx,nxty;
    dis[SX][SY]=1;
    que[front++]=(SX-1)*M+(SY-1);
    while(tail<front){
        curx=que[tail]/M+1;
        cury=que[tail++]%M+1;
        for(i=0;i<4;i++){
            nxtx=curx+dir[i][0];
            nxty=cury+dir[i][1];
            if(judge(nxtx,nxty)==0)
                continue;
            if(dis[nxtx][nxty]!=-1)
                continue;
            dis[nxtx][nxty]=dis[curx][cury]+1;
            que[front++]=(nxtx-1)*M+(nxty-1);
            if(nxtx==FX && nxty==FY)
                return dis[nxtx][nxty];
        }
    }
    return -1;
}
int main(){
    int i,x,y,ans;
    while(~scanf("%d%d%d",&N,&M,&T)){
        memset(dis,-1,sizeof(dis));
        scanf("%d%d%d%d",&SX,&SY,&FX,&FY);
        for(i=0;i<T;i++){
            scanf("%d%d",&x,&y);
            dis[x][y]=-2;
        }    
        ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}
//#BFS
//数据输入：
//第一行 N,M,T, N为行数，M为列数，T为障碍数(1<=N,M,T<=1000).
//第二行起点坐标sx,sy,终点坐标FX,FY(1<=SX,FX<=N)(1<=SY,FY<=M)
//接下来T行，每行为障碍的坐标(终点坐标有可能是不可达的) 