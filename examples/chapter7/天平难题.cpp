#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=6+6;

double weights[maxn];
double l[maxn],r[maxn];
double rr;
double ans;
int n;
int id;
int leave[maxn];


void init(){
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(leave,0,sizeof(leave));
	id=0;
	ans=-1;
}

void dfs(int cur){
	if(cur==n){
		return;
	}
	
	double L,R;
	
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			if(i!=j&&leave[i]&&leave[j]){
				L=max(l[i],l[j]-1);
				R=max(r[i]-1,r[j]);
				if(1+L+R<rr){
					if(cur==n-1) ans=max(ans,1+L+R);
					
					leave[i]=leave[j]=0;
					int temp=id++;
					leave[temp]=1;
					weights[temp]=weights[i]+weights[j]; 
					l[temp]=weights[j]/weights[temp]+L;
					r[temp]=weights[i]/weights[temp]+R;
					
					dfs(cur+1);
					
					leave[id--]=0;
					leave[i]=leave[j]=1;
				}
			}
		}
	}
}
int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>rr>>n;
		init();
		for(int i=0;i<n;i++){
			cin>>weights[i];
			leave[id++]=1;
		}
		dfs(1);
		if(ans==-1) printf("%d\n",-1);
		else printf("%.10lf\n",ans);
				
	}
}
