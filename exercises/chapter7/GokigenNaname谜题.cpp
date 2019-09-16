#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>

using namespace std;

#define DEBUG
const int maxn=15;
const int dx[]={-1,1,-1,1};
const int dy[]={-1,1,1,-1};
const int upr[]={0,0};
const int upc[]={0,1};
const int dwr[]={1,1};
const int dwc[]={1,0}; 
const char slashs[]={'\\','/'};
int n,m,mark;
int maze[maxn][maxn];
int edge[maxn][maxn][maxn][maxn];
int vis[maxn][maxn];
char ans[maxn][maxn]; 


inline void retrieve(int x1,int y1,int x2,int y2){
	if(maze[x1][y1]!=-1) maze[x1][y1]++;
	if(maze[x2][y2]!=-1) maze[x2][y2]++;
}

bool judge(int x,int y,int dir){
	if(vis[x][y]==mark) return true;
	vis[x][y]=mark;
	int xx,yy; 
	for(int i=0;i<4;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if((i^1)==dir) continue;
		if(edge[x][y][xx][yy]==0) continue;
		if(judge(xx,yy,i)) return true;
	}
	return false;
}

bool dfs(int r,int c){
	if(c==m){
		r++;c=1;
	}
	if(r==m) return true;
	
	int ur,uc,dr,dc;
	for(int i=0;i<2;i++){
		ur=r+upr[i];uc=c+upc[i];
		dr=r+dwr[i];dc=c+dwc[i];
		if(maze[ur][uc]!=-1&&maze[ur][uc]<1) continue;
		if(maze[dr][dc]!=-1&&maze[dr][dc]<1) continue;
		if(maze[ur][uc]!=-1) maze[ur][uc]--;
		if(maze[dr][dc]!=-1) maze[dr][dc]--;
		
		if(maze[r][c]>0){
			retrieve(ur,uc,dr,dc);
			continue;
		}
		
		if(c==n){
			if(maze[r+upr[1]][c+upr[1]]>0){
				retrieve(ur,uc,dr,dc);
				continue;
			}
		}
		
		if(r==n){
			if(maze[r+dwr[1]][c+dwc[1]]>0){
				retrieve(ur,uc,dr,dc);
				continue;
			}
		}
		
		if(r==n&&c==n){
			if(maze[r+dwr[0]][c+dwc[0]]>0){
				retrieve(ur,uc,dr,dc);
				continue;
			}
		}
		ans[r][c]=slashs[i];
		
		edge[ur][uc][dr][dc]=edge[dr][dc][ur][uc]=1;
		
		mark++;
		if(judge(r,c,-1)){
			edge[ur][uc][dr][dc]=edge[dr][dc][ur][uc]=0;
			retrieve(ur,uc,dr,dc);
			continue;
		}
		
		if(dfs(r,c+1)) return true;
		edge[ur][uc][dr][dc]=edge[dr][dc][ur][uc]=0;
		retrieve(ur,uc,dr,dc);
		
	}
	return false;
}
int main(void){
	
	#ifdef DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	char buffer[maxn];
	cin>>T;
	while(T--){
		cin>>n;
		m=n+1;
		for(int i=1;i<=m;i++){
			scanf("%s",buffer);
			for(int j=0;j<m;j++){
				if(buffer[j]=='.')maze[i][j+1]=-1;
				else maze[i][j+1]=buffer[j]-'0';
			}
		}
		
		memset(edge,0,sizeof(edge));
		memset(vis,0,sizeof(vis));
		mark=1;
		dfs(1,1);
		for(int i=1;i<m;i++){
			for(int j=1;j<m;j++){
				printf("%c",ans[i][j]);
			}
			printf("\n");
		} 
	}
	fclose(stdin);
	fclose(stdout);
} 
