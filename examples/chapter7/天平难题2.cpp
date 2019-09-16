#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=6;
const int maxm=1<<maxn;

struct Tree{
	double L,R;
	Tree():L(0),R(0){}
};

double r;
double w[maxn];
double sum[maxm];
int vis[maxm];
int n;
vector<Tree> trees[maxm];


void dfs(int subset){
	if(vis[subset]) return;
	
	vis[subset]=1;
	
	bool flag=false;
	for(int left=(subset-1)&subset;left;left=(left-1)&subset){
		flag=true;
		
		int right=left^subset;
		
		double d1=sum[right]/sum[subset];
		double d2=sum[left]/sum[subset];
		
		dfs(left);
		dfs(right);
		
		for(int i=0;i<trees[left].size();i++){
			for(int j=0;j<trees[right].size();j++){
				Tree t;
				t.L=max(trees[left][i].L+d1,trees[right][j].L-d2);
				t.R=max(trees[right][j].R+d2,trees[left][i].R-d1);
				if(t.L+t.R<r) trees[subset].push_back(t);
			}
		}
	}
	
	if(!flag)trees[subset].push_back(Tree()); 

}
int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>r>>n;
		
		for(int i=0;i<n;i++) cin>>w[i];
		
		for(int i=0;i<(1<<n);i++){
			sum[i]=0;
			trees[i].clear();
			for(int j=0;j<n;j++){
				if(i&(1<<j)) sum[i]+=w[j];
			}
		}
		
		int root=(1<<n)-1;
		memset(vis,0,sizeof(vis));
		
		dfs(root);
		
		double ans=-1;
		
		for(int i=0;i<trees[root].size();i++){
			ans=max(ans,trees[root][i].L+trees[root][i].R);
		}
		printf("%.10lf\n",ans);
	}
}

