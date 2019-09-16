#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>

using namespace std;

const int maxn=1000+10;


int max_len[maxn];
string buffer;
vector<string> s[maxn];

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int c=0,r=0;
	
	while(getline(cin,buffer)){
		stringstream ss;
		ss<<buffer;
		
		string temp;
		while(ss>>temp){
			max_len[c]=max(max_len[c],(int)temp.length());
			c++;
			s[r].push_back(temp);
		}
		
		r++;c=0;
	}
	
	
	for(int i=0;i<r;i++){
		int len=s[i].size();
		for(int j=0;j<len-1;j++){
			cout<<s[i][j]<<" ";
			
			int count=max_len[j]-s[i][j].length();
			
			while(count--){
				cout<<" ";
			}
		}
		
		cout<<s[i][len-1]<<endl;
	}
	
	
	
	
	//fclose(stdin);
	//fclose(stdout);

}
