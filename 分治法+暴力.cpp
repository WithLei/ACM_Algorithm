#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef pair<int,int> point;
#define random(x) rand()%x
const int RANDOMSIZE = 50;

vector<point>result;//结果储存 

struct Point{
    int x;
    int y;
} P[102];

int dis(int i, int j)  
{  
    return ((P[i].x-P[j].x)*(P[i].x-P[j].x)  
                + (P[i].y-P[j].y)*(P[i].y-P[j].y));  
} 

//随机数据并且输出所有的点
void RandomPoint(int n){
	srand((int)time(0));
	for(int i =0;i<n;i++)//输入n个点的数据 
	{
		P[i].x = random(RANDOMSIZE);
		P[i].y = random(RANDOMSIZE);
	}
	cout << "随机点:" << endl; 
	for(int i =0;i<n;i++)//统一输出n个点的数据 
	{
		cout<<i+1<< ".(" <<P[i].x<<","<<P[i].y<<")"<<endl;
	}
	cout<<endl;
} 


//声明函数 暴力 
void BruteForceClosetPoints(int n)
{
	point temp;
	int dmin=dis(0,1);
	temp = make_pair(0,1);
	result.push_back(temp);
	for(int i = 0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(i==0&&j==1)continue;
			if(dis(i ,j)<dmin)
			{
				dmin = dis(i ,j);
				temp=make_pair(i,j);
				result.clear();
				result.push_back(temp);
			}
			else if(dis(i ,j)==dmin)
			{
				dmin = dis(i ,j);
				temp=make_pair(i,j);
				result.push_back(temp);
			}
		}
	}
	//输出
	cout << "暴力法算得最近点：" << endl;
	for(vector<point>::iterator it = result.begin();it !=result.end();it++){
		point temp = *it;
		cout << "(" << P[temp.first].x << "," << P[temp.first].y << ")" << " and "
			<< "(" << P[temp.second].x << "," << P[temp.second].y << ")" << 
			" Length:" << (double)sqrt(dis(temp.first,temp.second)) << endl;
	} 
	cout << endl;
}

//分治法 
int tmpt[200];
bool cmpxy(const Point& a, const Point& b)  
{  
    if(a.x != b.x)  
        return a.x < b.x;  
    return a.y < b.y;  
}  
  
bool cmpy(const int& a, const int& b)  
{  
    return P[a].y < P[b].y;  
}   

//声明函数 时间复杂度为O(n*logn*logn)
int Closest_Pair(int left, int right)  
{  
	point temp;
    int d = 200000;  //max
    if(left==right)  
        return d;
    if(left + 1 == right)  
        return dis(left, right);  
    int mid = (left+right)>>1;  
    int d1 = Closest_Pair(left,mid);  
    int d2 = Closest_Pair(mid+1,right);  
    d = min(d1,d2);  
    int i,j,k=0;  
    //分离出宽度为d的区间  
    for(i = left; i <= right; i++)  
    {  
        if(fabs(P[mid].x-P[i].x) <= d)  
            tmpt[k++] = i;  
    }  
    sort(tmpt,tmpt+k,cmpy);  
    //线性扫描  
    for(i = 0; i < k; i++)  
    {  
        for(j = i+1; j < k && P[tmpt[j]].y-P[tmpt[i]].y<d; j++)  
        {  
            int d3 = dis(tmpt[i],tmpt[j]);  
            if(d >= d3){
            	d = d3;
            	temp=make_pair(tmpt[i],tmpt[j]);
				result.push_back(temp);
			}
        }  
    }  
    return d;
}  


int main(int argc, char *argv[])
{
	int n,length;
	cout << "请输入需要随机的点的个数" << endl; 
	cin >> n ;
	RandomPoint(n);
	
	BruteForceClosetPoints(n);//暴力法遍历，寻求出最近点 
	
	result.clear();
	sort(P,P+n,cmpxy);
	length = Closest_Pair(0, n-1);//分治法，寻求最近点 
	sort(result.begin(),result.end()); //排序   
    result.erase(unique(result.begin(),result.end()),result.end());//unique删除重复元素 
    
    vector<point>::iterator it = result.begin();
    point MinPoint = *it;
    for(++it;it !=result.end();it++){
    	point TempPoint = *it;
    	if(dis(MinPoint.first,MinPoint.second)>dis(TempPoint.first,TempPoint.second))MinPoint=TempPoint;
	}
	for(vector<point>::iterator it = result.begin();it !=result.end();it++){
		point TempPoint = *it;
		if(dis(MinPoint.first,MinPoint.second)<dis(TempPoint.first,TempPoint.second))
			it = result.erase(it)-1;
	}
	//分治法输出
	cout << "分治法算得最近点：" << endl;
	for(vector<point>::iterator it = result.begin();it !=result.end();it++){
		point temp = *it;
		cout << "(" << P[temp.first].x << "," << P[temp.first].y << ")" << " and "
			<< "(" << P[temp.second].x << "," << P[temp.second].y << ")" << 
			" Length:" << (double)sqrt(dis(temp.first,temp.second)) << endl;
	} 
	cout << endl;
	return 0;
}

