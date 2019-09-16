#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=1000+5;

int n;
int vis[maxn];
int ans[maxn];

bool dfs(int cur,int maxd){
	if(ans[cur]==n) return true;
	if(cur==maxd) return false;
	
	int maxv=-1;
	for(int i=0;i<=cur;i++)  maxv=max(maxv,ans[i]);
	if((maxv<<(maxd-cur))<n) return false;
	
	int t1,t2;
	int sum,sub;
	/*for(int i=cur;i>=0;i--){
		for(int j=i;j>=0;j--){
			t1=ans[i];
			t2=ans[j];
			sum=t1+t2;
			sub=t1-t2;
			if(!vis[sum]){
				vis[sum]=1;
				ans.push_back(sum);
				if(dfs(cur+1,maxd)) return true;
				ans.pop_back();
				vis[sum]=0;
			}
			if(sub>0&&!vis[sub]){
				vis[sub]=1;
				ans.push_back(sub);
				if(dfs(cur+1,maxd)) return true;
				ans.pop_back();
				vis[sub]=0;
			}
		}
	}*/
	
	for(int i=cur;i>=0;i--){
		ans[cur+1]=ans[cur]+ans[i];
		if(dfs(cur+1,maxd)) return true;
		ans[cur+1]=abs(ans[cur]-ans[i]);
		if(dfs(cur+1,maxd)) return true;
	}
	
	return false;
}
int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>n&&n){
		if(n==1){
			printf("%d\n",0);
			continue; 
		}
		
		int maxd=1;
		for(;maxd<14;maxd++){
			//ans.clear();
			//ans.push_back(1);
			//memset(vis,0,sizeof(vis));
			//vis[1]=1;
			ans[0]=1;
			if(dfs(0,maxd)) break;
		}
		printf("%d\n",maxd);		
	}
	
	return 0;
	
	//fclose(stdin);
	//fclose(stdout);
} 
