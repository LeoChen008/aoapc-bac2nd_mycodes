#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>

using namespace std;

set< pair<int,int> > s;
int n;

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		s.clear();

		cin>>n;
		
		int sum=0;
		
		for(int i=1;i<=n;i++){
			int x;
			int y;
			cin>>x;
			cin>>y;
			sum+=x;
			pair<int,int> p(x*n,y);
			s.insert(p);
		}
		
		
		bool flag=true;
		
		set< pair<int,int> >::iterator iter;
		for(iter=s.begin();iter!=s.end();iter++){
			pair<int,int> p1=*iter;
			pair<int,int> p2(2*sum-p1.first,p1.second);
			
			if(!s.count(p2)){
				flag=false;
				break;
			}
		}
		
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
