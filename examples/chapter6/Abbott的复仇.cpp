#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib> 
#include<cstring>
#include<queue> 
#include<vector>
using namespace std;

const int maxn=9+1;
const char *dirs="NESW";
const char *turns="FLR";
const int dr[4]={-1,0,1,0};
const int dc[4]={0,1,0,-1};
int r0,c0,r1,c1,re,ce,r,c;
char dir0;
int dir;
int maze[maxn][maxn][4][3];
int d[maxn][maxn][4];

int dir_id(char c){return strchr(dirs,c)-dirs;}
int turn_id(char c){return strchr(turns,c)-turns;}

struct Node{
	int r,c;
	int dir;
	Node(int rr=0,int cc=0,int dirr=0){
		r=rr;
		c=cc;
		dir=dirr;
	}
}p[maxn][maxn][4];


bool inside(int r,int c){
	if(r<0||r>=maxn||c<0||c>=maxn){
		return false;
	}
	return true;
}


void input(){
	memset(maze,0,sizeof(maze));
	
	cin>>r0>>c0>>dir0>>re>>ce;
    dir=dir_id(dir0);
	r1=r0+dr[dir];
	c1=c0+dc[dir];
	
	string direction;
	while(cin>>r){
		if(r==0) break;
		cin>>c;
		while(cin>>direction&&direction!="*"){
			int len=direction.size();
			for(int i=1;i<len;i++){
				maze[r][c][dir_id(direction[0])][turn_id(direction[i])]=1;
			}
		}
	}
}

Node walk(const Node &now,int turn){
	int dir=now.dir;
	if(turn==1){
		dir=(4+dir-1)%4; 
	}
	else if(turn==2){
		dir=(dir+1)%4;
	}
	
	return Node(now.r+dr[dir],now.c+dc[dir],dir); 
}

void print_ans(Node n){
	/*
	vector<Node> ans;
	
	while(true){
		ans.push_back(n);
		if(d[n.r][n.c][n.dir]==0) break;
		n=p[n.r][n.c][n.dir];
	}
	ans.push_back(Node(r0,c0,dir));
	
	int count=0;
	for(int i=ans.size()-1;i>=0;i--){
		if(count%10==0)printf(" ");
		printf(" (%d,%d)",ans[i].r,ans[i].c);
		if(++count%10==0) printf("\n");
	}
	
	if(ans.size()%10!=0) printf("\n");*/
	if(d[n.r][n.c][n.dir]==0) {
		printf(" (%d,%d)",r0,c0);
		printf(" (%d.%d)",n.r,n.c);
		return;
	}
	
	print_ans(p[n.r][n.c][n.dir]);

	printf(" (%d,%d)",n.r,n.c);	
}

void bfs(){
	queue<Node> q;
	
	memset(d,-1,sizeof(d));
	
	Node begin=Node(r1,c1,dir);
	
	d[begin.r][begin.c][begin.dir]=0;
	
	q.push(begin);
	
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		
		if(now.r==re&&now.c==ce){
			print_ans(now);
			return; 
		}
		
		for(int i=0;i<3;i++){
			Node next=walk(now,i);
			if(maze[now.r][now.c][now.dir][i]&&inside(next.r,next.c)
			&&d[next.r][next.c][next.dir]<0){
				d[next.r][next.c][next.dir]=d[now.r][now.c][now.dir]+1;
				p[next.r][next.c][next.dir]=now;
				q.push(next);
			}
		}
	}
	
	cout<<"  No Solution Possible"<<endl;
}
 
int main(void){
	 
	string name;
	while(cin>>name&&name!="END"){
	    input();
		cout<<name<<endl;
		bfs();
	}
} 
