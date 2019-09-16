#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;

const int maxe=1000+10;
const int maxn=50+5;

const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};

int X[maxn<<1],Y[maxn<<1],Z[maxn<<1];
int color[maxn<<1][maxn<<1][maxn<<1];
int vis[maxn<<1][maxn<<1][maxn<<1];
int n,v,s;
int nx,ny,nz;
int x0,y0,z0,lenx,leny,lenz;

struct Cell{
	int x,y,z;
	Cell(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
}cells[maxn<<1];


int discrete(int *v){ //排序去重，返回新的数组长度 
	sort(v,v+2*n+1);
	return unique(v,v+2*n+1)-v;
}

int area(int x,int y,int z,int dir){
	if(dx[dir]!=0){
		return (Y[y+1]-Y[y])*(Z[z+1]-Z[z]);
	}
	if(dz[dir]!=0){
		return (X[x+1]-X[x])*(Y[y+1]-Y[y]);
	}
	if(dy[dir]!=0){
		return (X[x+1]-X[x])*(Z[z+1]-Z[z]);
	}
}
void input(){
	memset(color,0,sizeof(color));
	cin>>n;
	for(int i=1;i<=n*2;i+=2){
		cin>>x0>>y0>>z0>>lenx>>leny>>lenz;
		
		cells[i].x=x0;	 cells[i+1].x=x0+lenx;
		cells[i].y=y0;	 cells[i+1].y=y0+leny;
		cells[i].z=z0;	 cells[i+1].z=z0+lenz;
		
		X[i]=cells[i].x; X[i+1]=cells[i+1].x;
		Y[i]=cells[i].y; Y[i+1]=cells[i+1].y;
		Z[i]=cells[i].z; Z[i+1]=cells[i+1].z;
	}
	
	X[0]=0;Y[0]=0;Z[0]=0;
	
	nx=discrete(X);ny=discrete(Y);nz=discrete(Z); //对三维坐标轴进行离散化
	
	X[nx]=maxe;Y[ny]=maxe;Z[nz]=maxe;
	
	for(int i=1;i<=2*n;i+=2){
		int x1,y1,z1,x2,y2,z2;
		
		x1=lower_bound(X,X+nx,cells[i].x)-X;
		x2=lower_bound(X,X+nx,cells[i+1].x)-X;
		y1=lower_bound(Y,Y+ny,cells[i].y)-Y;
		y2=lower_bound(Y,Y+ny,cells[i+1].y)-Y;
		z1=lower_bound(Z,Z+nz,cells[i].z)-Z;
		z2=lower_bound(Z,Z+nz,cells[i+1].z)-Z;
		
		for(int r=x1;r<x2;r++)
			for(int c=y1;c<y2;c++)
				for(int m=z1;m<z2;m++){
					color[r][c][m]=1;
				}
	}	 
}

void solve(){
	memset(vis,0,sizeof(vis));
	v=0;
	s=0;
	queue<Cell> q;
	q.push(Cell(0,0,0));
	vis[0][0][0]=1;
	
	while(!q.empty()){
		Cell now=q.front();q.pop();
		
		if(color[now.x][now.y][now.z]==0){
			v+=(X[now.x+1]-X[now.x])*(Y[now.y+1]-Y[now.y])*(Z[now.z+1]-Z[now.z]);
		}
		for(int i=0;i<6;i++){
			int xx=now.x+dx[i];
			int yy=now.y+dy[i];
			int zz=now.z+dz[i];
			
			if(xx<0||xx>=nx||yy<0||yy>=ny||zz<0||zz>=nz){
				continue; 
			}
			
			if(!color[xx][yy][zz]&&!vis[xx][yy][zz]){
				q.push(Cell(xx,yy,zz));
				vis[xx][yy][zz]=1;
			}else if(color[xx][yy][zz]){
				s+=area(xx,yy,zz,i);
			}
			
		}
		
	}
	v=maxe*maxe*maxe-v;	
}
	
int main(void){
	int T;
	cin>>T;
	while(T--){
		input();
		solve();
		printf("%d %d\n",s,v);
	}
} 
