#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>

using namespace std;

set< vector<int> > vis;
int n;


bool allzeros(vector<int> cur){
	
	for(int i=0;i<n;i++){
		if(cur[i]) return false;
	}
	
	return true;
}

bool dfs(vector<int> cur){
	if(allzeros(cur)) return true;
	if(vis.count(cur)) return false;
	
	vis.insert(cur);
	
	vector<int> next;
	
	for(int i=0;i<n;i++){
		int temp=abs(cur[i]-cur[(i+1)%n]);
		next.push_back(temp);
	}
	
	if(dfs(next)){
		return true;
	}
	
	return false;
}

int main(void){
	int T;
	cin>>T;
	while(T--){
		vis.clear();
		cin>>n;
		vector<int> start;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			start.push_back(temp);
		}		
		
		if(dfs(start)){
			printf("ZERO\n");
		}else{
			printf("LOOP\n");
		}
	}
} 
