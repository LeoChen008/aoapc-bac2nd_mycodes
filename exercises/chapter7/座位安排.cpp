#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

#define DEBUG
const int maxn=20+10;

int theater[maxn][maxn];
char ans[maxn][maxn];
int n,k;

inline int check_num(int x,int y,int edge_r,int edge_c){
	int res=100;
	int cnt=0;
	for(int i=x;i<x+edge_r;i++){
		for(int j=y;j<y+edge_c;j++){
			if(theater[i][j]!=0){
				res=theater[i][j];
				cnt++;
			}
			if(cnt>=2) return -1;
		}
	}
	return res;
}
inline void paint_ans(int x,int y,int edge_r,int edge_c,char ch){
	for(int i=x;i<x+edge_r;i++){
		for(int j=y;j<y+edge_c;j++){
			ans[i][j]=ch;
		}
	}
}
bool dfs(int id,int cur){
	
	while(ans[id/n][id%n]!='#') id++;

	if(id>=n*n) return true;
		
	int x=id/n;
	int y=id%n;
	
	int endy,area,num;
	endy=n;
	for(int i=x;i<n;i++){
		for(int j=y;j<endy;j++){
			if(ans[i][j]!='#'){
				endy=j;break;
			}
			area=(i-x+1)*(j-y+1);
			if(area>9){
				endy=j;break;
			}
			num=check_num(x,y,i-x+1,j-y+1);
			if(num==-1){
				endy=j;break;
			}
		
			if(num<area){
				endy=j;break;
			}
			if(num>area) continue;
			
			paint_ans(x,y,i-x+1,j-y+1,cur+'A');
			
			/*for(int p=0;p<n;p++){
			for(int q=0;q<n;q++){
				printf("%c",ans[p][q]);
			}
			printf("\n");
		}
			printf("\n");*/
			if(dfs(id+j-y+1,cur+1)) return true;
			paint_ans(x,y,i-x+1,j-y+1,'#');
		}
	}
	return false;
}   
int main(void){
	#ifdef _DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif 
	string buffer;
	while(cin>>n>>k&&n){
		for(int i=0;i<n;i++){
			cin>>buffer;
			for(int j=0;j<n;j++){
				if(buffer[j]=='.')theater[i][j]=0;
				else theater[i][j]=buffer[j]-'0';
				ans[i][j]='#';
			}
		}
		dfs(0,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c",ans[i][j]);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout); 
} 
