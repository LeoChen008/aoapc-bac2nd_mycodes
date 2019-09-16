#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

const int maxn=16+5;
const int maxm=256*0.75+5; 

const int dx[]={0,0,1,-1,0};
const int dy[]={1,-1,0,0,0};

int w,h,n,ans;
int g[maxm][5];
int dir[maxm];
int dist1[maxm][maxm][maxm];
int dist2[maxm][maxm][maxm];

struct Node{
	int a,b,c;
	Node(int a=0,int b=0,int c=0,int dist=0):a(a),b(b),c(c){}
}s,e;


bool conflict(int a,int b,int a2,int b2){
	return a2==b2||(a==b2&&b==a2);
}

void double_bfs(){
	memset(dist1,-1,sizeof(dist1));
	memset(dist2,-1,sizeof(dist2)); 
	queue<Node> q1;
	queue<Node> q2;
	
	Node ss=s;
	Node ee=e;
	q1.push(ss);
	q2.push(ee);
	
	dist1[s.a][s.b][s.c]=0;
	dist2[e.a][e.b][e.c]=0;
	
	while(!q1.empty()||!q2.empty()){
		Node t1=q1.front();q1.pop();
		Node t2=q2.front();q2.pop();
		
		Node n1,n2;
		int a2,b2,c2;
		
		for(int i=0;i<dir[t1.a];i++){
			a2=g[t1.a][i];			
			for(int j=0;j<dir[t1.b];j++){
				b2=g[t1.b][j];
				
				if(conflict(t1.a,t1.b,a2,b2)) continue;
				
				for(int k=0;k<dir[t1.c];k++){
					c2=g[t1.c][k];
					
					if(conflict(t1.a,t1.c,a2,c2)) continue;
					if(conflict(t1.b,t1.c,b2,c2)) continue;
					if(dist1[a2][b2][c2]!=-1) continue;
					
					n1.a=a2;n1.b=b2;n1.c=c2;
					q1.push(n1);
					
					dist1[a2][b2][c2]=dist1[t1.a][t1.b][t1.c]+1;
					if(dist2[a2][b2][c2]>=0){
						ans=dist1[a2][b2][c2]+dist2[a2][b2][c2];
						return;
					}
				}
			}
		}
		
		for(int i=0;i<dir[t2.a];i++){
			a2=g[t2.a][i];			
			for(int j=0;j<dir[t2.b];j++){
				b2=g[t2.b][j];
				
				if(conflict(t2.a,t2.b,a2,b2)) continue;
				
				for(int k=0;k<dir[t2.c];k++){
					c2=g[t2.c][k];
					if(conflict(t2.a,t2.c,a2,c2)) continue;
					if(conflict(t2.b,t2.c,b2,c2)) continue;
					if(dist2[a2][b2][c2]!=-1) continue;
					
					n2.a=a2;n2.b=b2;n2.c=c2;
					q2.push(n2);
					
					dist2[a2][b2][c2]=dist2[t2.a][t2.b][t2.c]+1;
					if(dist1[a2][b2][c2]>=0){
						ans=dist2[a2][b2][c2]+dist1[a2][b2][c2];
						return;
					}
				}
			}
		}
	}
}
int main(void){
	while(cin>>w>>h>>n&&w){
		cin.get();
		
		char buffer[maxn][maxn];
		for(int i=0;i<h;i++){
			cin.getline(buffer[i],20);
		}
		
		int x[maxm],y[maxm],id[maxn][maxn];
		int cnt=0;
		
		//找出空白位置 
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				char ch=buffer[i][j];
				if(ch!='#'){
					x[cnt]=i;y[cnt]=j;id[i][j]=cnt;
					if(islower(ch)){
						if(ch=='a') s.a=cnt;
						else if(ch=='b') s.b=cnt;
						else s.c=cnt;
					}
					else if(isupper(ch)){
						if(ch=='A') e.a=cnt;
						else if(ch=='B') e.b=cnt;
						else e.c=cnt;
					}
					cnt++;
				}
			}
		}
		
		//建立空白位置的图
		for(int i=0;i<cnt;i++){
			dir[i]=0;
			for(int j=0;j<5;j++){
				int xx=x[i]+dx[j];
				int yy=y[i]+dy[j];
				
				if(buffer[xx][yy]!='#'){
					g[i][dir[i]++]=id[xx][yy];
				}
			}
		}
		
		if(n<=2){
			dir[cnt]=1;g[cnt][0]=cnt;s.c=e.c=cnt++;
		} 
		if(n<=1){
			dir[cnt]=1;g[cnt][0]=cnt;s.b=e.b=cnt++;
		}
		
		ans=0x7fffffff;
		double_bfs();
		
		printf("%d\n",ans);
	}
}
