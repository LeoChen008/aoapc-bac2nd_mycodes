#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

const int maxn=200+5;

struct Node{
	int v[3];
	int volume;
	Node(int c=0){
		v[0]=0;
		v[1]=0;
		v[2]=c;
		volume=0;
	}
	
	bool operator<(const Node &n) const{
		return volume>n.volume;
	}
};

int vis[maxn][maxn];
int ans[maxn];
int cap[3];
int d;


void bfs(){
	priority_queue<Node> q;
	
	Node start(cap[2]);
	q.push(start);
	vis[0][0]=1;
	
	while(!q.empty()){
		Node temp=q.top();q.pop();
		
		for(int i=0;i<3;i++){
			int v=temp.v[i];
			if(ans[v]<0||temp.volume<ans[v]){
				ans[v]=temp.volume;
			}
		}
		
		if(ans[d]>=0) break;
		
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i!=j&&temp.v[i]>0&&temp.v[j]<cap[j]){
					int amount=min(temp.v[i],cap[j]-temp.v[j]);
					Node next;
					memcpy(&next,&temp,sizeof(temp));
					next.v[i]-=amount;
					next.v[j]+=amount;
					next.volume+=amount;
					
					if(!vis[next.v[0]][next.v[1]]){
						vis[next.v[0]][next.v[1]]=1;
						q.push(next);
					}
				}
			}
		}
	}
	
	while(d>=0){
		if(ans[d]>=0){
			printf("%d %d\n",ans[d],d);
			break;
		}
		d--;
	}
}

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T,va,vb,vc;
	cin>>T;
	while(T--){
		cin>>va>>vb>>vc>>d;
		cap[0]=va;cap[1]=vb;cap[2]=vc;
		memset(vis,0,sizeof(vis));
		memset(ans,-1,sizeof(ans));
		bfs();
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
