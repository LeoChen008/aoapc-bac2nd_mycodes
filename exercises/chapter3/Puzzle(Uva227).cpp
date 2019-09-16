#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 10
#define max 10000
char map[maxn][maxn];
char s[max];
using namespace std;
int main(){
	int kcase=0;
	 while(map[0][0]=getchar()){
	      if(map[0][0]=='Z') break;
	      int blk_r=0;
	      int blk_c=0;
	      for(int i=0;i<5;i++){
	      	for(int j=0;j<5;j++){
	      		if(i||j)
	      		   map[i][j]=getchar();
	      		if(map[i][j]==' ')
	      		{
	      		   blk_r=i;
	      		   blk_c=j;
	      			
				}
			  }
			  getchar();
		  }
	      int count=0;
	      while(~scanf("%c",&s[count])){
	      	if(s[count]!='0')count++;
	      	else break;
		  }
		  getchar();
		  int len=strlen(s);
		  int r=blk_r;
		  int c=blk_c;
		  bool flag=true;
		  for(int i=0;s[i]!='0';i++){
		  	switch(s[i]){
		  		case 'A':r=blk_r-1;c=blk_c;break;
		  		case 'B':r=blk_r+1;c=blk_c;break;
		  		case 'L':r=blk_r;c=blk_c-1;break;
		  		case 'R':r=blk_r;c=blk_c+1;break;
		  		default:continue;
			  }
			if(r<0||r>4||c<0||c>4){
				flag=false;
				break;
			}
			else{
				map[blk_r][blk_c]=map[r][c];
				map[r][c]=' ';
				blk_r=r;
				blk_c=c;
			}
		  }
		  if(kcase++) cout<<endl;
		  printf("Puzzle #%d:\n",kcase);
		  
		  if(!flag) {
		    printf("This puzzle has no final configuration.\n");
		  }
		  else{
		  	for(int i=0;i<5;i++){
		  		for(int j=0;j<4;j++){
		  			printf("%c ",map[i][j]);
				  }
				  printf("%c\n",map[i][4]);
			  }
		  }    
	}
	
} 
