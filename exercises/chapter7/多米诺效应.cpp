#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>

using namespace std;

const int maxn=7;
const int maxm=8;
const int maxd=28+1;
const int dx[]={1,0};
const int dy[]={0,1};
 
int count;
int kcase=0;
int layout[maxn][maxm];
int domino_id[maxn][maxn];
int ans[maxn][maxm];
int vis1[maxn][maxm];
int vis2[maxd];

void dfs(int x,int y,int cur){
	if(cur==28){
		count++;
		for(int i=0;i<maxn;i++){
			for(int j=0;j<maxm;j++){
				printf("%4d",ans[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	} 
	
	if(x==7) return;
	if(y==8){
		for(int i=0;i<8;i++)if(vis1[x][i]==0) return;
		dfs(x+1,0,cur);
		return;
	}
	if(vis1[x][y]){
		dfs(x,y+1,cur);
		return;
	}
	
	for(int dir=0;dir<2;dir++){
		if(x==6&&dir==0) continue;
		if(y==7&&dir==1) continue; 
		int xx=x+dx[dir];
		int yy=y+dy[dir];
		
		int a=layout[x][y];
		int b=layout[xx][yy];
				
		if(!vis1[xx][yy]&&!vis2[domino_id[a][b]]){
			vis1[xx][yy]=vis1[x][y]=1;
			vis2[domino_id[a][b]]=1;
			ans[x][y]=ans[xx][yy]=domino_id[a][b];
			dfs(x,y+1,cur+1);
			vis1[xx][yy]=vis1[x][y]=0;
			vis2[domino_id[a][b]]=0;
		}
	}
}

void init(){
	count=0;
	memset(vis1,0,sizeof(vis1));
	memset(ans,0,sizeof(ans));
	memset(vis2,0,sizeof(vis2));
}
void solve(){
	if(kcase) printf("\n\n\n");
	printf("Layout #%d:\n\n",++kcase);
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxm;j++){
			printf("%4d",layout[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("Maps resulting from layout #%d are:\n\n",kcase);
	
	dfs(0,0,0);
	
	printf("There are %d solution(s) for layout #%d.\n",count,kcase);
}
int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int id=1;
	for(int i=0;i<maxn;i++){
		for(int j=i;j<maxn;j++){
			domino_id[i][j]=domino_id[j][i]=id++;
		}
	}
	
	
	int a;
	while(scanf("%d",&a)!=EOF){
		init();
		
		layout[0][0]=a;
		for(int i=0;i<maxn;i++){
			for(int j=0;j<maxm;j++){
				if(i==0&&j==0) continue;
				cin>>layout[i][j];
			}
		}
		
		solve();
	}
	
	//fclose(stdin);
	//fclose(stdout);
}
