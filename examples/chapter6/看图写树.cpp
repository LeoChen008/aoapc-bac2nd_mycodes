#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=200+10;

char buffer[maxn][maxn];
int line=0;

void helper(int r,int c){
	printf("%c(",buffer[r][c]);
	
	if(r+1<line&&buffer[r+1][c]=='|'){
		int col=c;
		
		while(buffer[r+2][col-1]=='-'&&col>=1) col--;
		
		while(buffer[r+2][col]=='-'&&buffer[r+3][col]!='\0'){
			if(buffer[r+3][col]!=' '&&buffer[r+3][col]!='\n')
				helper(r+3,col);
			col++;
		}
	}
	
	printf(")");
}
int main(void){
	int T;
	cin>>T;
	getchar();
	while(T--){
		line=0;
		for(;;){
			fgets(buffer[line],maxn,stdin);
			if(buffer[line][0]=='#') break;
			else line++;
		}
		
		printf("(");
		
		if(line){
			for(int i=0;i<strlen(buffer[0]);i++){
				if(buffer[0][i]!=' '){
					helper(0,i);
					break;
				}
			}
		}
		
		printf(")\n"); 
	}	
} 
