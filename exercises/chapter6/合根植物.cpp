#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1000+10;

int map[maxn*maxn];
int m,n;
int T;
int p,q;
int count;

int find(int p){
	while(p!=map[p])p=map[p];
	return p;
}
bool connected(int p,int q){
	return find(p)==find(q);
}
void connect(int p,int q){
	int proot=find(p);
	int qroot=find(q);
	
	if(proot==qroot) return;
	
	map[proot]=qroot;
	
	count--;
}
int main(void){
	while(cin>>m>>n){
		for(int i=1;i<=m*n;i++){
			map[i]=i;
		}
		
		cin>>T;
		
		count=m*n;
		
		for(int i=0;i<T;i++){
			cin>>p>>q;
			
			if(connected(p,q)){
				continue;
			}
			
			connect(p,q);
		}
		
		printf("%d\n",count);
	}	
}
