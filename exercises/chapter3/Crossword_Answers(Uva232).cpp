#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15
char map[maxn][maxn];
int number[maxn][maxn];
bool eligible[maxn][maxn];
using  namespace std;
int main(){
	int r,c;
	int kcase=0;
	while(scanf("%d",&r)&&r!=0){
		int count=1;
		scanf("%d",&c);
		getchar();
		memset(number,0,sizeof(number));
		memset(eligible,false,sizeof(eligible));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]!='*'){
					eligible[i][j]=true;
					if((j-1<0||map[i][j-1]=='*')||(i-1<0||map[i-1][j]=='*')){
						number[i][j]=count++;
					}
				}
			}
			getchar();
		}
		if(kcase++)printf("\n");
		printf("puzzle #%d:\n",kcase);
		printf("Across\n");
		bool eli[maxn][maxn];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
			{
				eli[i][j]=eligible[i][j];
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(number[i][j]!=0){
					int end=j;
					if(eli[i][j]) printf("%3d.",number[i][j]);
					bool flag=eli[i][j];
					while(map[i][end]!='*'&&end<c&&eli[i][end]){
						eli[i][end]=false;
						printf("%c",map[i][end++]);
					}
					if(flag)printf("\n");
				}
			}
		}
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
			{
				eli[i][j]=eligible[i][j];
			}
		}
		printf("Down\n");
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(number[i][j]!=0){
					int end=i;
					if(eli[i][j])printf("%3d.",number[i][j]);
					bool flag=eli[i][j];
					while(map[end][j]!='*'&&end<r&&eli[end][j]){
						eli[end][j]=false;
						printf("%c",map[end++][j]);
					}
					if(flag)printf("\n");
				}
			}
		}
		
		
	}
}
