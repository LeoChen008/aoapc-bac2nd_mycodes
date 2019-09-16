#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

const int maxn=16+5;
const int maxm=256+5;

const int dx[]={0,0,1,-1,0};
const int dy[]={1,-1,0,0,0};

int w,h,n;
int start[3],e[3];
int g[maxm][5];
int dir[maxm];
int vis[maxm][maxm][maxm];
char buffer[maxn][maxn];
int ans;

struct Node{
	int a,b,c;
	int dist;
	Node():a(-1),b(-1),c(-1),dist(0){}
};

bool conflict(int a,int b,int a2,int b2){
	return a2==b2||(a==b2&&b==a2);
}

void bfs(){
	
	memset(vis,0,sizeof(vis));
	
	queue<Node> q;
	Node start;
	start.a=s[0];
	start.b=s[1];
	start.c=s[2];
	q.push(s);
	
	vis[s.a][s.b][s.c]=1;
	while(!q.empty()){
		Node temp=q.front();q.pop();
		
		if(temp.a==e[0]&&temp.b==e[1]&&temp.c==e[2]){
			ans=temp.dist;
			break;
		}
		
		Node next;
		for(int i=0;i<dir[temp.a];i++){
			
			int a2=g[temp.a][i];
			
			for(int j=0;j<dir[temp.b];j++){
				
				int b2=g[temp.b][j];
				if(conflict(temp.a,temp.b,a2,b2)) continue;
				
				for(int k=0;k<dir[temp.c];k++){
					
					int c2=g[temp.c][k];
					if(conflict(temp.a,temp.c,a2,c2)) continue;
					if(conflict(temp.b,temp.c,b2,c2)) continue;
					if(vis[a2][b2][c2]) continue;
					next.a=a2;
					next.b=b2;
					next.c=c2;
					next.dist=temp.dist+1;
					
					q.push(next);
					
					vis[a2][b2][c2]=1;
				}
			} 
		}
	}
}

int main(void){
	
	//freopen("in2.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>w>>h>>n&&w){
		getchar();
		int x[maxm],y[maxm],id[maxn][maxn];
		int cnt=0;
		ans=0x7fffffff;
		
		memset(g,0,sizeof(g));
		
		for(int i=0;i<h;i++) {
			cin.getline(buffer[i],20); 
		}
		
		//Ñ°ÕÒ¿Õ°×Î»ÖÃ 
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				char ch=buffer[i][j];
				if(ch!='#'){
					x[cnt]=i;y[cnt]=j;
					id[i][j]=cnt;
					if(isupper(ch)) e[ch-'A']=cnt;
					else if(islower(ch)) s[ch-'a']=cnt;
					cnt++;
				}
			}
		}
		
		//½¨Á¢¿Õ°×Î»ÖÃµÄÍ¼
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
			dir[cnt]=1;g[cnt][0]=cnt;s[2]=e[2]=cnt++;
		}
		if(n<=1){
			dir[cnt]=1;g[cnt][0]=cnt;s[1]=e[1]=cnt++;
		}
		
		bfs();
		
		printf("%d\n",ans); 
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
