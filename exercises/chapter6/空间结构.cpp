#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


const int maxn=64+5;

int n;

char image[maxn][maxn];
int kcase=0;
vector<int> ans;
vector<int> path;

bool iswhite(int r,int c,int len){
	for(int i=r;i<len+r;i++){
		for(int j=c;j<len+c;j++){
			if(image[i][j]=='1'){
				return false;
			}
		}
	}
	
	return true;
} 

bool isblack(int r,int c,int len){
	for(int i=r;i<len+r;i++){
		for(int j=c;j<len+c;j++){
			if(image[i][j]=='0'){
				return false;
			}
		}
	}
	
	return true;
}

void drawblack(int r,int c,int len){
	for(int i=r;i<len+r;i++){
		for(int j=c;j<len+c;j++){
			image[i][j]='*';
		}
	}
}

int convert2ten(string str){
	int len=str.length();
	
	int res=0;
	
	for(int i=0;i<len;i++){
		res+=(str[len-1-i]-'0')*pow(5,i);
	}
	
	return res;
}

vector<int> convert2five(int t){
	vector<int> path;
	
	while(t){
		path.push_back(t%5);
		t/=5;
	}
	
	return path;
}


void dfs(string path,int r,int c,int len){
	
	if(iswhite(r,c,len)) return;
	if(isblack(r,c,len)){
		ans.push_back(convert2ten(path));
		return;
	}
	
	if(len/2>0){
		dfs("1"+path,r,c,len/2); 
		dfs("2"+path,r,c+len/2,len/2); 
		dfs("3"+path,r+len/2,c,len/2); 
		dfs("4"+path,r+len/2,c+len/2,len/2);
	}
}


void getinput(bool ismatrix){
	if(ismatrix){
		for(int i=0;i<n;i++){
			scanf("%s",image[i]);
		}
	}
	else{
		int num;
		while(cin>>num&&num!=-1){
			path.push_back(num);
		}
	}
}


int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n&&n){
		if(kcase) printf("\n");
		memset(image,0,sizeof(image));
		
		if(n>0){
			getinput(true);
			
			ans.clear();
			
			if(iswhite(0,0,n)){
				//do nothing
			}
			else if(isblack(0,0,n)){
				ans.push_back(0);
			}
			else{
				string root="";
				dfs("1"+root,0,0,n/2);
				dfs("2"+root,0,n/2,n/2);
				dfs("3"+root,n/2,0,n/2);
				dfs("4"+root,n/2,n/2,n/2);
			}
			printf("Image %d\n",++kcase);
			
			if(ans.size()){
				sort(ans.begin(),ans.end());
				
				for(int i=0;i<ans.size();i++){
					if((i+1)%12==0||i==ans.size()-1)printf("%d\n",ans[i]);
					else{
						printf("%d ",ans[i]);
					}
				}
			}
			
			printf("Total number of black nodes = %d\n",ans.size());
		}
		else{
			n=-n;
						
			path.clear();
			
			getinput(false);
			
			vector<int> p;
			
			for(int i=0;i<path.size();i++){
				int number=path[i];
				
				p=convert2five(number);
				
				int r=0;
				int c=0;
				int len=n;
				
				for(int j=0;j<p.size();j++){
					switch(p[j]){
						case 1: r=r;c=c;len=len/2;break;
						case 2: r=r;c=c+len/2;len=len/2;break;
						case 3: r=r+len/2;c=c;len=len/2;break;
						case 4: r=r+len/2;c=c+len/2;len=len/2;break;
					}
				}
				
				drawblack(r,c,len);
			}
			
			
			printf("Image %d\n",++kcase);
			
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(!image[i][j]){
						printf(".");
					}
					else{
						printf("%c",image[i][j]);
					}
				}
				printf("\n");
			}
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
