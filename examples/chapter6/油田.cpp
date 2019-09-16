#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100+10;
char map[maxn][maxn];
int is_visited[maxn][maxn];
int m,n,sum;

void dfs(int r,int c){
	if(r<0||c<0||r>=m||c>=n){
		return;
	}
	if(is_visited[r][c]!=0||map[r][c]!='@') return;
	
	is_visited[r][c]=sum;
	dfs(r-1,c);
	dfs(r,c-1);
	dfs(r+1,c);
	dfs(r,c+1);
	dfs(r+1,c+1);
	dfs(r-1,c-1);
	dfs(r-1,c+1);
	dfs(r+1,c-1); 
}
int main(void){
	while(cin>>m>>n&&m!=0){
		for(int i=0;i<m;i++){
			scanf("%s",map[i]);
		}
		sum=0;
		memset(is_visited,0,sizeof(is_visited));
		for(int i=0;i<m;i++)
		    for(int j=0;j<n;j++){
		    	if(map[i][j]=='@'&&is_visited[i][j]==0){
		    		++sum;
		    		dfs(i,j);
				}
			}
			
		cout<<sum<<endl;
	}
} 
