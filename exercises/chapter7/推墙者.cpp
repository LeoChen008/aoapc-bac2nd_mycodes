#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

#define cols 6
#define rows 4

const int wall_dir[4] = {1,2,4,8}; //方向按西、北、东、南 
const int dx[4]    = {0,-1,0,1};   //方向按西、北、东、南 
const int dy[4]    = {-1,0,1,0};   //方向按西、北、东、南 
const char dirs[4] ={'W','N','E','S'};

int maze[rows+1][cols+1]; 
int vis[rows+1][cols+1];
int ans[cols*rows];


void print_ans(int len){
	for(int i=0;i<len;i++){
		printf("%c",dirs[ans[i]]);
	}
	printf("\n");
}

int exit_to(int x,int y){
	if(x==1&&(maze[x][y]&2)==0){
		return 1;
	}
	else if(x==4&&(maze[x][y]&8)==0){
		return 3;
	}
	
	if(y==1&&(maze[x][y]&1)==0){
		return 0;
	}
	else if(y==6&&(maze[x][y]&4)==0){
		return 2;
	}
	
	return -1;
}

bool dfs(int x,int y,int now,int max){
	if(now>=max) return false;
	
	int num=exit_to(x,y);
	if(num!=-1){
		ans[now]=num;
		return true;
	}
	
	int xx,yy;
	int ex_wall=0,ex_wall2=0;
	for(int i=0;i<4;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx<1||xx>rows||yy<1||yy>cols) continue;
		if(vis[xx][yy]) continue;
		
		ex_wall=maze[x][y]&wall_dir[i];
		ex_wall2=maze[xx][yy]&wall_dir[i];
		
		if(ex_wall&&!ex_wall2){
			
		    if(xx+dx[i]>=1&&xx+dx[i]<=rows&&yy+dy[i]>=1&&yy+dy[i]<=cols){
				maze[xx+dx[i]][yy+dy[i]]+=wall_dir[(i+2)%4];
			}
		    maze[xx][yy]+=wall_dir[i];
			maze[x][y]-=wall_dir[i];
			vis[xx][yy]=1;
			ans[now]=i;
			if(dfs(xx,yy,now+1,max)){
				return true;
			}
			if(xx+dx[i]>=1&&xx+dx[i]<=rows&&yy+dy[i]>=1&&yy+dy[i]<=cols){
				maze[xx+dx[i]][yy+dy[i]]-=wall_dir[(i+2)%4];
			}
			maze[xx][yy]-=wall_dir[i];
			maze[x][y]+=wall_dir[i];
			vis[xx][yy]=0;
		}
		else if(!ex_wall){
			vis[xx][yy]=1;
			ans[now]=i;
			if(dfs(xx,yy,now+1,max)){
				return true;
			}
			vis[xx][yy]=0;
		}
	}	
	return false;
}

void solve(int x,int y){
	int d=1;
	for(;d<=rows*cols;d++){
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		if(dfs(x,y,0,d)){
			print_ans(d);
			break;
		}
	}
}
 
int main(void){
	int x,y;
	
	while(cin>>y>>x&&x){
		for(int i=1;i<5;i++){
			for(int j=1;j<7;j++){
				cin>>maze[i][j];
			}
		}
		//show();
		solve(x,y);
	}	
} 
