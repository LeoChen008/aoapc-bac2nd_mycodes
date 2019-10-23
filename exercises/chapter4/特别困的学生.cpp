/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=10+5;

struct Student{
	int A,B,current;
}studs[maxn];
int n;
int states[maxn];

int solve(){
	int time=1;
	int i,a,b;
	int ttemp;
	bool flag=false;
	int sleep_num=0;
	for(time=1;;time++){
		//count sleepers
		sleep_num=0;
		for(i=0;i<n;++i) if(studs[i].current>studs[i].A) sleep_num++;
		if(sleep_num==0) break;
		
		
		for(i=0;i<n;++i){
			a=studs[i].A; b=studs[i].B; ttemp=studs[i].current;
			if(ttemp==a+b || (ttemp==a && sleep_num<=n-sleep_num)){
				studs[i].current=0;
			}
			studs[i].current++; 
		}		
		
		//check circle
		flag=false;
		for(i=0;i<n;++i) if(states[i]!=studs[i].current) flag=true;
		if(!flag)return -1;
	}
	
	return time;
}
int main(void){
	int kcase=0;
	int a,b,c;
	while(cin>>n&&n){
		for(int i=0;i<n;++i){
			cin>>a>>b>>c;
			studs[i].A=a;
			studs[i].B=b;
			studs[i].current=c;
			states[i]=c;
		}
		printf("Case %d: %d\n",++kcase,solve());
	}
} 
