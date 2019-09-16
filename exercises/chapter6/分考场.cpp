#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100+5;

#define INF 0x3f3f3f3f

int g[maxn][maxn];
int room[maxn][maxn];
int stunum[maxn];
int res=INF;
int n,m;
int u,v;

void dfs(int stu,int num){
	if(num>=res) return;
	
	if(stu>n){
		res=num;
		return;
	}
	
	for(int i=0;i<num;i++){
		int size=stunum[i];
		
		int c=0;
		for(int j=0;j<size;j++){
			
			if(g[stu][room[i][j]]==0){
				c++;
			}
		}
		
		if(c==size){
			room[i][stunum[i]++]=stu;
			dfs(stu+1,num);
			stunum[i]--;
		}
	}
	
	room[num][stunum[num]++]=stu;
	dfs(stu+1,num+1);
	stunum[num]--;
}
int main(void){
	while(cin>>n){
		memset(g,0,sizeof(g));
		
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
		
		dfs(1,0);
		
		printf("%d\n",res);
	}
}
