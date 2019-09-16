#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

#define DEBUG
const int limit=30;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int target[3][3];
int x,y;
int ans;

struct Cube{
	int top,right,face;
	Cube(int t=1,int r=3,int f=2):
		top(t),
		right(r),
		face(f){
		}
};
vector< vector<Cube> > board(3);

inline int get_cnt(){
	int count=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j].top!=target[i][j]) count++;
		}
	}
	return count;
}

void dfs(int r,int c,int prer,int prec,int cur){
	int diff=get_cnt();
	
	if(diff==0){
		if(cur<ans) ans=cur;
		return;
	}
	
	if(diff>ans-cur) return;
	
	for(int dir=0;dir<4;dir++){
		int nr=r+dx[dir];
		int nc=c+dy[dir];
		
		if(nr<0||nr>=3||nc<0||nc>=3||(prer==nr&&prec==nc)) continue;
		
		Cube now =board[r][c];
		Cube next=board[nr][nc];
		
		if(dx[dir]){
			board[r][c].top=next.face;
			board[r][c].face=next.top;
			board[r][c].right=next.right; 
		}
		else{
			board[r][c].top=next.right;
			board[r][c].right=next.top;
			board[r][c].face=next.face;
		}
		board[nr][nc].top=0;board[nr][nc].face=0;board[nr][nc].right=0;
		
		dfs(nr,nc,r,c,cur+1);
		
		board[r][c]=now;
		board[nr][nc]=next;
	}
}
void solve(){
	ans=31;
	dfs(x,y,-1,-1,0);
	
}
int main(void){
	
	#ifdef _DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	string buffer;
	for(int i=0;i<3;i++) board[i].resize(3);
	while(cin>>y>>x&&y){
		y--;x--;
		for(int i=0;i<9;i++){
			cin>>buffer;
			if(buffer=="W"){
				target[i/3][i%3]=1;
			}else if(buffer=="R"){
				target[i/3][i%3]=2;
			}else if(buffer=="B"){
				target[i/3][i%3]=3;
			}else if(buffer=="E"){
				target[i/3][i%3]=0;
			}
			board[i/3][i%3]=Cube();
		}
		board[x][y]=Cube(0,0,0);
		
		solve();
		printf("%d\n",ans>=31?-1:ans);
	}
	
	fclose(stdin);
	fclose(stdout);
} 
