#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=50+5;
const int maxe=1000+10;

const int dx[]={1,-1,0,0,0,0}; 
const int dy[]={0,0,1,-1,0,0}; 
const int dz[]={0,0,0,0,1,-1};

int x0[maxn],y0[maxn],z0[maxn];
int x1[maxn],y1[maxn],z1[maxn];

int X[maxn<<1],Y[maxn<<1],Z[maxn<<1];
int color[maxn<<1][maxn<<1][maxn<<1];
int vis[maxn<<1][maxn<<1][maxn<<1];
int v,s;
int nx,ny,nz;
int N;


int discrete(int *v){
	sort(v,v+2*N+1);
	return unique(v,v+2*N+1)-v;
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

void dfs(int x,int y,int z){
	vis[x][y][z]=1;
	
	if(color[x][y][z]==0){
		v+=(X[x+1]-X[x])*(Y[y+1]-Y[y])*(Z[z+1]-Z[z]);
	}
	
	for(int i=0;i<6;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		int zz=z+dz[i];
		
		if(xx<0||xx>=nx||yy<0||yy>=ny||zz<0||zz>=nz){
			continue;
		}
		
		if(!vis[xx][yy][zz]&&!color[xx][yy][zz]){
			dfs(xx,yy,zz);
		}else if(color[xx][yy][zz]){
			s+=area(xx,yy,zz,i);
		}
	}
}


int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			scanf("%d%d%d%d%d%d",&x0[i],&y0[i],&z0[i],&x1[i],&y1[i],&z1[i]);
			
			x1[i]+=x0[i];y1[i]+=y0[i];z1[i]+=z0[i];
			
			X[i+1]=x0[i];Y[i+1]=y0[i];Z[i+1]=z0[i];
			X[i+N+1]=x1[i];Y[i+N+1]=y1[i];Z[i+N+1]=z1[i];
		}
		X[0]=0;Y[0]=0;Z[0]=0;
		nx=discrete(X);ny=discrete(Y);nz=discrete(Z);
		X[nx]=maxe;Y[ny]=maxe;Z[nz]=maxe;
		
		memset(color,0,sizeof(color));
		int x2,y2,z2,x3,y3,z3;
		
		for(int i=0;i<N;i++){
			x2=lower_bound(X,X+nx,x0[i])-X;
			x3=lower_bound(X,X+nx,x1[i])-X;
			y2=lower_bound(Y,Y+ny,y0[i])-Y;
			y3=lower_bound(Y,Y+ny,y1[i])-Y;
			z2=lower_bound(Z,Z+nz,z0[i])-Z;
			z3=lower_bound(Z,Z+nz,z1[i])-Z;
			
			for(int r=x2;r<x3;r++)
				for(int c=y2;c<y3;c++)
					for(int m=z2;m<z3;m++){
						color[r][c][m]=1;
					}
		}
		
		memset(vis,0,sizeof(vis));
		v=0;s=0;
		dfs(0,0,0);
		printf("%d %d\n",s,maxe*maxe*maxe-v);
	}
}
