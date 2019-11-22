/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main(void) {
	int n;
	int temp;
	int ans;
	priority_queue< int,vector<int>,greater<int> > pq;	
	while(cin >> n && n) {
		while(!pq.empty()) pq.pop(); 
		for(int i=0; i<n; ++i) {
			cin>>temp;
			pq.push(temp);
		} 
		
		ans=0;
		while(pq.size() != 1){
			int a = pq.top();pq.pop();
			int b = pq.top();pq.pop();
			
			pq.push(a+b);
			ans += a+b;
		}
		
		printf("%d\n",ans);
	}
	return 0;
} 
