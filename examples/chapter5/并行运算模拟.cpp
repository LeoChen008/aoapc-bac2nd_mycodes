#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<deque>
#include<queue>
using namespace std;

const int maxn=1000+50;

vector<string> prg[maxn];
deque<int> pe; //执行队列 
queue<int> pw; //等待队列
int p[maxn];
int var[26];
int tc[5];
int lim;
bool if_lock=false;

void execute(int id){
	int t=lim;
	string cur_stat;
	while(t>0){
		cur_stat=prg[id][p[id]];
		if(cur_stat[2]=='='){
			t-=tc[0];
			int v=cur_stat[4]-'0';
			if(cur_stat.size()>=6){
				v=v*10+cur_stat[5]-'0';
			}
			var[cur_stat[0]-'a']=v;
		}
		else if(cur_stat[2]=='i'){
			t-=tc[1];
			printf("%d: %d\n",id,var[cur_stat[6]-'a']);
		}
		else if(cur_stat[2]=='c'){
			t-=tc[2];
			if(if_lock){
				pw.push(id);
				return;
			}
			if_lock=true;
		}
		else if(cur_stat[2]=='l'){
			t-=tc[3];
			if_lock=false;
			if(!pw.empty()){
					int v=pw.front();
			pw.pop();
			pe.push_front(v);
			}
		}
		else{
			return;
		}
		p[id]++;
	}
	pe.push_back(id);
}
int main(void){
	int cases,n;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(int i=0;i<5;i++){
			scanf("%d",&tc[i]);
		}
		scanf("%d",&lim);
		
		string s;
		for(int i=1;i<=n;i++){
			prg[i].clear();
			while(getline(cin,s)){
				if(s=="") continue;
				prg[i].push_back(s);
				if(prg[i].back()=="end") break;
			}
			pe.push_back(i);
		}
		
		memset(p,0,sizeof(p));
		memset(var,0,sizeof(var));
		
		while(!pe.empty()){
			int cur_id=pe.front();
			pe.pop_front();
			execute(cur_id);
		}
		if(cases){
			printf("\n");
		} 
	}
} 
