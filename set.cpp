#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 10000+4;
int main(){
	string input,buf;
	set<string> s;
	while(cin >> input){
		for(int i=0;i<input.length();i++)
			if(isalpha(input[i]))input[i]=tolower(input[i]);
			else input[i]=' ';
		stringstream ss(input);
		while(ss >> buf)s.insert(buf);
	}
	for(set<string>::iterator it=s.begin();it!=s.end();++it)
		cout << *it  << "\n";
	return 0;
}