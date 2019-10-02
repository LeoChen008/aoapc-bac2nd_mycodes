#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=9+9;

#define FOR(start,len,end) for(int index=start;index<start+len&&index<=end;index++)
int board_h[maxn][maxn];
int board_v[maxn][maxn];
int n,m;

int main(void){
	
	char dir;
	int x,y;
	int kcase=0;
	while(scanf("%d",&n)!=EOF){
		cin>>m;
		memset(board_h,0,sizeof(board_h));
		memset(board_v,0,sizeof(board_v));
		
		for(int i=1;i<=m;i++){
			cin>>dir>>x>>y;
			if(dir=='V'){
				board_v[y][x]=1;
			}
			else board_h[x][y]=1;
		}
		
		if(kcase++) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",kcase);
		
		int size=0,count=0;
		bool flag=false;
		for(int slen=1;slen<=n;slen++){
			count=0;
			
			for(int i=1;i<=n-1;i++){
				for(int j=1;j<=n-1;j++){
					
					size=0;
					if(board_h[i][j]){
						FOR(j,slen,n)size+=board_h[i][index]+board_h[i+slen][index];
						FOR(i,slen,n)size+=board_v[index][j]+board_v[index][j+slen];
					}
					
					if(size==4*slen) count++;
				}
			}
			
			if(count){
				printf("%d square (s) of size %d\n",count,slen);
				flag=true;
			}
		}
		
		if(!flag) printf("No completed squares can be found.\n");
	}
	
} 
