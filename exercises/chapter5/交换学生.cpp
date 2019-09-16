#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int n;
map< pair<int,int>,int> g;

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>n&&n){
		g.clear();		
		for(int i=0;i<n;i++){
			int u,v;
			cin>>u;
			cin>>v;
			pair<int,int> p(u,v);
			pair<int,int> q(v,u);
			
			if(g.find(p)!=g.end()) g[p]++;
			else if(g.find(q)!=g.end()) g[q]--;
			else g[p]=1;
		}
		
		bool flag=true;
		map< pair<int,int>,int >::iterator iter;
		for(iter=g.begin();iter!=g.end();iter++){
			if(iter->second){
				flag=false;
				break;
			}
		}
		
		flag?printf("YES\n"):printf("NO\n");
	}
	//fclose(stdin);
	//fclose(stdout);
}
