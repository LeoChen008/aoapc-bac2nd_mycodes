#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+5;


int tokens[maxn];
int N,T;
int trans;
int ans;
int kcase=0;

struct Trans{
	int ins,outs;
	int innum[maxn],outnum[maxn];
	int i[maxn],o[maxn]; 
}nt[maxn]; 



bool transfer(){
	bool flag=false;

	for(int i=1;i<=T;i++){
		Trans t=nt[i];
		
		bool f=true;
		for(int j=1;j<=t.ins;j++){
			if(t.innum[t.i[j]]>tokens[t.i[j]]){
				f=false;
				break;
			}
		}
		
		if(!f) continue;
		
		for(int j=1;j<=t.ins;j++){
			tokens[t.i[j]]-=t.innum[t.i[j]];
		}
		
		for(int j=1;j<=t.outs;j++){
			tokens[t.o[j]]+=t.outnum[t.o[j]];
		}
		
		flag=true;
		return flag;
	}	
	
	return flag;
}
void printtokens(){
	for(int i=1;i<=N;i++){
		if(tokens[i]>0){
			printf(" %d (%d)",i,tokens[i]);
		}
	}
}
int main(void){
	while(cin>>N&&N){
		memset(nt,0,sizeof(nt));
		
		for(int i=1;i<=N;i++){
			cin>>tokens[i];
		}
		
		cin>>T;
		
		
		int n;
		
		for(int i=1;i<=T;i++){
			while(cin>>n&&n!=0){
				if(n<0){
					nt[i].innum[-n]++;
				}
				else{
					nt[i].outnum[n]++;
				}
			}
			
			
			for(int j=1;j<=N;j++){
				if(nt[i].innum[j]){
					nt[i].i[++nt[i].ins]=j;
				}
				
				if(nt[i].outnum[j]){
					nt[i].o[++nt[i].outs]=j;
				}
			}
			
		}
		
		
		cin>>trans;
		
		bool flag=true;
		
		for(int i=1;i<=trans;i++){
			if(!transfer()){
				printf("Case %d: dead after %d transitions\n",++kcase,i-1);
				printf("Places with tokens:");
				printtokens();
				printf("\n\n");
				flag=false;
				break;
			}
		}
		
		if(flag){
			printf("Case %d: still live after %d transitions\n",++kcase,trans);
			printf("Places with tokens:");
			printtokens();
			printf("\n\n");
		}
	}
} 
