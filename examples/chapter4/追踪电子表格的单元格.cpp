#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 100
#define big 1000
using namespace std;
int sheet[maxn][maxn];
int tep[maxn][maxn];
int cols[maxn];
int ans[maxn][maxn];
int r,c,n;
void copy(char type,int q,int p){
	if(type=='R'){
		for(int i=1;i<=c;i++){
			sheet[q][i]=tep[p][i];
		}
	}
	else{
		for(int i=1;i<=r;i++){
			sheet[i][q]=tep[i][p];
		}
	}
}
void del(char type){
	memcpy(tep,sheet,sizeof(sheet));
	int cnt=type=='R'?r:c;
	int cnt2=0;
	for(int i=1;i<=cnt;i++){
		if(!cols[i])copy(type,++cnt2,i);
	}
	if(type=='R') r=cnt2;
	else c=cnt2;
}
void ins(char type){
	memcpy(tep,sheet,sizeof(sheet));
	int cnt=type=='R'?r:c;
	int cnt2=0;
	for(int i=1;i<=cnt;i++){
		if(cols[i])copy(type,++cnt2,0);
		copy(type,++cnt2,i);
	} 
	if(type=='R') r=cnt2;
	else c=cnt2;
}
int main(){
	int r1,r2,c1,c2,m,kcase=0;
	char cmd[10];
	memset(sheet,0,sizeof(sheet));
	while(scanf("%d",&r)==1&&r){
		scanf("%d%d",&c,&n);
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				sheet[i][j]=i*big+j;
			}
		}
		while(n--){
			scanf("%s",cmd);
			if(cmd[0]=='E'){
				scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
				int temp=sheet[r1][c1];
				sheet[r1][c1]=sheet[r2][c2];
				sheet[r2][c2]=temp;
			}
			else{
				int a,x;
				scanf("%d",&a);
				memset(cols,0,sizeof(cols));
				for(int i=0;i<a;i++){
					scanf("%d",&x);
					cols[x]=1;
			    }
				if(cmd[0]=='D') del(cmd[1]);else ins(cmd[1]);
			}
		}
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				ans[sheet[i][j]/big][sheet[i][j]%big]=i*big+j;
			}
		}
		if(kcase>0) printf("\n");
		printf("Spreadsheet #%d\n",++kcase);
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&r1,&c1);
			printf("Cell data in (%d,%d) ",r1,c1);
			if(ans[r1][c1]==0)printf("GONE\n");
			else{
				printf("moved to (%d,%d)\n",ans[r1][c1]/big,ans[r1][c1]%big);
			}
		} 
	}
} 
