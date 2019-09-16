#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=20+5;
const int maxm=210+5;
const int maxk=50+5;
const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};
const char dir[]="ensw";

struct Node{
	int x,y;
	int dir;
	Node(int x=0,int y=0):x(x),y(y){};
};
int n,k;
int count;
int g[maxm*2][maxm*2];
int sum[maxn];
vector<Node> ans;

inline bool ifbump(int x,int y,int dir,int len){
	int i;
	for(i=1;i<=len;i++){
		x+=dx[dir];
		y+=dy[dir];
		
		if(g[x][y]==-1) return true;
	}
	return false; 
}

void dfs(int cur){
	if(cur==n){
		if(ans[cur].x==0&&ans[cur].y==0){
			for(int i=1;i<=cur;i++) printf("%c",dir[ans[i].dir]); 
			printf("\n");
			count++;
			return;
		}
		return;
	}
	
	Node last=ans[cur];
	
	if(sum[n]-sum[cur]<abs(last.x)+abs(last.y)) return;
	
	for(int dir=0;dir<4;dir++){
		if(last.dir==dir||last.dir+dir==3) continue;
		int xx=last.x+dx[dir]*(cur+1);
		int yy=last.y+dy[dir]*(cur+1);
				
		if(!ifbump(last.x+maxm,last.y+maxm,dir,cur+1)&&!g[xx+maxm][yy+maxm]){
			g[xx+maxm][yy+maxm]=1;
			Node next(xx,yy);
			next.dir=dir;
			ans.push_back(next);
			dfs(cur+1);
			ans.pop_back();
			g[xx+maxm][yy+maxm]=0;
		}
	}
}
void solve(){
	Node bg(0,0);
	bg.dir=-1;
	ans.push_back(bg);
	dfs(0);
	
	printf("Found %d golygon(s).\n\n",count);
}

void init(){
	memset(g,0,sizeof(g));
	count=0;
	ans.clear();
}

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	
	sum[0]=0;
	for(int i=1;i<=maxn;i++){
		sum[i]=sum[i-1]+i;
	}
	cin>>T; 
	while(T--){
		cin>>n>>k;
		init();
		int x,y;
		for(int i=0;i<k;i++){
			cin>>x>>y;
			g[x+maxm][y+maxm]=-1;
		}
		
		solve();
	}
	//fclose(stdin);
	//fclose(stdout);
} 
