#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

const int maxm=20+5;
const int maxn=10+5;

int m,n;
int vis[maxm][maxn];
int iscircle[maxm][maxn];

struct Cell{
	int value;
	string s;
	bool isnum;
	Cell(int val=0,string s="",bool isnum=false):value(val),s(s),isnum(isnum){}
}cells[maxm][maxn];


bool dfs(int r,int c){
	
	if(iscircle[r][c]==1) return false;
	
	if(vis[r][c]==1) return true;
	if(vis[r][c]==-1){
		iscircle[r][c]=1;
		return false;
	}
	
	vis[r][c]=-1;
	
	string temp=cells[r][c].s;
	bool f=cells[r][c].isnum;
	int len=temp.length();
	
	int sum=0;
	int sign=1;
	
	for(int i=0;i<len;){
		if(temp[i]>='0'&&temp[i]<='9'){
			int number=0;
			string s(&temp[i],&temp[len]);
			stringstream ss;
			ss<<s;
			ss>>number;
			
			sum+=sign*number;
			while(i<len&&temp[i]>='0'&&temp[i]<='9'){
				i++;
			}
		}
		else if(temp[i]=='+'||temp[i]=='-'){
			if(temp[i]=='+'){
				sign=1;
			}
			else{
				sign=-1;
			}
			
			i++;
		}
		else {
			int row=temp[i]-'A';
			int column=temp[i+1]-'0';
			
			if(dfs(row,column)){
				sum+=sign*cells[row][column].value;
			}
			else{
				iscircle[r][c]=1;
				vis[r][c]=1;
				return false;
			}
			
			i+=2;
		}
	}
	cells[r][c].isnum=true;
	cells[r][c].value=sum;
	vis[r][c]=1;
	return true;
}
void print_sheet(){
	
	printf(" ");
	for(int i=0;i<n;i++){
		printf("%6d",i);
	}
	printf("\n");
	 
	for(int i=0;i<m;i++){
		for(int j=-1;j<n;j++){
			if(j==-1){
				printf("%c",'A'+i);
			}
			else{
				printf("%6d",cells[i][j].value);
			}
		}
		printf("\n");
	}
}


void print_circle(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(iscircle[i][j]){
				printf("%c%d: ",i+'A',j);
				cout<<cells[i][j].s<<endl;
			}
		}
	}
}


int main(void){
	while(cin>>m>>n&&m){
			
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>cells[i][j].s;
				cells[i][j].isnum=false;
			}
		}
		memset(vis,0,sizeof(vis));
		memset(iscircle,0,sizeof(iscircle));
		
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(cells[i][j].isnum){
					continue;
				}
				dfs(i,j);
			} 
		}
		
		bool flag=true;
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(iscircle[i][j]){
					flag=false;
					break;
				}
			}
		}
		
		if(flag){
			print_sheet();
		}
		else{
			print_circle();
		}
		printf("\n");
	}
} 
