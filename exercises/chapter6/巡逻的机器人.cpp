#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=20+5;
const int dr[]={1,-1,0,0};
const int dc[]={0,0,1,-1};

int map[maxn][maxn];
int vis[maxn][maxn];
int m,n;
int k;
int ans;
struct Node{
	int r,c;
	int step;
	int k;
	
	Node(int r=0,int c=0,int step=0,int k=0):r(r),c(c),step(step),k(k){}
};


bool inbound(int x,int y){
	return x>=1&&x<=m&&y>=1&&y<=n;
}
int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>m>>n;
		cin>>k;
		
		memset(map,-1,sizeof(map));
		memset(vis,0,sizeof(vis));
		ans=-1;
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>map[i][j];
			}
		}
		
		queue<Node> q;
		q.push(Node(1,1,0,0));
		
		while(!q.empty()){
			Node now=q.front();q.pop();
			
			vis[now.r][now.c]=1;
			
			if(now.r==m&&now.c==n){
				ans=now.step;
				break;
			}
			
			for(int i=0;i<4;i++){
				int rn=now.r+dr[i];
				int cn=now.c+dc[i];
				
				if(!vis[rn][cn]&&inbound(rn,cn)){
					
					if(map[rn][cn]==0){
						q.push(Node(rn,cn,now.step+1,0));
					}
					else{
						if(now.k+1<=k){
							q.push(Node(rn,cn,now.step+1,now.k+1));
						}
					}
				}
			}
		}
		
		printf("%d\n",ans);
	}
} 
