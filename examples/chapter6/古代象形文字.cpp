#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int maxh=200+10;
const int maxw=50+5;
const char *note="WAKJSD"; 

vector< set<int> > neighbor;
char bin[16][4]={{'0','0','0','0'},{'0','0','0','1'},{'0','0','1','0'},{'0','0','1','1'},{'0','1','0','0'},{'0','1','0','1'},{'0','1','1','0'},{'0','1','1','1'},
                 {'1','0','0','0'},{'1','0','0','1'},{'1','0','1','0'},{'1','0','1','1'},{'1','1','0','0'},{'1','1','0','1'},{'1','1','1','0'},{'1','1','1','1'}};
char img[maxh][maxw]; //store the hex image
int img_bin[maxh][maxw<<2]; //store the binary image 
int color[maxh][maxw<<2];//note the diffierence of area 
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
int H,W;

void decode(int r,int c,const char ch){
	//translate the hex to binary and store it in the img_bin
	if(ch<='9'&&ch>='0'){
		for(int i=0;i<4;i++)img_bin[r][c+i]=bin[ch-'0'][i]-'0';
	}
	else{
		for(int i=0;i<4;i++)img_bin[r][c+i]=bin[ch-'a'+10][i]-'0';
	}
}
void dfs(int r,int c,int id){
	//to search the area without marked 
	color[r][c]=id;
	int xx,yy;
	for(int i=0;i<4;i++){
		xx=r+x[i];
		yy=c+y[i];
		if(xx>=0&&xx<H&&yy>=0&&yy<W&&img_bin[r][c]==img_bin[xx][yy]&&color[xx][yy]==0) dfs(xx,yy,id);
	}
}
void find_blank(int r,int c){
	//check whether there are blank areas
	int xx,yy;
	for(int i=0;i<4;i++){
		xx=r+x[i];
		yy=c+y[i];
		if(xx>=0&&yy>=0&&xx<H&&yy<W&&color[xx][yy]!=1&&img_bin[xx][yy]==0){
			neighbor[color[r][c]].insert(color[xx][yy]);
		}
	} 
	
}
int main(void){
	int kcase=0;
	while(cin>>H>>W&&H!=0){
		
		memset(img_bin,0,sizeof(img_bin));
		
		for(int i=0;i<H;i++){
			scanf("%s",img[i]);
			for(int j=0;j<W;j++){
				decode(i+1,j*4+1,img[i][j]);
			}
		}
		
		H+=2;
		W=W*4+2;
		
		int id=0;
		vector<int> black;
		memset(color,0,sizeof(color));
		
		for(int i=0;i<H;i++)
		    for(int j=0;j<W;j++){
		    	if(!color[i][j]){
		    		dfs(i,j,++id);
		    		if(img_bin[i][j]==1) black.push_back(id);
				}
			}
		
		neighbor.clear();
		neighbor.resize(id+1);
		
		for(int i=0;i<H;i++)
		    for(int j=0;j<W;j++){
		    	if(img_bin[i][j]==1){
		    		find_blank(i,j);
				}
			}
			
		vector<char> ans; 
		for(int i=0;i<black.size();i++){
			ans.push_back(note[neighbor[black[i]].size()]);
		}
		sort(ans.begin(),ans.end()); 
		
		printf("Case %d: ",++kcase);
		for(int i=0;i<ans.size();i++){
			printf("%c",ans[i]);
		}
		cout<<endl; 
	} 
} 
