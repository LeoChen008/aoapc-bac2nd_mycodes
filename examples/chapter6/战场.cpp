#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=1000+10;
const int bound=1000;

int vis[maxn];
int n;
double inx,iny,outx,outy;
bool flag=true;

struct Point{
	int x,y,r;
	Point(int x=0,int y=0,int r=0):x(x),y(y),r(r){}
}points[maxn];


bool hasinter(Point cur,Point p){
	int dx=cur.x-p.x;
	int dy=cur.x-p.x;
	
	return dx*dx+dy*dy-(cur.r+p.r)*(cur.r+p.r)<0;
} 
bool dfs(int cur){
	vis[cur]=1;
	if(points[cur].y-points[cur].r<=0) return false;
	if(points[cur].x-points[cur].r<=0) iny=min(iny,points[cur].y-sqrt(pow(points[cur].r,2)-pow(points[cur].x,2)));
	if(points[cur].x+points[cur].r>=bound) outy=min(outy,points[cur].y-sqrt(pow(points[cur].r,2)-pow(bound-points[cur].x,2)));
	for(int i=0;i<n;i++){
		if(!vis[i]&&hasinter(points[cur],points[i])){
			if(!dfs(i)) return false;
		}
	}
	
	return true;
} 

int main(void){
	while(scanf("%d",&n)!=EOF){
		memset(vis,0,sizeof(vis));
		flag=true;
		
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&points[i].x,&points[i].y,&points[i].r);
		}
		
		inx=0;iny=1000;
		outx=1000;outy=1000;
		
		for(int i=0;i<n;i++){
			if(!vis[i]&&points[i].y+points[i].r>=bound){
				if(!dfs(i)){
					cout<<"IMPOSSIBLE"<<endl;
					flag=false;
				}
			}
		}
		
		if(flag) printf("%0.2f %0.2f %0.2f %0.2f\n",inx,iny,outx,outy);	
	}
}
