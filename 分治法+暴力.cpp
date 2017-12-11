#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef pair<int,int> point;
#define random(x) rand()%x
const int RANDOMSIZE = 50;

vector<point>result;//������� 

struct Point{
    int x;
    int y;
} P[102];

int dis(int i, int j)  
{  
    return ((P[i].x-P[j].x)*(P[i].x-P[j].x)  
                + (P[i].y-P[j].y)*(P[i].y-P[j].y));  
} 

//������ݲ���������еĵ�
void RandomPoint(int n){
	srand((int)time(0));
	for(int i =0;i<n;i++)//����n��������� 
	{
		P[i].x = random(RANDOMSIZE);
		P[i].y = random(RANDOMSIZE);
	}
	cout << "�����:" << endl; 
	for(int i =0;i<n;i++)//ͳһ���n��������� 
	{
		cout<<i+1<< ".(" <<P[i].x<<","<<P[i].y<<")"<<endl;
	}
	cout<<endl;
} 


//�������� ���� 
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
	//���
	cout << "�������������㣺" << endl;
	for(vector<point>::iterator it = result.begin();it !=result.end();it++){
		point temp = *it;
		cout << "(" << P[temp.first].x << "," << P[temp.first].y << ")" << " and "
			<< "(" << P[temp.second].x << "," << P[temp.second].y << ")" << 
			" Length:" << (double)sqrt(dis(temp.first,temp.second)) << endl;
	} 
	cout << endl;
}

//���η� 
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

//�������� ʱ�临�Ӷ�ΪO(n*logn*logn)
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
    //��������Ϊd������  
    for(i = left; i <= right; i++)  
    {  
        if(fabs(P[mid].x-P[i].x) <= d)  
            tmpt[k++] = i;  
    }  
    sort(tmpt,tmpt+k,cmpy);  
    //����ɨ��  
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
	cout << "��������Ҫ����ĵ�ĸ���" << endl; 
	cin >> n ;
	RandomPoint(n);
	
	BruteForceClosetPoints(n);//������������Ѱ�������� 
	
	result.clear();
	sort(P,P+n,cmpxy);
	length = Closest_Pair(0, n-1);//���η���Ѱ������� 
	sort(result.begin(),result.end()); //����   
    result.erase(unique(result.begin(),result.end()),result.end());//uniqueɾ���ظ�Ԫ�� 
    
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
	//���η����
	cout << "���η��������㣺" << endl;
	for(vector<point>::iterator it = result.begin();it !=result.end();it++){
		point temp = *it;
		cout << "(" << P[temp.first].x << "," << P[temp.first].y << ")" << " and "
			<< "(" << P[temp.second].x << "," << P[temp.second].y << ")" << 
			" Length:" << (double)sqrt(dis(temp.first,temp.second)) << endl;
	} 
	cout << endl;
	return 0;
}

