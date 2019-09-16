#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=16+5;

int n;
int kcase=0;
int vis[maxn];
int res[maxn];
bool isprime[2*maxn];

bool is_prime(int num){
	for(int i=2;i<num;i++){
		if(num%i==0) return false;
	}
	
	return true;
}

void dfs(int cur){
	if(cur==n&&isprime[1+res[n-1]]){
		for(int i=0;i<n-1;i++) printf("%d ",res[i]);
		printf("%d\n",res[n-1]);
		return;
	}
	
	
	for(int i=2;i<=n;i++){
		if(!vis[i]&&isprime[res[cur-1]+i]){
			res[cur]=i;
			vis[i]=1;
			dfs(cur+1);
			vis[i]=0;
		}
	}
}

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	for(int i=2;i<=2*maxn;i++) isprime[i]=is_prime(i);	
	while(cin>>n){
		res[0]=1;
		memset(vis,0,sizeof(vis));
		if(kcase) printf("\n");
		printf("Case %d:\n",++kcase);
		dfs(1);
	}
	
	//fclose(stdin);
	//fclose(stdout);
}
