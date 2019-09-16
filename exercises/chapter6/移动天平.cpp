#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;


string buffer;
int sum;
int ans;
map<long long,int> m;

void dfs(int depth,int bg,int len){
	if(buffer[bg]=='['){
		
		int count=0;
		
		for(int i=bg+1;i<len;i++){
			if(buffer[i]=='[') count++;
			else if(buffer[i]==']') count--;
			else if(count==0&&buffer[i]==','){
				dfs(depth+1,bg+1,i-1);
				dfs(depth+1,i+1,len-1);
				break; 
			}
		}
	}else{
		
		long long weight=0;
		
		for(int i=bg;i<=len;i++){
			weight=weight*10+buffer[i]-'0';
		}
		
		sum++;
		
		m[weight<<depth]++;
		
		ans=max(ans,m[weight<<depth]);
	}
}
int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>buffer;
		
		ans=0;sum=0;
		m.clear();
		
		dfs(0,0,buffer.size()-1);
		
		
		printf("%d\n",sum-ans); 
	}
}
