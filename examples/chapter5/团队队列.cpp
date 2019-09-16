#include<iostream>
#include<cstdio> 
#include<string>
#include<queue>
#include<map>
using namespace std;

const int maxn=1000+100;
int main(void){
	int t,kcase=0;
	while(cin>>t&&t){
		printf("Scenario #%d\n",++kcase);
		
		map<int,int> team;
		for(int i=0;i<t;i++){
			int n,m;
			cin>>n;
			while(n--){
				cin>>m;
				team[m]=i;
			}
		}
		
		queue<int> q1,q2[maxn];
		while(1){
			string cmd;
			int num;
			cin>>cmd;
			if(cmd[0]=='S'){
				break;
			}
			else if(cmd[0]=='E'){
				cin>>num;
				int t=team[num];
				if(q2[t].empty()) q1.push(t);
				q2[t].push(num);
			}
			else if(cmd[0]=='D'){
				int t=q1.front();
				printf("%d\n",q2[t].front());
				q2[t].pop();
				if(q2[t].empty()) q1.pop();
			}
		}
		cout<<endl;
	}
} 
