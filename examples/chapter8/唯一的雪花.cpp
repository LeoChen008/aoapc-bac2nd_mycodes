/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;

const int maxn = 1000000+5;

int sub[maxn];
set<int> s;
int main(void){
	int T,n,ans;
	int L,R;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i) cin>>sub[i];
		
		s.clear();
		L=0;R=0;ans=0;
		while(R<n){
			while(R<n&&!s.count(sub[R])) s.insert(sub[R++]);
			ans=max(ans,R-L);
			s.erase(sub[L++]);
		}
		
		printf("%d\n",ans);
	}	
	return 0;	
}
