#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define DEBUG
const int maxstate=1000000;
const int maxn=15+5;
typedef int State[2];
typedef int Path [2];
 
int n,m,s,t;
int g[maxn][maxn];
State stats[maxstate];
Path  path[maxstate];
int fa[maxstate];
int dist[maxstate];
int vis[1<<16][maxn];
int ans;

void solve(){
	int front,rear;
	front=1;rear=2;
	while(front<rear){
		State &stat=stats[front];
		if(stat[0]==t){
			ans=front;
			return;
		}
		for(int i=1;i<=n;i++){
			if(!(stat[1]&(1<<i))&&stat[0]!=i) continue;
			for(int j=1;j<=n;j++){
				if((stat[1]&(1<<j))||!g[i][j]||stat[0]==j) continue;
				State &temp=stats[rear];
				memcpy(&temp,&stat,sizeof(stat));
				if(stat[0]==i) temp[0]=j;
				else temp[1]^=1<<i|1<<j;
				path[rear][0]=i;
				path[rear][1]=j;
				dist[rear]=dist[front]+1;
				fa[rear]=front;
				if(!vis[temp[1]][temp[0]]){
					vis[temp[1]][temp[0]]=1;
					rear++;
				}
			}
		}
		front++;
	}
}
void print_path(int cur){
	if(cur==1) return;
	print_path(fa[cur]);
	printf("%d %d\n",path[cur][0],path[cur][1]);
}
int main(void){
	#ifdef _DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int T;
	int kcase=0;
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>t;
		memset(g,0,sizeof(g));
		memset(fa,0,sizeof(fa));
		memset(vis,0,sizeof(vis));
		memset(path,0,sizeof(path));
		stats[1][1]=0;
		dist[1]=0; 
		ans=-1;
		int a;
		for(int i=0;i<m;i++){
			cin>>a;
			stats[1][1]|=1<<a;
		}
		int u,v;
		for(int i=0;i<n-1;i++){
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
		stats[1][0]=s;
		solve();
		printf("Case %d: %d\n",++kcase,ans==-1?-1:dist[ans]);
		if(ans!=-1) print_path(ans);
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
} 
