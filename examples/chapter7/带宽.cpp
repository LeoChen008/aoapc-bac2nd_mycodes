#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;

const int maxn=26+5;
const int maxm=8+5;


string buffer;
int g[maxn][maxn];
int vis[maxn];
int temp[maxm];
int res[maxm];
int minbd;
int n;
set<int> s;


void construct_graph() {
	int start,end;
	start=end=0;

	for(int i=0; i<buffer.length(); i++) {

		if(buffer[i]==':') {
			start=i;
		} else if(buffer[i]==';') {
			end=i;
		}

		if(start<end) {
			s.insert(buffer[start-1]-'A');
			for(int j=start+1; j<end; j++) {
				g[buffer[start-1]-'A'][buffer[j]-'A']=1;
				g[buffer[j]-'A'][buffer[start-1]-'A']=1;
				s.insert(buffer[j]-'A');
			}
		}
	}

	if(start>end) {
		s.insert(buffer[start-1]-'A');
		for(int j=start+1; j<buffer.length(); j++) {
			g[buffer[start-1]-'A'][buffer[j]-'A']=1;
			g[buffer[j]-'A'][buffer[start-1]-'A']=1;
			s.insert(buffer[j]-'A');
		}
	}
}

void dfs(int cur) {
	if(cur==n) {
		int u,v,maxbd;
		maxbd=-1;
		for(int i=0; i<cur; i++) {
			u=temp[i];
			for(int j=i+1; j<cur; j++) {
				v=temp[j];
				if(g[u][v]) {
					maxbd=max(j-i,maxbd);
				}
			}
		}
		
		/*for(int i=0;i<cur;i++){
			printf("%c",temp[i]+'A');
		} 
		printf("\n");*/
		if(minbd>maxbd) {
			minbd=maxbd;
			for(int i=0; i<cur; i++)res[i]=temp[i];
		}

		return;
	}

	int u,v,maxbd;
	maxbd=-1;
	for(int i=0; i<cur; i++) {
		u=temp[i];
		for(int j=i+1; j<cur; j++) {
			v=temp[j];
			if(g[u][v]) {
				maxbd=max(j-i,maxbd);
				if(maxbd>minbd) return;
			}
		}
	}
	
	for(set<int>::iterator it=s.begin(); it!=s.end(); it++) {
		if(!vis[*it]) {
			vis[*it]=1;
			temp[cur]=*it;
			dfs(cur+1);
			vis[*it]=0;
		}
	}


}

void init() {
	memset(g,0,sizeof(g));
	memset(res,0,sizeof(res));
	memset(temp,0,sizeof(temp));
	memset(vis,0,sizeof(vis));
	minbd=0x7fffffff;
	s.clear();
}

int main(void) {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>buffer&&buffer!="#") {
		init();
		construct_graph();
		n=s.size();
		dfs(0);
		for(int i=0; i<n; i++) {
			printf("%c ",res[i]+'A');
		}
		printf("-> %d\n",minbd);

	}
	
	//fclose(stdin);
	//fclose(stdout);
}
