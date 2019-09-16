#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=10+5;
const int maxm=maxn*maxn;
const int res=maxm/2;
int n,m;
int ans;
int board[maxn][maxn];
int visr[maxn];
int visc[maxn];
int viss[maxm];
int visbs[maxm];

bool judge(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]==0&&!(visr[i]||visc[j]||viss[res+i+j]||visbs[res+i-j])) return false;
		}
	}
	
	return true;
}
bool dfs(int r,int c,int cur,int maxd){
	if(cur==maxd){
		if(judge()) return true;
		return false;
	}
	
	/*if(c==m) return dfs(r+1,0,cur,maxd); 
	if(r>=n) return false;
	
	visr[r]++;visc[c]++;viss[res+r+c]++;visbs[res+r-c]++;
	if(dfs(r,c+1,cur+1,maxd)) return true;
	visr[r]--;visc[c]--;viss[res+r+c]--;visbs[res+r-c]--;
	
	if(dfs(r,c+1,cur,maxd)) return true; 
	return false;*/
	
	while(r<n){
		while(c<m){
			visr[r]++;visc[c]++;viss[res+r+c]++;visbs[res+r-c]++;
			if(dfs(r,c+1,cur+1,maxd)) return true;
			visr[r]--;visc[c]--;viss[res+r+c]--;visbs[res+r-c]--;
			c++;
		}
		r++;
		c%=m;
	}
	return false;
}

void solve(){
	ans=n;
	int maxd;
	for(maxd=1;maxd<=n;maxd++){
		if(dfs(0,0,0,maxd)){
			ans=maxd;
			return;
		}
	}
} 
int main(void){
	string buffer;
	int kcase=0;
	while(cin>>n&&n){
		cin>>m;
		memset(visr,0,sizeof(visr));
		memset(visc,0,sizeof(visc));
		memset(viss,0,sizeof(viss));
		memset(visbs,0,sizeof(visbs));
		
		for(int i=0;i<n;i++){
			cin>>buffer;
			for(int j=0;j<m;j++){
				if(buffer[j]=='X'){
					board[i][j]=0;
				}
				else board[i][j]=-1;
			}
		}
		solve();
		printf("Case %d: %d\n",++kcase,ans);
	}
} 
