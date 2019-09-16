#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#include<stack>
using namespace std;

const int maxn=1000+5;

int dis[maxn];
int n;
vector<int> parsetree[maxn];
		
int main(void){
	while(cin>>n&&n){
		for(int i=1;i<=n;i++){
			int index;
			cin>>index;
			dis[index]=i;
			parsetree[i].clear();
		}
		
		int root;
		cin>>root;
		
		stack<int> s;
		s.push(root);
		
		for(int i=1;i<=n-1;i++){
			int node;
			cin>>node;
			
			
			while(1){
			    int now=s.top();
				if(now==root||dis[now]+1<dis[node]){
					parsetree[now].push_back(node);
					s.push(node);
					break;
				}else{
					s.pop();
				}
			}
			
		}
		
		for(int i=1;i<=n;i++){
			printf("%d:",i);
			if(!parsetree[i].empty()){
				for(int j=0;j<parsetree[i].size();j++)
					printf(" %d",parsetree[i][j]);
				printf("\n");
			}else{
				printf("\n");
			}
		}
	}
	
}
