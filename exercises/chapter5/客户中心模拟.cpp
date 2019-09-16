#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>

using namespace std;


const int maxn=20+5;
const int maxm=5+5;


int kcase=0;
int n,m;
int res;
int pools[maxn];
map<int,int> mark;

struct Topic{
	int id;
	int num;
	int t0;
	int t;
	int dt;
	int last;
}topics[maxn];

struct Personnel{
	int id;
	int num;
	int earlyt;
	int workid;
	int priority[maxn];
	bool iswork;
	
	
	bool operator<(const Personnel &person) const{
		if(this->earlyt==person.earlyt){
			return this->id<person.id;
		}
		return this->earlyt<person.earlyt;
	}
}personnels[maxm];


void init(){
	memset(topics,0,sizeof(topics));
	memset(personnels,0,sizeof(personnels));
	memset(pools,0,sizeof(pools));
	mark.clear();
	res=0;
} 


bool solve(){
	
	bool flag=true;
	
	for(int i=0;i<n;i++){
		if(topics[i].num>0){
			if(topics[i].t0==res){
				pools[i]++;
				topics[i].num--;
				topics[i].t0=-1;
				topics[i].last=res;
			}
			else if(res-topics[i].last==topics[i].dt&&topics[i].t0==-1){
				pools[i]++;
				topics[i].num--;
				topics[i].last=res;
			}
		}
	}
	
	sort(personnels,personnels+m);
	
	int id;
	
	for(int i=0;i<m;i++){
		if(personnels[i].iswork){
			id=mark[personnels[i].workid];
			if(res-personnels[i].earlyt==topics[id].t){
				personnels[i].iswork=false;
				personnels[i].workid=-1;
			}
		}
	}
	
	int index;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!personnels[j].iswork&&i<personnels[j].num){
				index=mark[personnels[j].priority[i]];
				if(pools[index]>0){
					pools[index]--;
					personnels[j].iswork=true;
					personnels[j].earlyt=res;
					personnels[j].workid=topics[index].id;
				}
			}
		}
	}
	
	
	for(int i=0;i<m;i++){
		if(personnels[i].iswork){
			flag=false;
			break;
		}
	}
	
	for(int i=0;i<n;i++){
		if(topics[i].num>0){
			flag=false;
		    break;
		}
	}
	
	return flag;
}


int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>n&&n!=0){
		
		init();
		
		for(int i=0;i<n;i++){
			cin>>topics[i].id;
			cin>>topics[i].num;
			cin>>topics[i].t0;
			cin>>topics[i].t;
			cin>>topics[i].dt;
			mark[topics[i].id]=i;
			topics[i].last=-1;
		}
		
		cin>>m;
		
		for(int i=0;i<m;i++){
			cin>>personnels[i].id;
			cin>>personnels[i].num;
			for(int j=0;j<personnels[i].num;j++){
				cin>>personnels[i].priority[j];
			}
			
			personnels[i].earlyt=-1;
			personnels[i].workid=-1;
			personnels[i].iswork=false;
		}
		
		while(!solve()){
			res++;
		}
		
		printf("Scenario %d: All requests are serviced within %d minutes.\n",++kcase,res);
		
	}
	
	//fclose(stdin);
	//fclose(stdout);
	 
	
}
