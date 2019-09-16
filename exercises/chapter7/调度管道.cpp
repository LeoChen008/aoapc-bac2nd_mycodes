#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int maxn=20+5;
const int maxm=5;
int n;
int ans;
int len;//合法距离的个数 
int table[maxm];
int jump[maxn];   //存储相对前一个位置的合法距离 


bool judge(int *t,int a){
	for(int i=0;i<maxm;i++){
		if(table[i]&(t[i]>>a)) return false;
	}
	return true;
}
void dfs(int *ct,int cur,int s){
	
	if(s+jump[0]*(10-cur)>ans) return;
	
	if(cur==10){
		if(s<ans){
			ans=s;
			return;
		}
		return;
	}
	
	for(int i=0;i<len;i++){
		if(judge(ct,jump[i])){
			int nct[maxm];
			for(int j=0;j<maxm;j++){
				nct[j]=table[j]|(ct[j]>>jump[i]);
			} 
			dfs(nct,cur+1,s+jump[i]);
		}
	}
}
void solve(){
	ans=n*10;
	len=0; 
	
	for(int i=1;i<=n;i++){
		if(judge(table,i)){
			jump[len++]=i;
		}
	}
	
	dfs(table,1,n);
}
int main(void){
	 while(cin>>n&&n){
	 	getchar();
	 	string buffer;
	 	
	 	memset(table,0,sizeof(table));
	 	
	 	for(int i=0;i<maxm;i++){
	 		getline(cin,buffer);
	 		for(int j=0;j<n;j++){
	 			if(buffer[j]=='X') table[i]|=(1<<j);
			 }
		 }
		 
		 solve();
		 printf("%d\n",ans);
	 }
} 
