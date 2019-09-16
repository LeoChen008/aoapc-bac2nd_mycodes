#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

const int maxn=52;

int g[maxn][maxn];
int vis[maxn];
int n;

int getId(const char a,const char b){
	return a-'A'+(b=='+'?0:26);
}
void connect(const char ch1,const char ch2,const char ch3,const char ch4){
	if(ch1=='0'||ch3=='0'){
		return;
	}
	
	int u=getId(ch1,ch2);
	u=u>=26?u-26:u+26;
	int v=getId(ch3,ch4);
	
	g[u][v]=1;
}
bool toposort(int u){
	vis[u]=-1;
	for(int v=0;v<maxn;v++){
		if(g[u][v]){
			if(vis[v]==-1){
				return true;
			}
			if(!vis[v]&&toposort(v)){
				return true;
			}
		}
	}
	vis[u]=1;
	
	return false;
}

bool has_cycle(){
	for(int i=0;i<maxn;i++){
		if(!vis[i]&&toposort(i)){
			return true;
		}
	}
	return false;
}
int main(void){
	while(cin>>n&&n){
		memset(g,0,sizeof(g));

		while(n--){
			char buffer[10];
			cin>>buffer;
			
			for(int i=0;i<8;i+=2)
				for(int j=0;j<8;j+=2){
					if(i!=j)connect(buffer[i],buffer[i+1],buffer[j],buffer[j+1]);
				}
		}
		
		memset(vis,0,sizeof(vis));
		if(has_cycle()){
			printf("unbounded\n");
		}
		else{
			printf("bounded\n");
		}
	}	
}
