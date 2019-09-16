#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10000;
int main(){
	int n,q,m[maxn],x,kcase=0;
	while(scanf("%d%d",&n,&q)==2&&n){
		printf("CASE# %d:\n",++kcase);
		for(int i=0;i<n;i++){
			scanf("%d",&m[i]);
		}
		sort(m,m+n);
		while(q--){
			scanf("%d",&x);
			int index=lower_bound(m,m+n,x)-m;
			if(m[index]==x){
				printf("%d found at %d\n",x,index+1);
			}
			else{
				printf("%d not found\n",x);
			}
		}
	}
}
