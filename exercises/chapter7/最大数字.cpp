#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=15+5;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

string ans;
char maze[maxn][maxn];
char p[maxn*2]; 
int vis[maxn][maxn];
int vis2[maxn][maxn];
int r,c;
int cnt;

struct Square{
	pair<int,int> pos;
	Square(pair<int,int> pos):pos(pos){}
};
int bfs(int x,int y){
	queue<Square> q;
	q.push(Square(make_pair(x,y)));
	vis2[x][y]=1;
	int len=0;
	while(!q.empty()){
		Square s=q.front();q.pop();
		for(int i=0;i<4;i++){
			int xx=s.pos.first+dx[i];
			int yy=s.pos.second+dy[i];
			
			if(xx<0||xx>=r||yy<0||yy>=c) continue;
			if(vis[xx][yy]||vis2[xx][yy]||maze[xx][yy]=='#') continue;
			vis2[xx][yy]=1;
			p[len++]=maze[xx][yy];
			q.push(Square(make_pair(xx,yy)));
		}
	}
	
	return len;
}
void dfs(int x,int y,string path){
	int len;
	if(path.length()>ans.length()||(ans.length()==path.length()&&ans<path)) ans=path;
	else{
		memset(vis2,0,sizeof(vis2));
		len=bfs(x,y);
		if(len+path.length()<ans.length()) return;
		sort(p,p+len,greater<int>());
		string tmp=path;
		for(int i=0;i<len;i++) tmp+=p[i];
		if(ans.length()==tmp.length()&&ans>tmp) return;
	}
	
	for(int dir=0;dir<4;dir++){
		int xx=x+dx[dir];
		int yy=y+dy[dir];
		
		if(xx<0||xx>=r||yy<0||yy>=c) continue;
		if(maze[xx][yy]=='#') continue;
		if(vis[xx][yy])continue;
		vis[xx][yy]=1;
		dfs(xx,yy,path+maze[xx][yy]);
		vis[xx][yy]=0;
	}
}
void solve(){
 	int sr,sc;
 	string path;
 	memset(vis,0,sizeof(vis));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(maze[i][j]=='#') continue;
			path="";
			vis[i][j]=1;
			dfs(i,j,path+maze[i][j]);
			vis[i][j]=0;
		} 
		
	}
}
int main(void){
	string buffer;
	while(cin>>r>>c&&r){
		ans="";
		for(int i=0;i<r;i++){
			cin>>buffer;
			for(int j=0;j<c;j++){
				maze[i][j]=buffer[j];
			} 
		}
		solve();
		cout<<ans<<endl;
	}
} 
