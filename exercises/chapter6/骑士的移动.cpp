#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

const int maxn=8;
const int dr[]={-2,-1,1,2,2,1,-1,-2};
const int dc[]={1,2,2,1,-1,-2,-2,-1};

int vis[maxn][maxn];
string bg;
string ed;
int count;

struct Node{
	int r,c;
	int step;
	Node(int r=0,int c=0,int step=0):r(r),c(c),step(step){}
};



bool inbound(int r,int c){
	return r>=0&&r<8&&c>=0&&c<8;
}
int main(void){
	while(cin>>bg>>ed){
		memset(vis,0,sizeof(vis));
		count=0;
		
		int bgr=bg[1]-'1';
		int bgc=bg[0]-'a';
		int edr=ed[1]-'1';
		int edc=ed[0]-'a';
		Node begin=Node(bgr,bgc,0);
		
		queue<Node> q;
		q.push(begin);
		
		while(!q.empty()){
			Node now=q.front();q.pop();
			
			vis[now.r][now.c]=1;
			
			if(now.r==edr&&now.c==edc){
				count=now.step;
				break;
			}
			
			for(int i=0;i<8;i++){
				int rn=now.r+dr[i];
				int rc=now.c+dc[i];
				
				if(!vis[rn][rc]&&inbound(rn,rc)){
					q.push(Node(rn,rc,now.step+1));
				}
			}
		}
		
		cout<<"To get from "<<bg<<" to "<<ed<<" takes "<<count<<" knight moves."<<endl;
	}
}
