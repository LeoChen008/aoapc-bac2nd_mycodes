/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;

const int maxn = 200000+5;

int n;
int seq[maxn];
int G[maxn],F[maxn];/* G[] for the last index of longest ordered seqs
					*  F[] for the first index of longest ordered seqs 
                    */                    
struct Tuple{
	int a,g; // a for seq[], g for G[] 
	Tuple(int a, int g): a(a),g(g) {}
	bool operator<(const Tuple& rhs) const{
		return this->a < rhs.a;
	}
};
set<Tuple> s; 

int main(void){
	int Z;
	int ans;
	cin>>Z;
	while(Z--){
		cin>>n;
		for(int i=0;i<n;++i) cin>>seq[i];
		
		G[0]=1;
		for(int i=1;i<n;++i){
			if(seq[i]>seq[i-1]) G[i]=G[i-1]+1;
			else  G[i]=1;
		}
		
		F[n-1]=1;
		for(int i=n-2;i>=0;--i){
			if(seq[i]<seq[i+1]) F[i]=F[i+1]+1;
			else F[i]=1;
		}
		
		ans=1;
		s.clear();
		s.insert(Tuple(seq[0],G[0]));
		
		for(int i=1;i<n;++i){
			Tuple t(seq[i],G[i]);
			auto iter=s.lower_bound(t);
			
			bool flag=true;
			if(iter!=s.begin()){
				Tuple temp=*(--iter);
				ans=max(ans,temp.g+F[i]);
				if(temp.g >= t.g) flag=false;
			}
			
			if(flag){
				s.erase(t);
				s.insert(t);
				iter=s.find(t);
				iter++;
				while(iter != s.end()&&iter->a > t.a&&iter->g <= t.g) s.erase(iter++); 
			}
		}
		
		printf("%d\n",ans);
	} 
	return 0;
}
