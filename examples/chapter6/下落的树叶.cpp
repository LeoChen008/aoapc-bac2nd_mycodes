#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1<<10;

int sum[maxn];


void build(int root){
	int n;
	cin>>n;
	if(n==-1) return;
	sum[root]+=n;
	build(root-1);
	build(root+1);
}
int main(void){
	int kcase=0;
	int v,pos;
	pos=maxn/2;
	while(cin>>v&&v!=-1){
		memset(sum,0,sizeof(sum));
		sum[pos]=v;
		build(pos-1);
		build(pos+1);
		
		int p=0;
		while(!sum[p]) p++;
		cout<<"Case "<<++kcase<<":\n"<<sum[p];
		
		for(int i=p+1;i<maxn;i++){
			if(sum[i]!=0) cout<<" "<<sum[i];
		}
		cout<<endl<<endl;
		
	}
} 
