#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;


vector< pair<int,int> >res;

int main(void){
	
	int k;
	int x;
	
	while(cin>>k){
		
		res.clear();
		
		for(int y=k+1;y<=2*k;y++){
			x=(k*y)%(y-k)==0?(k*y/(y-k)):0;
			
			if(x>=y){
				res.push_back(make_pair(x,y));
			} 
		}
		
		printf("%d\n",res.size());
		for(int i=0;i<res.size();i++){
			printf("1/%d = 1/%d + 1/%d\n",k,res[i].first,res[i].second);
		}
	} 
} 
